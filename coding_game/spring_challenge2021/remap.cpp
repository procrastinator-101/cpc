#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <vector>
#include <ctime>
#include <chrono>
#include <iostream>


using namespace std;

typedef struct s_tree
{
    int         size;                               // size of this tree: 0-3
    bool        isMine;                            // 1 if this is your tree
    bool        isDormant;                         // 1 if this tree is dormant
}               t_tree;


typedef struct s_cell
{
    int         is_empty;
    int         richness;                           // 0 if the cell is unusable, 1-3 for usable cells
    int         neigh[6];
    t_tree      tree;                           // the index of the neighbouring cell for each direction
}               t_cell;


namespace solution
{
    int	ft_uniform(int range_from, int range_to)
    {
        std::random_device                  rand_dev;
        std::mt19937                        generator(rand_dev());
        std::uniform_int_distribution<int>  distr(range_from, range_to);

        return (distr(generator));
    }

    vector <int> ft_get_tree_seeds(int index, int size)
    {
        vector <int> seeds;

        for (int i = 1; i < size; i++)
        {
            
        }
    }
}

int numberOfCells = 37;

t_cell  cells[37];
vector <vector<int>>   forest = {   {25, 24, 23, 22},
                                        {26, 11, 10, 9, 21},
                                        {27, 12, 3, 2, 8, 20},
                                        {28, 13, 4, 0, 1, 7, 19},
                                        {29, 14, 5, 6, 18, 36},
                                        {30, 15, 16, 17, 35},
                                        {31, 32, 33, 34}
                                    };

int main()
{
    /*
    vector <vector<int>>   forest = {   {25, 24, 23, 22},
                                        {26, 11, 10, 9, 21},
                                        {27, 12, 3, 2, 8, 20},
                                        {28, 13, 4, 0, 1, 7, 19},
                                        {29, 14, 5, 6, 18, 36},
                                        {30, 15, 16, 17, 35},
                                        {31, 32, 33, 34}
                                    };
*/
    int     index;
    t_tree  tree;

    int day;                            // the game lasts 24 days: 0-23
    int nutrients;                      // the base score you gain from the next COMPLETE action
    int sun;                            // your sun points
    int score;                          // your current score
    int oppSun;                         // opponent's sun points
    int oppScore;                       // opponent's score
    bool oppIsWaiting;                  // whether your opponent is asleep until the next day
    int numberOfTrees;                  // the current amount of trees
    int numberOfPossibleActions;        // all legal actions


    cin >> numberOfCells; cin.ignore();
    for (int i = 0; i < numberOfCells; i++)
    {
        cin >> index >> cells[index].richness;
        for (int j = 0; j < 6; j++)
            cin >> cells[index].neigh[j];
        cin.ignore();
    }

    // game loop
    while (1) 
    {
        cin >> day; cin.ignore();
        cin >> nutrients; cin.ignore();
        cin >> sun >> score; cin.ignore();
        cin >> oppSun >> oppScore >> oppIsWaiting; cin.ignore();
        cin >> numberOfTrees; cin.ignore();

        for (int i = 0; i < numberOfCells; i++)
            cells[i].is_empty = 1;
        for (int i = 0; i < numberOfTrees; i++)
        { 
            cin >> index >> cells[index].tree.size >> cells[index].tree.isMine >> cells[index].tree.isDormant; cin.ignore();
            cells[index].is_empty = 0;
        }
        
        cin >> numberOfPossibleActions; cin.ignore();
        string possible_actions[numberOfPossibleActions];
        for (int i = 0; i < numberOfPossibleActions; i++) 
            getline(cin, possible_actions[i]);       // try printing something from here to start with
        
        for (int i = 0; i < numberOfPossibleActions; i++) 
            cerr << possible_actions[i] << endl;
        


        // GROW cellIdx | SEED sourceIdx targetIdx | COMPLETE cellIdx | WAIT <message>
        cout << (numberOfPossibleActions > 1 ? possible_actions[1] : possible_actions[0]) << endl;
    }
}
