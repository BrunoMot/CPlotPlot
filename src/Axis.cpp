#include "../inc/Axis.h"

Axis::Axis()
{
    xstart=xstop=ystart=ystop=num_divisions=0;
    xaxis_spine = Line(0, 0, 0, 0);
    yaxis_spine = Line(0, 0, 0, 0);
    
    xticks = new Line;
    yticks = new Line;
}

Axis::Axis(float window_height, float window_width, float xstart, float xstop,
           float ystart, float ystop, int num_divisions):
xstart(xstart), xstop(xstop), ystart(ystart), ystop(ystop), num_divisions(num_divisions), window_height(window_height),
window_width(window_width)
{
    int wallDist = 50;
    // Create spines wallDist points away from sides
    xaxis_spine = Line(wallDist, window_height - wallDist, window_width - wallDist, window_height - wallDist);
    yaxis_spine = Line(wallDist, window_height - wallDist, wallDist, wallDist);

    // Create ticks
    xticks = new Line[num_divisions];
    yticks = new Line[num_divisions];

    // Variables to help with tick positioning
    float tickLen = 5; // length of ticks
    float thickness = 3; // Thickness of ticks
    float xLen = (window_width - wallDist) - wallDist, // Length of x Spine
          yLen = wallDist - (window_height - wallDist), // Length of y Spine
          dx = xLen/num_divisions, // Ammout of space between each x tick
          dy = yLen/num_divisions, // Ammout of space between each y tick
          currX = wallDist, currY = window_height - wallDist; // Current x and y of xtick and ytick being created

    for(int i = 0; i < num_divisions; i++)
    {
        xticks[i] = Line(currX, window_height - wallDist, currX, window_height - wallDist + tickLen, thickness);
        yticks[i] = Line(wallDist - tickLen, currY, wallDist, currY, thickness);
        currX += dx;
        currY += dy;
    }
}

Axis::~Axis()
{   
    delete xticks;
    delete yticks;
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


Line* Axis::getXticks()
{
    return xticks;
}

Line* Axis::getYticks()
{
    return yticks;
}