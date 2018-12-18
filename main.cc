#include <SFML/Graphics.hpp>

#include "tile.hh"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Simpson run");
    /*sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);*/

	Position pos(50, 100);
	Tile tile(pos, "images/wall.jpg");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //window.draw(shape);
		tile.draw(window);
        window.display();
    }

    return 0;
}
