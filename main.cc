#include <SFML/Graphics.hpp>

#include "tile.hh"
#include "game.hh"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Simpson run");
    /*sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);*/

	Game game = Game();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

		game.update();

        window.clear();
        //window.draw(shape);
		game.draw(window);
        window.display();
    }

    return 0;
}
