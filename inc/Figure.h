#ifndef FIGURE_H
#define FIGURE_H

#include <SFML/Graphics.hpp>

#include "Axis.h"

class Figure
{
public:
    Figure(float xstart, float xstop, float ystart, float ystop, int num_divisions);
    ~Figure();

    void plot();

private:
    float xstart;
    float xstop;
    float ystart;
    float ystop;
    int num_divisions;

    Axis ax;
};

#endif // FIGURE_H
