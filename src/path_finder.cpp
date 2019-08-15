#include "../include/path_finder.h"
#include <fstream> /*ifstream*/
#include <sstream> /*getline, istringstream*/
#include <math.h>
#include <algorithm>/*sort*/

const int cell_shifter[4][2]{ { 0, 1 },  { 1, 0 }, { 0, -1 }, { -1, 0 } };

vector<State> PathFinder::parse_line(string line)
{
    int n;
    char c;
    istringstream sline(line);
    vector<State>row;
    while (sline >> n >> c && c == ',')
    {
        if (n == 0)
        {
            row.push_back(State::kEmpty);
        }
        else
        {
            row.push_back(State::kObstacle);
        }
    }

    return row;
}

vector<vector<State>> PathFinder::read_maze(string path)
{
    vector<vector<State>>maze{};
    ifstream input_file(path);
    if (input_file)
    {
        string line;
        while (getline(input_file, line))
        {
            maze.push_back(parse_line(line));
        }
    }

    return maze;
}


void PathFinder::add_open(int x, int y, int g, int h, vector<vector<int>>&open, vector<vector<State>> &maze)
{
    open.push_back(vector<int>{x, y, g, h});
    maze[x][y] = State::kClosed;

}

bool compare(const vector<int> a, const vector<int> b)
{
    //f = g + h;
    int f1 = a[2] + a[3];
    int f2 = b[2] + b[3];
    return f1 > f2;
}

void PathFinder::sort_vector(vector<vector<int>>&open)
{
    sort(open.begin(), open.end(), compare);
}

int PathFinder::heuristics(int x1, int y1, int x2, int y2)
{
    return abs(x2 - x1) + abs(y2 - y1);
}

bool PathFinder::valid_cell(int x2, int y2, vector<vector<State>> &maze)
{
    bool is_on_grid_x = (x2 >= 0) && (x2 < maze.size());
    bool is_on_grid_y = (y2 >= 0) && (y2 < maze[0].size());

    if (is_on_grid_x && is_on_grid_y)
    {
        bool is_empty = false;

        if (maze[x2][y2] == State::kEmpty)
        {
            is_empty = true;
        }

        return is_empty;
    }
    else
    {
        return false;
    }

}

void PathFinder::expand_neighbors(vector<int> &current, int goal[2], vector<vector<int>> &open, vector<vector<State>> &maze)
{
    int x = current[0];
    int y = current[1];
    int g = current[2];

    for (int i = 0; i < 4; i++)
    {
        int x2 = x + cell_shifter[i][0];
        int y2 = y + cell_shifter[i][1];

        if (valid_cell(x2, y2, maze))
        {
            int g2 = g + 1;
            int h2 = heuristics(x2, y2, goal[0], goal[1]);
            add_open(x2, y2, g2, h2, open, maze);
        }
    }
}


vector<vector<State>> PathFinder::search_maze(vector<vector<State>> &maze, int init[2], int goal[2])
{
    int x = init[0];
    int y = init[1];
    int g = 0;
    int h = heuristics(x, y, goal[0], goal[1]);
    vector<vector<int>>open{};
    add_open(x, y, g, h, open, maze);

    while (open.size() > 0)
    {
        sort_vector(open);

        auto current = open.back();
        open.pop_back();

        x = current[0];
        y = current[1];
        maze[x][y] = State::kPath;

        if (x == goal[0] && y == goal[1])
        {
            maze[init[0]][init[1]] = State::kStart;
            maze[goal[0]][goal[1]] = State::kFinish;

            return maze;
        }

        expand_neighbors(current, goal, open, maze);
    }

    printf("No Path Found!");
    return vector<vector<State>>{};
}