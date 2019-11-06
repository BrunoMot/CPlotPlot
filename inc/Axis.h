#ifndef AXIS_H
#define AXIS_H

#include <SFML/Graphics.hpp>

#include "SFMLLine.h"

class Axis{
public:
    Axis();
    Axis(float window_height, float window_width, float xstart, float xstop,
               float ystart, float ystop, int num_divisions);
    ~Axis();

    float getxStart();
    float getxStop();
    float getyStart();
    float getyStop();
    float getNumDivisions();

    Line getXaxisSpine();
    Line getYaxisSpine();

private:
    float xstart;
    float xstop;
    float ystart;
    float ystop;
    int num_divisions;
    float window_height;
    float window_width;

    Line xaxis_spine;
    Line yaxis_spine;

    Line* xticks;
    Line* yticks;

};


#endif