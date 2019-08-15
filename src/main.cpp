#include<iostream>
#include "../include/path_finder.h"
#include "../include/visualizer.h"

int main()
{
    PathFinder obj_PathFinder;
	Visualizer obj_visualizer;

    int init[2]{ 0,0 };
    int goal[2]{ 4,5 };

    std::string path;
    path = "../src/maze.board";

    vector<vector<State>> maze = obj_PathFinder.read_maze(path);

    obj_PathFinder.search_maze(maze, init, goal);

    obj_visualizer.print_grid(maze);

    return 0;
}