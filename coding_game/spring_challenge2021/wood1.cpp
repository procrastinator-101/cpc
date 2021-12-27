#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct s_cell
{
    int index;                              // 0 is the center cell, the next cells spiral outwards
    int richness;                           // 0 if the cell is unusable, 1-3 for usable cells
    int neigh[6];                           // the index of the neighbouring cell for each direction
}               t_cell;

typedef struct s_tree
{
    int cellIndex;                          // location of this tree
    int size;                               // size of this tree: 0-3
    bool isMine;                            // 1 if this is your tree
    bool isDormant;                         // 1 if this tree is dormant
}               t_tree;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int numberOfCells;                      // 37
    cin >> numberOfCells; cin.ignore();

    t_cell  cells[numberOfCells];
    for (int i = 0; i < numberOfCells; i++)
        cin >> cells[i].index >> cells[i].richness >> cells[i].neigh[0] >> cells[i].neigh[1] >> cells[i].neigh[2] >> cells[i].neigh[3] >> cells[i].neigh[4] >> cells[i].neigh[5]; cin.ignore();

    // game loop
    while (1) {
        int day;                            // the game lasts 24 days: 0-23
        int nutrients;                      // the base score you gain from the next COMPLETE action
        int sun;                            // your sun points
        int score;                          // your current score
        int oppSun;                         // opponent's sun points
        int oppScore;                       // opponent's score
        bool oppIsWaiting;                  // whether your opponent is asleep until the next day
        int numberOfTrees;                  // the current amount of trees

        
        cin >> day; cin.ignore();
        cin >> nutrients; cin.ignore();
        cin >> sun >> score; cin.ignore();
        cin >> oppSun >> oppScore >> oppIsWaiting; cin.ignore();
        cin >> numberOfTrees; cin.ignore();

        t_tree  trees[numberOfTrees];
        for (int i = 0; i < numberOfTrees; i++) 
            cin >> trees[i].cellIndex >> trees[i].size >> trees[i].isMine >> trees[i].isDormant; cin.ignore();
        int numberOfPossibleActions;            // all legal actions
        cin >> numberOfPossibleActions; cin.ignore();
        for (int i = 0; i < numberOfPossibleActions; i++) {
            string possibleAction;
            getline(cin, possibleAction);       // try printing something from here to start with
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // GROW cellIdx | SEED sourceIdx targetIdx | COMPLETE cellIdx | WAIT <message>
        cout << "WAIT" << endl;
    }
}
