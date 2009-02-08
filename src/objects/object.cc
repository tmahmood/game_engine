#include	"../resources.h"
#include	"object.h"
#include 	<stdio.h>

void Object::move(Direction dir, int amount)
{
	if(amount !=0)
	{
		int old_speed = speed;
		speed = amount;
		move_int(dir);		
		speed = old_speed;
		return;
	}
	
	move_int(dir);		
}

void Object::set_position(int x, int y)
{
	pos_x = x;
	pos_y = y;
}

void Object::set_speed(int spd)
{
	speed = spd;
}

int Object::get_current_speed()
{
	return speed;
}

Rectangle Object::get_rectangle()
{
	Rectangle t;
	t.x = pos_x;
	t.y = pos_y;
	t.width= width;
	t.height= height;
	return t;
}

void Object::move_int(Direction dir)
{
	switch(dir)
	{
		case Left:
			printf("Left %d\n", speed);
			pos_x-=speed;
			break;

		case Right:
			printf("Right %d\n", speed);
			pos_x+=speed;
			break;

		case Up:
			printf("Top %d\n", speed);
			pos_y-=speed;
			break;

		case Down:
			printf("Down %d\n", speed);
			pos_y+=speed;
			break;
	}
}

void Object::set_life(int val)
{
	life = val;
}

void Object::set_size(int w,int h)
{
	width = w;
	height = h;
}

void Object::set_damage(int val)
{
	damage = val;
}

void Object::set_level(int val)
{
	level = val;
}

void Object::set_obj_id(int id)
{
	obj_id = id;
}

void Object::set_direction(Direction dir)
{
	speed = 0;
	current_dir = dir;
}

Direction Object::get_direction()
{
	return current_dir;
}

int Object::get_life()
{
	return life;
}

int Object::get_width()
{
	return width;
}

int Object::get_height()
{
	return height;
}

int Object::get_damage()
{
	return damage;
}

int Object::get_level()
{
	return level;
}

int Object::get_obj_id()
{
	return obj_id;
}

int Object::get_pos_x()
{
	return pos_x;
}

int Object::get_pos_y()
{
	return pos_y;
}

