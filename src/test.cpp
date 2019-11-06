
#include <iostream>
#include <SFML/Graphics.hpp>

#include "../inc/SFMLLine.h"

int main()
{

    sf::RenderWindow window;
    window.create(sf::VideoMode(6*sf::VideoMode::getDesktopMode().height/7, 
                                6*sf::VideoMode::getDesktopMode().height/7 - 20), "Teste");


    sf::Event event;

    float wx = window.getSize().x;
    float wy = window.getSize().y;

    sf::Font garamond;

    if( ! garamond.loadFromFile("data/Garamond.ttf"))
    {
        std::cout << "Error loading font from file" << std::endl;
    }

    Line line1 = Line(50, wy - 50, 50, 50);
    Line line2 = Line(50, wy - 50, wx - 50, wy - 50);

    sf::Text t1;
    t1.setFillColor(sf::Color::Black);
    t1.setFont(garamond);
    t1.setOrigin(- 35, - wy + 50);
    t1.setString("O");
    t1.setCharacterSize(20);
    // for com t1 e draw(t1) antes do display



    while (window.isOpen())
    {
        // Handle events
        while(window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                window.close();
                break;
            default:
                break;
            }
        }
        window.clear(sf::Color::White);
        window.draw(line1.getLine());        
        window.draw(line2.getLine());        
        window.draw(t1);        
        window.display();


    } 


    return 0;
}
