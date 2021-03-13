#ifndef E_CHESS_KING_H
#define E_CHESS_KING_H

#include "Piece.h"
#include "Chessboard.h"
#include "GameConstants.h"

// Standard library
#include <vector>

using namespace std;

class King : public Piece {
public:
    King(PieceColor color);

    /*
     * builder de King
     */

    virtual char PieceToFEN();

    /*
     * get the FEN representation of a Piece
     */
    bool isValidMove(Chessboard board, int pos);

    /*
     * Check if a move is valid or not
     */

    vector<int> movements(Chessboard board);
    /*
     * List of all the possible moves
     */

    virtual void NotifyMove (Move mv) override;

    bool IsFirstMoveDone();

    /**
     * This variable is set to false as long as the king has not moved
     */
    bool firstMoveDone;

private:
    vector<int> movelists{-11, -10, -9, -1, 1, 9, 10, 11};

    vector<int> moveroques{-2, 2};
};


#endif //E_CHESS_KING_H
