#include "check.h"

bool prev_encounter_check(std::vector<Node> list, Node kid) {
    // iterate through queue and checked for repeats
    for (const Node &i : list)
        for (int r = 0; r < a; r++)
            for (int c = 0; c < b; c++)
                if (kid.puzzle[r][c] != i.puzzle[r][c])
                    // if no repeat
                    return 0;
    // if it is a repeat
    return 1;
}