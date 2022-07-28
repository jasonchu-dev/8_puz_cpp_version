#include "UCS.h"
#include "check.h"

using namespace std;

bool ucs_search(Node p) {
    vector<Node> queue, checked;
    queue.push_back(p);
    // clock starts here the moment first node is in queue    
    start_time = clock();
    // nothing in queue? then return false for no solution
    if (queue.empty()) return 0;
    // but if there is, then continue checking for a solution
    while (queue.size() != 0) {
    // grab and track record queue size
        if (q_size < queue.size()) q_size = queue.size();
        // check the smallest object
        Node curr = queue[0];
        // is it a goal?
        if (curr.goal()) {
            // the moment goal is found, then timer for search stops
            finish_time = clock() - start_time;
            // start traversing back to add solution
            path.push_back(curr);
            while (curr.parent) {
                curr.parent = curr.parent->parent; // this might be wrong
                path.insert(path.begin(), curr);
            }
            // checked already, put in here
            checked.push_back(curr);
            // true if solution is found
            found = 1;
            // now get out of this class
            break;
        }
        // checked already, put in here
        checked.push_back(curr);
        // for very root of node that has no parent, set heuristic
        if (!curr.parent) curr.f = curr.h; // or 0 since root is at depth 0
        // expand
        curr.move();
        // check parent objects to calculate heuristics and to check whether it should be appended to queue to avoid repeats
        for (int s = 0; s < curr.kids.size(); s++) {
            Node kid = curr.kids.at(s);
            // track number of nodes expanded
            expanded += 1;
            // heuristics calculation
            kid.g = kid.parent->g + 1;
            kid.f = kid.g + kid.h;
            // repeat object?
            if (!prev_encounter_check(queue, kid) && !prev_encounter_check(checked, kid))
                // then add
                queue.push_back(kid);
        }
        // take object out of queue since we are done checking it
        queue.erase(queue.begin());
    }
    return 0;
}