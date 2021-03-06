//
// Created by Nikita TEREKHOV on 06/03/2021.
//
#include "../../include/service/AI.h"
#include "limits.h"

using namespace std;

AI* AI::ai_ = nullptr;

AI * AI::GetInstance() {
    if (AI::ai_ == nullptr) {
        AI::ai_ = new AI;
    }
    return AI::ai_;
}

AI::AI() : aiMode(RANDOM) {}

Move AI::DoMove(Chessboard& chessboard) {

    // aiMode can be changed here
    aiMode = MINIMAX;
    Move move;
    if (aiMode == RANDOM) move = RandomMove(chessboard);
    else if (aiMode == MINIMAX) {
        cout << "generating move " << endl;
        bool maxOrMinPlayer = chessboard.GetCurrentPlayer() == WHITE;
        list<Transition> bestPath;
        Minimax(bestPath, DEPTH_MINIMAX, maxOrMinPlayer);
        auto lastElementIt = bestPath.end();
        --lastElementIt;
        move = lastElementIt->mv;
    }
    return move;
}

Move AI::RandomMove(Chessboard& chessboard) {

    DestinationsSet movablePieces = chessboard.GetMovablePieces(chessboard.GetCurrentPlayer());

    // choose a random piece to move
    Coordinate initialPosition = movablePieces[rand() % movablePieces.size()];

    DestinationsSet possibleMoves = chessboard.GetPossibleMoves(initialPosition,false);

    int index = rand() % possibleMoves.size();
    Coordinate randomPosition = possibleMoves[index];

    Move randomMove = make_pair(initialPosition, randomPosition);
    return randomMove;
}

/*
 * returns Heuristic evaluation
 */
int AI::evaluate(Chessboard& chessboard, PieceColor pieceColor) {
    // positive result if white piece is a current player, negative otherwise
    return getScore(chessboard, WHITE) - getScore(chessboard, BLACK);
}

int AI::getScore(Chessboard& chessboard, PieceColor pieceColor) {

    int weightCounter = 0;
    for (auto pieceCoordinate : chessboard.GetAllPieces(pieceColor)) {
        switch (chessboard.getPiece(chessboard.convertCoordinates(pieceCoordinate))->GetType()) {
            case PAWN: weightCounter += PAWN_W; break;
            case BISHOP: weightCounter += BISHOP_W; break;
            case TOWER: weightCounter += TOWER_W; break;
            case KNIGHT: weightCounter += KNIGHT_W; break;
            case QUEEN: weightCounter += QUEEN_W; break;
            case KING: weightCounter += KING_W; break;
        }
    }
    return weightCounter;
}

int AI::Minimax(list<Transition>& bestPath, int depth, bool maximizingPlayer) {

    Chessboard * board = Chessboard::GetInstance();

    PieceColor pieceColor = maximizingPlayer ? WHITE : BLACK;

    if (depth == 0 || board->GameOver(pieceColor)) {
        int eval = evaluate(*board, pieceColor);

        return eval;
    }

    DestinationsSet movablePieces = board->GetMovablePieces(pieceColor);

    if (maximizingPlayer) {
        int maxEval = INT_MIN;
        Move bestMove;
        for (auto piece : movablePieces) {
            for (auto moveTo : board->GetPossibleMoves(piece, false)) {
                Transition t;

                // move piece in the chessboard and remember eated pieces (in some cases)
                Move possibleMove = make_pair(piece, moveTo);

                // make a temporary move
                t = CalculateMove(possibleMove);

                // evaluate current chessboard configuration
                int eval = Minimax(bestPath, depth - 1, false);
//                cout << "color " << pieceColor << ", depth : "<< depth << " , eval " << eval << " with possible move is from x=" << possibleMove.first.first << ", y=" << possibleMove.first.second
//                     << " to x=" << possibleMove.second.first << ", y=" << possibleMove.second.second << endl;

                board->ChangePlayer();
                board->undoTransition(t);

                maxEval = max(maxEval, eval);
                if (maxEval == eval) bestMove = possibleMove;
            }
        }
        Transition t;
        t.mv = bestMove;
        bestPath.push_back(t);

        return maxEval;
    } else {
        int minEval = INT_MAX;
        Move bestMove;
        for (auto piece : movablePieces) {
            for (auto moveTo : board->GetPossibleMoves(piece, false)) {
                Transition t;

                // move piece in the chessboard and remember eated piece (in some cases)
                Move possibleMove = make_pair(piece, moveTo);

                // make a temporary move
                t = CalculateMove(possibleMove);

                // evaluate current chessboard configuration
                int eval = Minimax(bestPath, depth - 1, true);
//                cout << "color " << pieceColor << ", depth : "<< depth << " , eval " << eval << " with possible move is from x=" << possibleMove.first.first << ", y=" << possibleMove.first.second
//                     << " to x=" << possibleMove.second.first << ", y=" << possibleMove.second.second << endl;

                board->ChangePlayer();
                board->undoTransition(t);

                minEval = min(minEval, eval);
                if (minEval == eval) bestMove = possibleMove;
            }
        }
        Transition t;
        t.mv = bestMove;
        bestPath.push_back(t);

        return minEval;
    }
}

Transition AI::CalculateMove(Move move) {

    Chessboard &c = *Chessboard::GetInstance();
    GameController * controller = GameController::GetInstance();

    Piece * p = controller->MakeMove(move, false, true);
    Transition t;
    t.mv = move;
    t.eatenPiece = false;
    if (p != nullptr) {
        t.eatenPiece = true;
        t.positionOfEatenPiece = c.convertCoordinates(move.second);
        t.eatenPieceColor = p->GetColor();
    }
    return t;
}
