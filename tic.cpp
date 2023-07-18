#include <iostream>
#include <vector>
#include <string>
#include "fns.hpp"

using namespace std;

int main () {

    greet();

    vector<vector<string>>gamepad(3, vector<string>(3, "[  ]"));
    create_gamepad(gamepad);
    print_gamepad(gamepad);
    bool endgame = false;

    while(!endgame){
        cout << "Jogador 1, escolha um número:\n" << endl;
        int choice;
        cin >> choice;
        player1_choice(gamepad, choice);
        if(check_winner1(gamepad)){
            cout << "Jogador 1 venceu!" << endl;
            print_gamepad(gamepad);
            endgame = true;
            break;
        }
        print_gamepad(gamepad);
        cout << "Jogador 2, escolha um número:" << endl;
        int choice2;
        cin >> choice2;
        player2_choice(gamepad, choice2);
        if(check_winner2(gamepad)){
            cout << "Jogador 2 venceu!" << endl;
            print_gamepad(gamepad);
            endgame = true;
            break;
        }
        print_gamepad(gamepad);
    }

    return 0;
}