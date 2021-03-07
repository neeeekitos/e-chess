#ifndef E_CHESS_GAMECONSTANTS_H
#define E_CHESS_GAMECONSTANTS_H

#include <vector>
#include <string>

using namespace  std;

const int CHESSGAMESIZE = 64;

typedef pair<int, int> Coordinate;

typedef pair <Coordinate, Coordinate> Move;

typedef vector<Move> MoveSet;

typedef vector<Coordinate> DestinationsSet;

enum CastlingSide{
    QUEENSIDE,
    KINGSIDE
};

const int boundaries [120] = {
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, 0, 1, 2, 3, 4, 5, 6, 7, -1,
        -1, 8, 9, 10, 11, 12, 13, 14, 15, -1,
        -1, 16, 17, 18, 19, 20, 21, 22, 23, -1,
        -1, 24, 25, 26, 27, 28, 29, 30, 31, -1,
        -1, 32, 33, 34, 35, 36, 37, 38, 39, -1,
        -1, 40, 41, 42, 43, 44, 45, 46, 47, -1,
        -1, 48, 49, 50, 51, 52, 53, 54, 55, -1,
        -1, 56, 57, 58, 59, 60, 61, 62, 63, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
};

const int positionInBoundariesTable[64] = {
        21, 22, 23, 24, 25, 26, 27, 28,
        31, 32, 33, 34, 35, 36, 37, 38,
        41, 42, 43, 44, 45, 46, 47, 48,
        51, 52, 53, 54, 55, 56, 57, 58,
        61, 62, 63, 64, 65, 66, 67, 68,
        71, 72, 73, 74, 75, 76, 77, 78,
        81, 82, 83, 84, 85, 86, 87, 88,
        91, 92, 93, 94, 95, 96, 97, 98
};

enum GameMode {
    MULTIPLAYER,
    AIPLAYER,
    UNDEFINED
};

enum AIMode{
    RANDOM,
    MINIMAX
};

enum PieceColor {
    EMPTY,
    BLACK,
    WHITE
};

const string PIECE_COLOR_NAME[3] = {
        "empty",
        "black",
        "white"
};

enum GameStatus {
    Check,
    Mate,
    CastlingPossible,
    BlackWin,
    WhiteWin,
    Pat,
    GoesOn,
    BeforeBegin
};

enum WINNER {
    BLACKWINNER,
    WHITEWINNER,
    EQUAL
};



class constantesDeplacement {

};


#endif //E_CHESS_GAMECONSTANTS_H
