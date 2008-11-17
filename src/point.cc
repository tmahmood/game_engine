/*
 * =====================================================================================
 *
 *       Filename:  point.cc
 *
 *    Description:  Main file for Point class
 *
 *        Version:  1.0
 *        Created:  11/17/2008 12:16:11 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Tarin Mahmood (tmn), mrlinux045@gmail.com
 *        Company:  tmnSoft
 *
 * =====================================================================================
 */

#include	"point.h"

void Point::set_position(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Point::get_x_position()
{
	return x;
}

int Point::get_y_position()
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

