#ifndef EVENT_H_

#define EVENT_H_

#include 	"../resources.h"

#define MAX_KEYS 512

class Event
{
	protected:
	Fx listeners[MAX_KEYS];
	bool events_set[MAX_KEYS];
	void call_function(void(*)());

	public:
	Event();
	void add_listener(int, Fx);
	bool get_key_state(int);
	void get_key_pressed();
};



#endif /* SRC/SDL/EVENT_H_ */


