#include	"../resources.h"
#include	"object.h"
#include 	<stdio.h>

void Object::move(Direction dir)
{
	move_int(dir);		
}

void Object::move_int(Direction dir)
{
	switch(dir)
	{
		case Left:
			printf("Left\n");
			pos_x-=speed;
			break;

		case Right:
			printf("Right\n");
			pos_x+=speed;
			break;

		case Up:
			printf("Top\n");
			pos_y+=speed;
			break;

		case Down:
			printf("Down\n");
			pos_y-=speed;
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


