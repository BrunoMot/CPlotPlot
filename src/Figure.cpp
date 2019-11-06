#include "../inc/Figure.h"

Figure::Figure(float xstart, float xstop, float ystart, float ystop, int num_divisions, string name):
xstart(xstart),  xstop(xstop),  ystart(ystart),  ystop(ystop), num_divisions(num_divisions), name(name)
{
    int windowHeight = 6*sf::VideoMode::getDesktopMode().height/7 - 20;
    int windowWidth = 6*sf::VideoMode::getDesktopMode().height/7 - 20;

    ax = Axis(windowHeight,
              windowWidth,
              xstart, xstop, ystart, ystop, num_divisions);
}



Figure::~Figure()
{

}

void Figure::plot()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode(6*sf::VideoMode::getDesktopMode().height/7, 
                                6*sf::VideoMode::getDesktopMode().height/7 - 20), name);

    sf::Event event;
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
        // Draw spines
        window.draw(ax.getXaxisSpine().getLine());
        window.draw(ax.getYaxisSpine().getLine());
        // Draw ticks
        for (int i = 0; i < num_divisions; i++){
            window.draw(ax.getXticks()[i].getLine());
            window.draw(ax.getYticks()[i].getLine());
        }
        window.display();

    }
}

