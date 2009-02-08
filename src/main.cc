#include 	"resources.h"

SDL_DM sdm;

int app_status;
int system_status = ALL_GOOD;
dictionary *game_ini;

int actor_count;
int name_index;

void init_game();
void init_system(char*);
void game_loop();
bool start_sdl();
void cleanup();
void sdl_event();

void clear_objects();
void on_escape();
void on_up();
void on_down();
void on_right();
void on_left();

LinkedList<SDL_Surface*, Image_node>image_list;
LinkedList<char*, String_node>string_list;
LinkedList<PyObject*, PyObject_node>pyobj_list;

Event events;
Object vc;
Timer main_timer;

int main (int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("Argument missing\n");
		exit(1);
	}

	init_system(argv[1]);
	game_loop();

	return EXIT_SUCCESS;
}

void init_system(char *game_name)
{	
	if(!start_sdl())
	{
		exit(DISPLAY_INIT_FAILED);
	}
	atexit(cleanup);
	clear_objects();

	String_helper::trim_right(game_name, '/');

	string_list.add(game_name);
	init_game();
	printf("Starting game loop\n");
}

void init_game()
{
	events.add_listener(SDLK_ESCAPE, on_escape);
	events.add_listener(SDL_QUIT, on_escape);
	events.add_listener(SDLK_UP, on_up);
	events.add_listener(SDLK_DOWN, on_down);
	events.add_listener(SDLK_LEFT, on_left);
	events.add_listener(SDLK_RIGHT, on_right);

	vc.set_size(64,64);
	vc.set_position(10,10);
	vc.set_speed(10);
	vc.set_obj_id(MISSILE_IMAGE);
}

void clear_objects()
{
	Uint32 colorkey = SDL_MapRGB(sdm.get_display_format(), 0, 0, 0); 

	Rectangle tr = vc.get_rectangle();
	sdm.fill_rect(colorkey, &tr);
}

bool start_sdl()
{
	sdm.set_screen_size(800, 800);
	return sdm.init_dm();
}

void game_loop()
{
	Uint32 colorkey = sdm.get_colorkey(233, 233, 233); 
	try
	{
		while(app_status!=S_EXIT)
		{
			clear_objects();
			events.get_key_pressed();
			Rectangle tr = vc.get_rectangle();
			sdm.fill_rect(colorkey, &tr);
			sdm.redraw();
		}
	}
	catch(int x)
	{
		printf("Exception cought %d\n", x);
	}
}


void cleanup()
{
	sdm.close_display_manager();
}

void on_escape()
{
	printf("Good bye!\n");
	app_status = S_EXIT;
}

void on_up()
{
	if(main_timer.is_started())
	{
		main_timer.stop();
		vc.set_direction(Up);
		return;
	}
	main_timer.start();
}

void on_down()
{
	if(main_timer.is_started())
	{
		main_timer.stop();
		vc.set_direction(Down);
		return;
	}
	main_timer.start();

}

void on_right()
{	
	if(main_timer.is_started())
	{
		main_timer.stop();
		vc.set_direction(Right);
		return;
	}
	main_timer.start();
}

void on_left()
{	
	if(main_timer.is_started())
	{
		main_timer.stop();
		vc.set_direction(Left);
		return;
	}
	main_timer.start();
}
