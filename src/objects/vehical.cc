#include "vehical.h"
#include <stdio.h>

void Vehical::move(Direction dir)
{
	if(current_dir != dir)
	{
		current_dir = dir;
		speed = 0;
		return;
	}
	
	if(speed == top_speed)
	{
		return;
	}

	speed += accel;
	move_int(dir);
}

int Vehical::get_accelaration()
{
	return accel;
}

int Vehical::get_top_speed()
{
	return top_speed;
}


