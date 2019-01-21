#include <SFML/Graphics.hpp>

#include "tile.hh"
#include "game.hh"
#include "state.hh"

int main()
{
    sf::RenderWindow window(sf::VideoMode(DISPLAY_WIDTH, DESPLAY_HEIGHT), "Simpson run");
    /*sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);*/

	Game game = Game();
	State state = State();

	sf::Clock clock;

    while (window.isOpen())
    {
		sf::Time elapsed = clock.getElapsedTime();

		// Pour ne pas refresh trop vite (60Hz)
		if(elapsed.asMilliseconds() > 1000 / 60)
		{
			clock.restart();

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
    }

    return 0;
}
