#include <SFML/Graphics.hpp>

#include "tile.hh"
#include "game.hh"
#include "state.hh"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Simpson run");
    /*sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);*/

	Game game = Game();
	State state = State();

    while (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			state.update(event);
		}

		game.update(state);

        window.clear();
        //window.draw(shape);
		game.draw(window);
        window.display();
    }

    return 0;
}
