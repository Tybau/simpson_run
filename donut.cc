#include "donut.hh"

#include <SFML/Audio.hpp>
#include <iostream>

Donut::Donut(const Position &pos):Object(pos, "images/donut.png")
{
	if (!crocTex.loadFromFile("images/donut_croc.png"))
	    std::cerr << "Erreur de chargement de la texture!" << std::endl;
	if (!buffer.loadFromFile("sounds/miam.wav"))
		std::cerr << "Erreur de chargement du son!" << std::endl;
	sound.setBuffer(buffer);
}

void Donut::interact(Personnage &p)
{
	if(this->state)
	{
		p.addScore(1);
		this->state = false;
		sound.play();
	}
}

void Donut::draw(sf::RenderWindow &win)
{
	sf::Sprite sprite;
	if(this->state)
		sprite.setTexture(tex);
	else
		sprite.setTexture(crocTex);
	sprite.setPosition(pos.getVector());
	win.draw(sprite);
}
