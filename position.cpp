#include <string>
#include <iostream>
#include "position.h"
using namespace std;

Position::Position() : to_move(0){
    for(int i = 0; i < 8; i++){
        board[1][i] = -1;
        board[6][i] = 1;
    }

    board[0][0] = -4;
    board[0][7] = -4;
    board[0][1] = -2;
    board[0][6] = -2;
    board[0][2] = -3;
    board[0][5] = -3;
    board[0][3] = -5;
    board[0][4] = -6;

    board[7][0] = 4;
    board[7][7] = 4;
    board[7][1] = 2;
    board[7][6] = 2;
    board[7][2] = 3;
    board[7][5] = 3;
    board[7][3] = 5;
    board[7][4] = 6;
}

Position::Position(Position& p) : to_move(p.to_move){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            board[i][j] = p.board[i][j];
        }
    }
}

Position::~Position(){}

bool Position::play(string move){
    if(move.compare("exit") == 0){
        return true;
    }
    
    char piece_char = move[0];
    Piece p;
    string target;
    bool capture = (move[1] == 'x');

    if(piece_char >= 97){
        p = PAWN;
    }
    else if(piece_char == 'R'){
        p = ROOK;
    }
    else if(piece_char == 'K'){
        p = KNIGHT;
    }
    else if(piece_char == 'B'){
        p = BISHOP;
    }

    if(capture){
        target = move.substr(2, 2);
    }
    else if(p == 1){
        target = move;
    }
    else{
        target = move.substr(1, 2);
    }

    checkAndMove(p, target);
}

bool Position::checkAndMove(Piece p, string target){

}

void Position::show() const{
    cout << "-------------------------" << endl;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            int piece = board[i][j];
            cout << "|";
            if(piece == -1){
                cout << "BP";
            }
            else if(piece == -2){
                cout << "BN";
            }
            else if(piece == -3){
                cout << "BB";
            }
            else if(piece == -4){
                cout << "BR";
            }
            else if(piece == -5){
                cout << "BQ";
            }
            else if(piece == -6){
                cout << "BK";
            }
            else if(piece == 1){
                cout << "WP";
            }
            else if(piece == 2){
                cout << "WN";
            }
            else if(piece == 3){
                cout << "WB";
            }
            else if(piece == 4){
                cout << "WR";
            }
            else if(piece == 5){
                cout << "WQ";
            }
            else if(piece == 6){
                cout << "WK";
            }
            else if(piece == 0){
                cout << "  ";
            }
            else{
                cout << "XX";
            }
        }
        cout << "|" << endl;
        cout << "-------------------------" << endl;
    }

    cout << (to_move == 0 ? "White to move\n" : "Black to move\n");
}