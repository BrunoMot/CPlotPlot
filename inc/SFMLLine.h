#ifndef SFMLLINE_H
#define SFMLLINE_H

#include <SFML/Graphics.hpp>

class Line{
public:
    Line();
    Line(float startPointX, float startPointY, float endPointX, float endPointY);
    Line(float startPointX, float startPointY, float endPointX, float endPointY, float thickness);
    ~Line();

    float getThickness(); // Returns thickness of line
    sf::Vector2f getStartPoint(); // Returns a sfml vector with the start point of the line
    sf::Vector2f getEndPoint(); // Returns a sfml vector with the end point of the line
    sf::ConvexShape getLine(); // Returns the line for drawing
    
    void setThickness(float thickness);
    void setStartPoint(sf::Vector2f startPoint);
    void setEndPoint(sf::Vector2f endPoint);

private:
    float thickness;
    sf::Vector2f startPoint;
    sf::Vector2f endPoint;
    sf::ConvexShape line;
    sf::Color color = sf::Color::Black; // Color of the line

    void setLine(); // Uses sfml functions to set the properties of the sf::ConvexShape line
};

#endif