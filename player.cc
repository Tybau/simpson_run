#include "player.hh"

#include <iostream>

#include "wall.hh"
#include "object.hh"

#define MAX_SPEED 8
#define INERTIE 2
#define REAL_SPEED (MAX_SPEED * INERTIE)
#define JUMP 0.75

void Player::update(const State &state, const std::vector<Tile *> &tiles)
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

	// Gérer les collisions
	applyCollisions(tiles, oldPos);
}

void Player::applyCollisions(const std::vector<Tile *> &tiles, const Position oldPos)
{
	// Reset grounded
	grounded = false;

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

void Player::draw(sf::RenderWindow &win)
{
	sf::Sprite sprite;
	sprite.setTexture(tex);
	sprite.setPosition(sf::Vector2f(pos.getX(), pos.getY()));
	win.draw(sprite);
}

void Player::addScore(const int &s)
{
	score += s;
	if(score < 0)
		score = 0;
}
