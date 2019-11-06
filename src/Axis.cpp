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
    // Create spines 10 points away from sides
    xaxis_spine = Line(10, window_height - 10, window_width - 10, window_height - 10);
    yaxis_spine = Line(10, window_height - 10, 10, 10);

    // Create ticks
    xticks = new Line[num_divisions];
    yticks = new Line[num_divisions];

    // Variables to help with tick positioning
    float tickLen = 5; // length of ticks
    float xLen = (window_width - 10) - 10, // Length of x Spine
          yLen = (window_height - 10) - 10, // Length of y Spine
          dx = xLen/num_divisions + 1, // Ammout of space between each x tick
          dy = yLen/num_divisions + 1, // Ammout of space between each y tick
          currX = 10, currY = window_height - 10; // Current x and y of xtick and ytick being created

    for(int i = 0; i < num_divisions; i++)
    {
        xticks[i] = Line(currX, window_height - 10, currX, window_height - 10 + tickLen);
        yticks[i] = Line(10, currY, 10 - tickLen, currY);
        currX += dx;
        currY += dy;
    }
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


Line* Axis::getXticks()
{
    return xticks;
}

Line* Axis::getYticks()
{
    return yticks;
}