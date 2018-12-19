#pragma once

#include <SFML/Graphics.hpp>

class State
{
public:
	bool KEY_Z;
	bool KEY_Q;
	bool KEY_S;
	bool KEY_D;
	bool KEY_SPACE;

	State() : KEY_Z(false), KEY_Q(false),
	KEY_S(false), KEY_D(false), KEY_SPACE(false) {};

	void update(sf::Event &event)
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Z)
				KEY_Z = true;
			if (event.key.code == sf::Keyboard::S)
		        KEY_S = true;
			if (event.key.code == sf::Keyboard::Q)
		        KEY_Q = true;
			if (event.key.code == sf::Keyboard::D)
		        KEY_D = true;
			if (event.key.code == sf::Keyboard::Space)
		        KEY_SPACE = true;
		}
		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::Z)
				KEY_Z = false;
			if (event.key.code == sf::Keyboard::S)
		        KEY_S = false;
			if (event.key.code == sf::Keyboard::Q)
		        KEY_Q = false;
			if (event.key.code == sf::Keyboard::D)
		        KEY_D = false;
			if (event.key.code == sf::Keyboard::Space)
		        KEY_SPACE = false;
		}
	}
};
