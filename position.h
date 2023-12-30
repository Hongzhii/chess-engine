#include <string>
using namespace std;

enum Piece{PAWN = 1, KNIGHT, BISHOP, ROOK, QUEEN, KING};

class Position{
    int board [8][8]{0};
    int to_move;

    public:
    Position();
    Position(Position& p);
    ~Position();
    bool play(string move);
    bool checkAndMove(Piece p, string target);
    void show() const;
};