#include "Node.h"

using namespace std;

const int x = 3, y = 3; // change here for nxn
int expanded = 0;
int q_size = 0;
vector<Node> path;
clock_t start_time, finish_time; // need to change datatype for time
bool found = 0; // might need to be put in search object or function

Node::Node(int puzzle[x][y], int val) : h(0), g(0), f(0), val(val), parent(nullptr) { memcpy(this->puzzle, puzzle, x*y*sizeof(int)); }

void Node::calc_h() {
    for (int r1 = 0; r1 < x; r1++) {
        for (int c1 = 0; c1 < y; c1++) {
            // is this tile in the right place?
            if (puzzle[r1][c1] != solution[r1][c1] && puzzle[r1][c1] != 0) {
                found = 0;
                if (val == 2) {
                    for (int r2 = 0; r2 < x; r2++) {
                        for (int c2 = 0; c2 < y; c2++) {
                            // find position of where it needs to go
                            if (solution[r2][c2] == puzzle[r1][c1]) {
                                // calculate h(n) and append for others
                                h += abs(r2 - r1) + abs(c2 - c1);
                                // break loop to save time and move on to next object with bool
                                found = 1;
                            }
                            if (found) break;
                        }
                        if (found) break;
                    }
                }
                // or if misplaced then just count the tile
                else h = 1;
            }
        }
    }
}

// find blank tile spot to prep for switching
// int Node::get_i_j() {
//     for (i; i < x; i++) {
//         for (int j = 0; j < y; j++) {
//             if (puzzle[i][j] == 0) { return j; }
//         }
//     }
//     return 0;
// }

// if goal then save time and get out of search
bool Node::goal() {
    for (int r = 0; r < x; r++)
        for (int c = 0; c < y; c++)
            if (puzzle[r][c] != solution[r][c]) return false;
    return true;
}

// func to make kids and expand
void Node::move() {
    // get blank spot
    bool found = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (puzzle[i][j] == 0) { 
                r(i, j); l(i, j); d(i, j); u(i, j);
                found = 1; break; 
            }
        }
        if (found) break;
    }
}

// go right
void Node::r(int &i, int &j) {
    if (j != 2) {
        // copy so it doesn't just make a pointer to object which will affect its attributes in long run
        int next_puzzle[x][y];
        memcpy(next_puzzle, puzzle, x*y*sizeof(int));
        // swap
        swap(next_puzzle[i][j], next_puzzle[i][j + 1]);
        Node child(next_puzzle, val);
        // no need to calc h(n) if UCS
        if (val != 1) { child.calc_h(); }
        // correlate child to parent by pointing and appending
        // must append first otherwise anything after appending won't work as vector will not be willing to reallocate space just for one var
        child.parent = this;
        kids.push_back(child);
    }
}

// go left 
void Node::l(int &i, int &j) {
    // can't go left?
    if (j != 0) {
        // copy so it doesn't just make a pointer to object which will affect its attributes in long run
        int next_puzzle[x][y];
        memcpy(next_puzzle, puzzle, x*y*sizeof(int));
        // swap
        swap(next_puzzle[i][j], next_puzzle[i][j - 1]);
        // produce child
        Node child(next_puzzle, val);
        // no need to calc h(n) if UCS
        if (val != 1) { child.calc_h(); }
        // correlate child to parent by pointing and appending
        // must append first otherwise anything after appending won't work as vector will not be willing to reallocate space just for one var
        child.parent = this;
        kids.push_back(child);
    }
}

// go down 
void Node::d(int &i, int &j) {
    // can't go down?
    if (i != 2) {
        // copy so it doesn't just make a pointer to object which will affect its attributes in long run
        int next_puzzle[x][y];
        memcpy(next_puzzle, puzzle, x*y*sizeof(int));
        // swap
        swap(next_puzzle[i + 1][j], next_puzzle[i][j]);
        // produce child
        Node child(next_puzzle, val);
        // no need to calc h(n) if UCS
        if (val != 1) { child.calc_h(); }
        // correlate child to parent by pointing and appending
        // must append first otherwise anything after appending won't work as vector will not be willing to reallocate space just for one var
        child.parent = this;
        kids.push_back(child);
    }
}

// go up 
void Node::u(int &i, int &j) {
    // can't go down?
    if (i != 0) {
        // copy so it doesn't just make a pointer to object which will affect its attributes in long run
        int next_puzzle[x][y];
        memcpy(next_puzzle, puzzle, x*y*sizeof(int));
        // swap
        swap(next_puzzle[i - 1][j], next_puzzle[i][j]);
        // produce child
        Node child(next_puzzle, val);
        // no need to calc h(n) if UCS
        if (val != 1) { child.calc_h(); }
        /// correlate child to parent by pointing and appending
        // must append first otherwise anything after appending won't work as vector will not be willing to reallocate space just for one var
        child.parent = this;
        kids.push_back(child);
    }
}