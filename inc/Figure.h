#ifndef FIGURE_H
#define FIGURE_H

#include <SFML/Graphics.hpp>
#include <string>

#include "Axis.h"

using namespace std;

class Figure
{
public:
    Figure(float xstart, float xstop, float ystart, float ystop, int num_divisions, string name);
    ~Figure();

    void plot();

private:
    string name;
    float xstart;
    float xstop;
    float ystart;
    float ystop;
    int num_divisions;

    Axis ax;
};

#endif // FIGURE_H
