#include "../inc/Axis.h"

Axis::Axis()
{
    xstart=xstop=ystart=ystop=num_divisions=0;
    xaxis_spine = Line(0, 0, 0, 0);
    yaxis_spine = Line(0, 0, 0, 0);
    
    xticks = new Line(0, 0, 0, 0);
    yticks = new Line(0, 0, 0, 0);
}

Axis::Axis(float window_height, float window_width, float xstart, float xstop,
           float ystart, float ystop, int num_divisions):
xstart(xstart), xstop(xstop), ystart(ystart), ystop(ystop), num_divisions(num_divisions), window_height(window_height),
window_width(window_width)
{
    xaxis_spine = Line(10, window_height - 10, window_width - 10, window_height - 10);
    yaxis_spine = Line(10, window_height - 10, 10, 10);

    xticks = new Line[num_divisions];
    yticks = new Line[num_divisions];
}

Axis::~Axis()
{

}

float Axis::getxStart()
{
    return xstart;
}

float Axis::getxStop()
{
    return xstop;
}

float Axis::getyStart()
{
    return ystart;
}

float Axis::getyStop()
{
    return ystop;
}

float Axis::getNumDivisions()
{
    return num_divisions;
}   

Line Axis::getXaxisSpine()
{
    return xaxis_spine;
}

Line Axis::getYaxisSpine()
{
    return yaxis_spine;
}


Line* xticks()
{

}

Line* yticks()
{

}