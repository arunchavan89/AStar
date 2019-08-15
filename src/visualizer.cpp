#include "../include/visualizer.h"

string Visualizer::cell_string(State cell)
{
    switch (cell)
    {
    case State::kEmpty: return "E  ";
    case State::kObstacle: return "XX ";
    case State::kClosed: return "C  ";
    case State::kPath: return "P  ";
    case State::kStart: return "S  ";
    case State::kFinish: return "G  ";
    default: return "0";
    }
}

void Visualizer::print_grid(vector<vector<State>> maze)
{
    for (int row = 0; row < maze.size(); row++)
    {
        for (int col = 0; col < maze[row].size(); col++)
        {
            cout << cell_string(maze[row][col]);
        }
        cout << endl;
    }
}