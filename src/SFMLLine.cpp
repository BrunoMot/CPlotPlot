#include "../inc/SFMLLine.h"

Line::Line()
{
    startPoint = sf::Vector2f(0,0);
    endPoint = sf::Vector2f(0,0);
    thickness = 2.718;

    setLine();

}

Line::Line(float startPointX, float startPointY, float endPointX, float endPointY)
{
    thickness = 2.718;

    this->startPoint = sf::Vector2f(startPointX, startPointY);
    this->endPoint = sf::Vector2f(endPointX, endPointY);

    setLine();
}

Line::Line(float startPointX, float startPointY, float endPointX, float endPointY, float thickness):
thickness(thickness)
{
    this->startPoint = sf::Vector2f(startPointX, startPointY);
    this->endPoint = sf::Vector2f(endPointX, endPointY);

    setLine();
}

Line::~Line()
{

}

float Line::getThickness()
{
    return thickness;
}

sf::Vector2f Line::getStartPoint()
{
    return startPoint;
}

sf::Vector2f Line::getEndPoint()
{
    return endPoint;
}

sf::ConvexShape Line::getLine()
{
    return line;
}


void Line::setThickness(float thickness)
{
    this->thickness = thickness;
    setLine();
}

void Line::setStartPoint(sf::Vector2f startPoint)
{
    this->startPoint = startPoint;
    setLine();
}

void Line::setEndPoint(sf::Vector2f endPoint)
{
    this->endPoint = endPoint;
    setLine();

}

void Line::setLine()
{
    sf::Vector2f startdxp = sf::Vector2f(startPoint.x + thickness, startPoint.y);
    sf::Vector2f startdxn = sf::Vector2f(startPoint.x - thickness, startPoint.y);
    sf::Vector2f startdyp = sf::Vector2f(startPoint.x, startPoint.y  + thickness);
    sf::Vector2f startdyn = sf::Vector2f(startPoint.x, startPoint.y  - thickness);
    sf::Vector2f enddxp = sf::Vector2f(endPoint.x + thickness, endPoint.y);
    sf::Vector2f enddxn = sf::Vector2f(endPoint.x - thickness, endPoint.y);
    sf::Vector2f enddyp = sf::Vector2f(endPoint.x, endPoint.y - thickness);
    sf::Vector2f enddyn = sf::Vector2f(endPoint.x, endPoint.y - thickness);

    line = sf::ConvexShape(4);
    line.setFillColor(color);

    // Tilted points
    if (startPoint.y != endPoint.y && startPoint.x != endPoint.x)
    {
        line.setPoint(0, startPoint);
        line.setPoint(1, endPoint);
        line.setPoint(2, enddxp);
        line.setPoint(3, startdxp);
    }
    // Same horizontal points
    else if (startPoint.y == endPoint.y && startPoint.x != endPoint.x)
    {
        line.setPoint(0, startPoint);
        line.setPoint(1, startdyn);
        line.setPoint(2, enddyn);
        line.setPoint(3, endPoint);
    }
    // Same vertical points
    else if (startPoint.y != endPoint.y && startPoint.x == endPoint.x)
    {
        line.setPoint(0, startPoint);
        line.setPoint(1, endPoint);
        line.setPoint(2, enddxp);
        line.setPoint(3, startdxp);
    }
    
}
