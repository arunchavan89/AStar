#ifndef PATH_FINDER_H_
#define PATH_FINDER_H_

#include <iostream>
#include<vector>

using namespace std;

enum class State
{
    kEmpty,
    kObstacle,
    kClosed,
    kPath,
    kStart,
    kFinish,
};

class PathFinder
{
public:
    
    /*search for the path inside the maze with A* algorithm*/
    vector<vector<State>> search_maze(vector<vector<State>> &maze, int init[2], int goal[2]);
    
    /*read the input maze which is in maze.board file*/
    vector<vector<State>> read_maze(string path);
    

private:
    /*parse the input line and read each element as a State*/
    vector<State> parse_line(string line);

    /*calculate heuristics with Manhattan formula*/
    int heuristics(int x1, int y1, int x2, int y2);

    /*add to open list*/
    void add_open(int x, int y, int g, int h, vector<vector<int>>&open, vector<vector<State>> &maze);

    /*sorting*/
    void sort_vector(vector<vector<int>>&open);

    /*expand path by checking neighboring cells*/
    void expand_neighbors(vector<int>&current, int goal[2], vector<vector<int>> &open, vector<vector<State>>&maze);

    /*check if new cell is within the maze*/
    bool valid_cell(int x2, int y2, vector<vector<State>> &maze);
};

#endif /*PATH_FINDER_H_*/