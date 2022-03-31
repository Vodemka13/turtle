#include <iostream>
#include <fstream>
#include <vector>
#include "Turtle.h"


using namespace std;

long itc_len(string str) {
    int i = 0;
    while (str[i] != '\0'){
        i += 1;
    }
    return i;
}

void input(int &x, int &y, vector <vector <char>> &board) {
    ifstream in;
    string line;
    in.open("answ.txt");
    bool bruh = true;
    while(in.good()){
        getline(in, line);
        if (line[0] == '*'){
            vector <char> line1(itc_len(line));
            for (int i = 0; i < itc_len(line); i++) line1[i] = line[i];
            board.push_back(line1);
        }
        else {
                if (bruh) {
                    bruh = false;
                    x = (int) line[0] - 48;
                }
                else y = (int) line[0] - 48;
        }
    }
    in.close();
}

bool check(int x, int y, vector <vector <char>> board){
    if (board[y][x] == '*') return false;
    else {
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[i].size(); j++){
                if (board[i][j] != '*' && board[i][j] != ' ') return false;
            }
        }
    }
    return true;
}

Turtle *turtle = nullptr;

int main() {
    vector <vector <char>> board;
    int x, y;
    input(x, y, board);

    if (check(x, y, board)){
        turtle = new Turtle();
        turtle->init(y, x, board);
        turtle->print();

        while (turtle->isRunning()){
            turtle->logic();
            turtle->print();
        }
    }
    else {
        cout << "Incorrect input";
    }


    return 0;
}
