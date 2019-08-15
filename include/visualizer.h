#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <iostream>
#include<vector>
#include <string>
#include "path_finder.h"


class Visualizer
{
public:
    
    /*print the grid map*/
    void print_grid(vector<vector<State>> maze);

private:

    /*convert State to a string*/
    string cell_string(State cell);
};

#endif /*VISUALIZER_H*/