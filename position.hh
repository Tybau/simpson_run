#pragma once

class Position
{
private:
	int x;
	int y;
public:
	Position() { x = 0; y = 0; };
	Position(int x, int y) { this->x = x; this->y = y; };
	void set(int x, int y) { this->x = x; this->y = y; };
	int getX() const { return x; };
	void setX(int x) { this->x = x; };
	int getY() const { return y; };
	void setY(int y) { this->y = y; };
};
