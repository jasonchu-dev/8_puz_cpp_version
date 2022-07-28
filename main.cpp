#include <iostream>
#include <set>
#include <string>
#include "Node.h"
#include "UCS.h"

using namespace std;

int main() {
    // set up blank array
    int puzzle[a][b] = {{1, 2, 3}, 
                        {0, 4, 6}, 
                        {7, 5, 8}};
    int spot = 0, inp;
    // saved list of user inputs to prevent repeat values
    set<int> userinput;
    // prompt user
    // cout << "\nFill in the array:\n\n";

    // // fill array with user input
    // for (int i = 0; i < a; i++) {
    //     for (int j = 0; j < b; j++) {
    //         spot += 1;
    //         cout << "spot " << spot << endl; // might need an endl
    //         // check for valid inputs or repeat numbers
    //         while (1) {
    //             cin >> inp;
    //             if ((-1 < inp && inp < 9) && userinput.find(inp) == userinput.end()) { // change here for nxn
    //                 puzzle[i][j] = inp;
    //                 // if valid, append and break
    //                 userinput.insert(inp);
    //                 break;
    //             } 
    //             // if not, keep looking
    //             else cout << "Invalid or already added, try again"; // might need an endl
    //             cin.clear(); cin.ignore(100, '\n'); // might need to get rid of cin ignore
    //         }
    //     }
    // }
    // // print puzzle for user reference
    // cout << "\n\n";
    // for (int i = 0; i < a; i++) {
    //     cout << '[';
    //     for (int j = 0; j < b; j++) {
    //         cout << puzzle[i][j];
    //         if (j != 2) cout << ", ";
    //     }
    //     cout << "]\n";
    // }
    // cout << "\n";
    // what does the user want?
    int val = 1;
    // cin.clear(); cin.ignore(100, '\n'); // might need to get rid of cin ignore
    // cout << "\nPress 1 for Uniform Cost Search\nPress 2 for A* with Manhattan Distance heuristic\nPress 3 for A* with Misplaced Tiles heuristic\n";
    // cin >> val;

    // tell to wait
    cout << "Please wait...";

    // produce node object
    Node p(puzzle, val);
    string str = "";

    // Which A*?
    if (val == 2 || val == 3) {
        if (val == 2) str = "A* with Manhattan Distance heuristic\n";
        else str = "A* with Misplaced Tiles heuristic\n";
        // a_search(p);
    }

    // UCS
    else {
        str = "Uniform Cost Search\n";
        // make the search object to start its work
        ucs_search(p);
    }

    if (!found) cout << "\n\nNo solution found";
    else {
        cout << "\n\nSolution:\n\n";
        // traverse through solution list
        for (int i = 0; i < path.size(); i++) {
            // print out attributes of each node object
            cout << "Depth: " << i << endl;
            cout << "g(n) = " << path[i].g << endl;
            cout << "h(n) = " << path[i].h << endl;
            for (int j = 0; j < a; j++) {
                cout << '[';
                for (int k = 0; k < b; k++) {
                    cout << path[i].puzzle[j][k];
                    if (k != 2)  cout << ", ";
                }
                cout << "]\n";
            }
            cout << endl;
        }

        // print out specs of search object
        cout << endl << str;
        cout << "\nNodes expanded: " << expanded;
        cout << "\nMax queue size: " << q_size;
        cout << "\nTime in sec: " << finish_time;
    }
    cout << "\n\nBy Jason Chu";
    cout << "\nProgram simulated and tested on:\nIntel(R) Core(TM) i5-7300HQ CPU @ 2.50GHz\n\n";
    return 0;
}