#include "Turtle.h"
#include "windows.h"

Turtle::Turtle()
{}
Turtle::~Turtle()
{}

void Turtle::init(int startx, int starty, vector <vector <char>> startboard){
    x = startx;
    y = starty;
    board = startboard;
}

void Turtle::print(){
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[i].size(); j++){
            if (y == i && x == j) cout << 'x';
            else if (board[i][j] == 'x') cout << ' ';
            else cout << board[i][j];
        }
        cout << endl;
    }
    Sleep(50);
    system("cls");
}

void Turtle::moveTurtle(string dir){
    if (dir == "down") y += 1;
    if (dir == "up") y -= 1;
    if (dir == "left") x -= 1;
    if (dir == "right") x += 1;
}

void Turtle::checkCrossRoad(){
    int counter = 0;
    if (board[y - 1][x] == ' ') counter += 1;
    if (board[y + 1][x] == ' ') counter += 1;
    if (board[y][x + 1] == ' ') counter += 1;
    if (board[y][x - 1] == ' ') counter += 1;
    if (counter == 2){
        vector <int> temp = {y, x};
        checkpoints.push_back(temp);
    }
}

void Turtle::logic(){
    if (x == 0 || y == 0 || x == board[0].size() - 1 || y == board.size() - 1) {
        running = false;
        return;
    }
    checkCrossRoad();
    if (board[y][x - 1] == ' '){
        //cout << " @ " << "left" << endl;
        board[y][x] = 'x';
        moveTurtle("left");
        return;
    }
    else if (board[y - 1][x] == ' '){
        //cout << " @ " << "up" << endl;
        board[y][x] = 'x';
        moveTurtle("up");
        return;
    }
    else if (board[y][x + 1] == ' '){
        //cout << " @ " << "right" << endl;
        board[y][x] = 'x';
        moveTurtle("right");
        return;
    }
    else if (board[y + 1][x] == ' '){
        //cout << " @ " << "down" << endl;
        board[y][x] = 'x';
        moveTurtle("down");
        return;
    }


    // я в тупике надо выходить

    if (board[y - 1][x] != ' ' && board[y][x + 1] != ' ' && board[y + 1][x] != ' ' && board[y][x - 1] != ' '){
        //cout << checkpoints[checkpoints.size() - 1][0] << " @ " << checkpoints[checkpoints.size() - 1][1] << endl;
        if (y == checkpoints[checkpoints.size() - 1][0] && x == checkpoints[checkpoints.size() - 1][1]){
            vector <vector <int>> temp(checkpoints.size() - 1);
            for (int i = 0; i < checkpoints.size() - 1; i++) temp[i] = checkpoints[i];
            checkpoints.clear();
            checkpoints = temp;
        }
        while (y != checkpoints[checkpoints.size() - 1][0] || x != checkpoints[checkpoints.size() - 1][1]){
            if (board[y - 1][x] == 'x'){
                //cout << " @ " << "up" << endl;
                board[y][x] = 'x';
                moveTurtle("up");
                return;
            }
            else if (board[y][x + 1] == 'x'){
                //cout << " @ " << "right" << endl;
                board[y][x] = 'x';
                moveTurtle("right");
                return;
            }
            else if (board[y + 1][x] == 'x'){
                //cout << " @ " << "down" << endl;
                board[y][x] = 'x';
                moveTurtle("down");
                return;
            }
            else if (board[y][x - 1] == 'x'){
                //cout << " @ " << "left" << endl;
                board[y][x] = 'x';
                moveTurtle("left");
                return;
            }
        }
    }

}

bool Turtle::isRunning(){
    return running;
}
