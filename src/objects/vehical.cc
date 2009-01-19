#include "vehical.h"
#include <stdio.h>

void Vehical::move(Direction dir)
{
	move_int(dir);
}

int Vehical::get_top_speed()
{
	return top_speed;
}

void Vehical::set_top_speed(int ts)
{
	top_speed = ts;
}
