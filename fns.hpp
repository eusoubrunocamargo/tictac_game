#include <iostream>
#include <vector>
#include <string>
using namespace std;

void greet();
void print_gamepad (vector<vector<string>>& gamepad);
void create_gamepad (vector<vector<string>>& gamepad);
void player1_choice(vector<vector<string>>& gamepad, int number);
bool check_winner1(vector<vector<string>>& gamepad);
void player2_choice(vector<vector<string>>& gamepad, int number);
bool check_winner2(vector<vector<string>>& gamepad);


