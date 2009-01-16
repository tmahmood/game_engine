#include "object.h"

class Vehical : public Object
{
	private:
		int accel;
		int top_speed;

	public:
		void move(Direction)
		int get_accelaration();
		int get_top_speed();
		
};
