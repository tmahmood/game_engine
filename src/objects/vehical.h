#include "object.h"

class Vehical : public Object
{
	private:
		int top_speed;

	public:
		void set_top_speed(int);
		void move(Direction);
		int get_top_speed();
};
