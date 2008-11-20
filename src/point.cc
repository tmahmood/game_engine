#include	"point.h"

void Point::set_position(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Point::get_x()
{
	return x;
}

int Point::get_y()
{
	return y;
}

void Point::move_left(int amount)
{
	x -= amount;
}

void Point::move_right(int amount)
{
	x += amount;
}

void Point::move_up(int amount)
{
	y-= amount;
}

void Point::move_down(int amount)
{
	y+= amount;
}

