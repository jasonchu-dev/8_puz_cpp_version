#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <string>
#include <stdlib.h>
#include <cstring> // memcpy

using namespace std;

const int a = 3, b = 3; // change here for nxn
extern int expanded;
extern int q_size;
extern clock_t start_time, finish_time; // need to change datatype for time
extern bool found; // might need to be put in search object or function

class Node {
    private:
        int solution[a][b] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}}; // change here for nxn
    public:
        int puzzle[a][b];
        vector<Node> kids;
        int h; // estimated distance to goal
        int g; // cost from initial
        int f; // heuristic total
        int val; // user input taken for which hueristic to calculate h
        Node *parent;

        Node(int[a][b], int);
        // special function to overide iteration system in heapq module
        // def __lt__(self, other):
        //     return self.f < other.f
        void calc_h();
        // int get_i_j();
        bool goal();
        void move();
        void r(int&, int&), l(int&, int&), d(int&, int&), u(int&, int&);
};

extern vector<Node> path;

#endif