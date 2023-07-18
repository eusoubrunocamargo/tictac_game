#include <iostream>
#include <vector>
#include <string>
using namespace std;

void greet () {
    cout << "JOGO DA VELHA!" << endl;
    cout << "Jogador 1: X" << endl;
    cout << "Jogador 2: O" << endl;
    cout << "\n\n";
}

void create_gamepad (vector<vector<string>>& gamepad){
    int counter = 1;
    for(int i = 0; i < gamepad.size(); i++){
        for(int j = 0; j < gamepad[i].size(); j++){
            gamepad[i][j] = "[ " + to_string(counter) + " ]";
            counter++;
        }
    }
}

void print_gamepad (vector<vector<string>>& gamepad){
    for(const auto& row: gamepad){
        for(const auto& cell: row){
            cout << cell << " ";
        }
        cout << "\n\n";
    }
}

void player1_choice(vector<vector<string>>& gamepad, int number){
    int check_number = 1;
    for(auto& row: gamepad){
        for(auto& cell: row){
            if(cell == "[ " + to_string(check_number) + " ]" && check_number == number){
                cell = "[ X ]";
            }
            check_number++;
        }
    }
}

bool check_winner1(vector<vector<string>>& gamepad){
    int rowcount = 0;
    int colcount = 0;

    //check row
    for(auto& row: gamepad){
        for(auto& cell: row){
            if(cell == "[ X ]"){
                rowcount++;
            }
        }
        if (rowcount == 3){
            return true;
        }
        rowcount = 0;
    }

    //check column
    for(int j = 0; j < gamepad[0].size(); j++){
        for(int i = 0; i < gamepad.size(); i++){
            if(gamepad[i][j] == "[ X ]"){
                colcount++;
            }
        }
        if (colcount == 3){
            return true;
        }
        colcount = 0;
    }

    //check diagonal
    vector<vector<int>>cells_top_right = {{0,0},{1,1},{2,2}};
    vector<vector<int>>cells_bottom_left = {{2,0}, {1,1}, {0,2}};
    int diagonal_count1 = 0;
    int diagonal_count2 = 0;
    for(auto& cell: cells_top_right){
        if(gamepad[cell[0]][cell[1]] == "[ X ]"){
            diagonal_count1++;
        }
    }
    if (diagonal_count1 == 3){
        return true;
    }

    for (auto& cell: cells_bottom_left){
        if(gamepad[cell[0]][cell[1]] == "[ X ]"){
            diagonal_count2++;
        }
    }
    if (diagonal_count2 == 3){
        return true;
    }

    return false;

}

void player2_choice(vector<vector<string>>& gamepad, int number){
    int check_number = 1;
    for(auto& row: gamepad){
        for(auto& cell: row){
            if(cell == "[ " + to_string(check_number) + " ]" && check_number == number){
                cell = "[ O ]";
            }
            check_number++;
        }
    }
}

bool check_winner2(vector<vector<string>>& gamepad){
    int rowcount = 0;
    int colcount = 0;

    //check row
    for(auto& row: gamepad){
        for(auto& cell: row){
            if(cell == "[ O ]"){
                rowcount++;
            }
        }
        if (rowcount == 3){
            return true;
        }
        rowcount = 0;
    }

    //check column
    for(int j = 0; j < gamepad[0].size(); j++){
        for(int i = 0; i < gamepad.size(); i++){
            if(gamepad[i][j] == "[ O ]"){
                colcount++;
            }
        }
        if (colcount == 3){
            return true;
        }
        rowcount = 0;
    }

    //check diagonal
    vector<vector<int>>cells_top_right = {{0,0},{1,1},{2,2}};
    vector<vector<int>>cells_bottom_left = {{2,0}, {1,1}, {0,2}};
    int diagonal_count1 = 0;
    int diagonal_count2 = 0;
    for(auto& cell: cells_top_right){
        if(gamepad[cell[0]][cell[1]] == "[ O ]"){
            diagonal_count1++;
        }
    }
    if (diagonal_count1 == 3){
        return true;
    }

    for (auto& cell: cells_bottom_left){
        if(gamepad[cell[0]][cell[1]] == "[ O ]"){
            diagonal_count2++;
        }
    }
    if (diagonal_count2 == 3){
        return true;
    }

    return false;

}


