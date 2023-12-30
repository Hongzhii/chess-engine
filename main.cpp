#include <iostream>
#include <string>
#include "position.h"
using namespace std;

int main(){
    Position p;
    while(true){
        p.show();
        cout << "Please input a move:\n";
        string move;
        cin >> move;

        if(move.compare("exit") == 0){
            break;
        }

        if(!p.play(move)){
            cout << "Please enter a valid move\n";
        }
    }

    return 0;
}