#include "../resources.h"

Event::Event()
{
	for( int i = 0; i < MAX_KEYS; i += 1)
	{
		events_set[i] = false;
	} 
}

void Event::call_function(void (*func_name)())
{
	func_name();

}

void Event::add_listener(int key_code, Fx func)
{
	listeners[key_code] = func;
	events_set[key_code] = true;
}

void Event::get_key_pressed()
{
	SDL_Event event;
	int sym;
	SDL_WaitEvent(&event);
	switch (event.type) 
	{
		case SDL_KEYDOWN:
		case SDL_KEYUP:
			sym = event.key.keysym.sym;
			if(events_set[sym])
			{
				call_function(listeners[sym]);
			}
			break;

		case SDL_QUIT:
			call_function(listeners[event.type]);
			break;
	}
}

bool Event::get_key_state(int key_code)
{
	Uint8 *key_state = SDL_GetKeyState(NULL);
	return key_state[key_code];
}
