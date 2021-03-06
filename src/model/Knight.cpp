#include "../../include/model/Knight.h"

#include <algorithm>

Knight::Knight(PieceColor aColor): Piece(aColor) {
    this->moveDirections = {-21, -19, -12, -8, 8, 12, 19, 21};
    this->directionIsLimited = true;
    this->type = KNIGHT;
}

char Knight::PieceToFEN() {
    return (this->GetColor() == WHITE ? 'n' : 'N');
}

/*

char Knight::PieceToFEN() {
    if(this->getColor()==BLACK)
    {
        return 'N';
    }
    else
    {
        return 'n';
    }

}

bool Knight::isValidMove(Chessboard board, int pos) {
    vector<int> validMoves = this->movements(board);
    return (find(validMoves.begin(),validMoves.end(),pos) != validMoves.end() );
}

vector<int> Knight::movements(Chessboard board) {
    vector<int> list;
    int pos;
    int index = board.indexOf(this);

    for (int i = 0; i < this->movelists.size(); i++){
        pos = getCase120(getCase64(index) + this->movelists[i]);
        if (pos != -1 && board.getCase(pos).getColor() != this->getColor()){
            list.push_back(pos);
        }
    }

    return list;
}

vector<int> Knight::eatableCase(Chessboard board) {
    vector<int> list;
    int pos;
    int index = board.indexOf(this);

    for (int i = 0; i < this->movelists.size(); i++){
        pos = getCase120(getCase64(index) + this->movelists[i]);
        if (pos != -1 && board.getCase(pos).getColor() == this->getColor()){
            list.push_back(pos);
        }
    }

    return list;
}*/