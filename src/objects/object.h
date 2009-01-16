#ifndef OBJECT_H_

#define OBJECT_H_
#include	"../resources.h"

class Object
{
	public:

	void set_life(int);
	void set_size(int,int);
	void set_damage(int);
	void set_level(int);
	void set_obj_id(int);

	int get_life();
	int get_width();
	int get_height();
	int get_damage();
	int get_level();
	int get_obj_id();
	int get_pos_x();
	int get_pos_y();

	virtual void move(Direction);

	protected:
	int obj_id;
	int life;
	int width;
	int height;
	int damage;
	int level;
	Direction current_dir;

	int speed;

	int pos_x;
	int pos_y;

	void move_int (Direction);
};

#endif /* SRC/OBJECTS/OBJECT_H_ */


