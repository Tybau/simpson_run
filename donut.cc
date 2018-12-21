#include "donut.hh"

#include <iostream>

Donut::Donut(const Position &pos):Object(pos, "images/donut.png"), state(true)
{
	if (!crocTex.loadFromFile("images/donut_croc.png"))
	    std::cerr << "Erreur de chargement de la texture!" << std::endl;
}

void Donut::interact(Personnage &p)
{
	if(state)
	{
		p.addScore(1);
		state = false;
	}
	std::cout << "MIAM : " << p.getScore() << std::endl;
}

void Donut::draw(sf::RenderWindow &win)
{
	sf::Sprite sprite;
	if(state)
		sprite.setTexture(tex);
	else
		sprite.setTexture(crocTex);
	sprite.setPosition(pos.getVector());
	win.draw(sprite);
}
