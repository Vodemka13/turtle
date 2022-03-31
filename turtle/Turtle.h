#ifndef TURTLE_H_INCLUDED
#define TURTLE_H_INCLUDED
#ifndef UPDATE_H
#define UPDATE_H

#include <iostream>
#include <vector>

using namespace std;

class Turtle {

public:
    Turtle();
    ~Turtle();

    void init(int startx, int starty, vector <vector <char>> board);
    void print();
    void logic();
    void checkCrossRoad();
    void moveTurtle(string dir);
    bool isRunning();

private:
    int x;
    int y;
    bool running = true;
    vector <vector <char>> board;
    vector <vector <int>> checkpoints;
};



#endif // TURTLE_H_INCLUDED
#endif // UPDATE_H
