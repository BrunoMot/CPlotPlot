#include "../inc/Figure.h"

Figure::Figure(float xstart, float xstop, float ystart, float ystop, int num_divisions):
xstart(xstart),  xstop(xstop),  ystart(ystart),  ystop(ystop), num_divisions(num_divisions)
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
                                6*sf::VideoMode::getDesktopMode().height/7 - 20), "Teste");

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
        window.draw(ax.getXaxisSpine().getLine());
        window.draw(ax.getYaxisSpine().getLine());
        window.display();

    }
}

