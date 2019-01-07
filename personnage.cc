#include "personnage.hh"

#include <iostream>

#include "wall.hh"
#include "object.hh"

#define MAX_SPEED 8
#define INERTIE 2
#define REAL_SPEED (MAX_SPEED * INERTIE)
#define JUMP 0.45

Personnage::Personnage(const Position &pos, const std::string &texPath)
	: pos(pos), score(0)
{
	if (!tex.loadFromFile(texPath))
	    std::cerr << "Erreur de chargement de la texture!" << std::endl;
	grounded = false;
}

void Personnage::update(State &state, std::vector<Tile *> &tiles)
{
	// Augmenter la vitesse en fonction du clavier
	if (state.KEY_Q) // DROITE
        velocity.x -= 2;
	if (state.KEY_D) // GAUCHE
        velocity.x += 2;
	if (state.KEY_Z && grounded) // SAUT (si sur le sol)
	{
		grounded = false; // N'est plus sur le sol
		velocity.y -= REAL_SPEED * JUMP;
	}

	// Caper la vitesse
	if(velocity.x > REAL_SPEED) velocity.x = REAL_SPEED;
	if(velocity.x < -REAL_SPEED) velocity.x = -REAL_SPEED;

	// Ralentir le personnage (frottements)
	if(velocity.x > 0) velocity.x--;
	if(velocity.x < 0) velocity.x++;

	// Gravite
	if(!grounded)
		velocity.y += 1;

	// Appliquer le mouvement
	Position oldPos = Position(pos.getX(), pos.getY());
	pos += velocity / INERTIE;

	grounded = false;

	// Gérer les collisions
	for(auto& tile : tiles)
	{
		// Verifier si il y a du sol
		Position pInf = Position(pos.getX(), pos.getY() + REAL_SPEED);
		if(dynamic_cast<Wall *>(tile) && tile->collision(pInf))
			grounded = true;

		// Gerer les collision (mur et objets)
		if(tile->collision(pos))
		{
			if(dynamic_cast<Wall *>(tile))
			{
				pos.set(oldPos.getX(), oldPos.getY());
				velocity.x = 0;
				velocity.y = 0;
			}
			if(dynamic_cast<Object *>(tile))
			{
				Object *o = static_cast<Object *>(tile);
				o->interact(*this);
			}
		}
	}
}

void Personnage::draw(sf::RenderWindow &win)
{
	sf::Sprite sprite;
	sprite.setTexture(tex);
	sprite.setPosition(sf::Vector2f(pos.getX(), pos.getY()));
	win.draw(sprite);
}
