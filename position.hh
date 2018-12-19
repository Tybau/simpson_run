#pragma once

class Position
{
private:
	float x;
	float y;
public:
	Position() { x = 0; y = 0; };
	Position(float x, float y) { this->x = x; this->y = y; };
	void set(float x, float y) { this->x = x; this->y = y; };
	int getX() const { return x; };
	void setX(float x) { this->x = x; };
	int getY() const { return y; };
	void setY(float y) { this->y = y; };
};
