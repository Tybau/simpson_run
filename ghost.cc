#include "ghost.hh"

#include <iostream>

#include "wall.hh"
#include "object.hh"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define DROITE 0
#define GAUCHE 1
#define HAUT 2
#define BAS 3

#define MAX_SPEED 1
#define INERTIE 1
#define REAL_SPEED (MAX_SPEED * INERTIE)

void Ghost::update(const State &state, const std::vector<Tile *> &tiles)
{
	if(!active) return;

	// Modifier les deplacements
	if (dir == DROITE)
        velocity.x = 2;
	if (dir == GAUCHE)
        velocity.x = -2;
	if (dir == HAUT)
        velocity.y = -2;
	if (dir == BAS)
        velocity.y = 2;

	// Gerer les collisions avec l'ecran
	if(dir == DROITE && pos.getX() >= SCREEN_WIDTH - TILE_SIZE) dir = GAUCHE;
	else if(dir == GAUCHE && pos.getX() <= 0) dir = DROITE;
	else if(dir == BAS && pos.getY() >= SCREEN_HEIGHT - TILE_SIZE) dir = HAUT;
	else if(dir == HAUT && pos.getY() <= 0) dir = BAS;

	// Appliquer le mouvement
	Position oldPos = Position(pos.getX(), pos.getY());
	pos += velocity;

	// Gérer les collisions
	applyCollisions(tiles, oldPos);  // Traverser les mures ?
}

void Ghost::applyCollisions(const std::vector<Tile *> &tiles, const Position oldPos)
{
	for(auto& tile : tiles)
	{
		// Gerer les collision (mur et objets)
		if(tile->collision(pos))
		{
			if(dynamic_cast<Wall *>(tile))
			{
				pos.set(oldPos.getX(), oldPos.getY());

				// Gerer les collisions avec l'ecran
				if(dir == DROITE) dir = GAUCHE;
				else if(dir == GAUCHE) dir = DROITE;
				else if(dir == BAS) dir = HAUT;
				else if(dir == HAUT) dir = BAS;
			}
			if(dynamic_cast<Object *>(tile))
			{
				Object *o = static_cast<Object *>(tile);
				o->interact(*this);
			}
		}
	}
}

void Ghost::draw(sf::RenderWindow &win)
{
	if(!active) return;

	sf::Sprite sprite;
	sprite.setTexture(tex);
	sprite.setPosition(sf::Vector2f(pos.getX(), pos.getY()));
	win.draw(sprite);
}

void Ghost::collide(Player &player)
{
	float pX = player.getPosition().getX();
	float pY = player.getPosition().getY();

	float tX = pos.getX();
	float tY = pos.getY();

	if (active && pX + 50 > tX && pX < tX + 50 && pY + 50 > tY && pY < tY + 50)
	{
		player.addScore(-2);
		active = false;
	}
}
