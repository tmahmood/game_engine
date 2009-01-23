#include	<stdio.h>
#include	<stdlib.h>
#include	<SDL/SDL_image.h>

#include 	"resources.h"

#include	"mem_manager/llist.h"
#include	"sdl/sdl_dm.h"
#include	"sdl/image.h"
#include	"objects/vehical.h"
#include	"mem_manager/string_node.h"
#include	"helpers/file_helper.h"
#include 	"helpers/string_tokenizer.h"
#include 	"ini_parser/iniparser.h"

SDL_DM sdm;

int app_status;
int system_status = ALL_GOOD;

void init_system(char*);
void game_loop();
bool start_sdl();
void cleanup();
void on_key_down();
void sdl_event();
void get_keyboard_event(SDL_Event);

void get_key_down();
void move_up();
void move_down();
void move_left();
void move_right();
void clear_screen();
void set_human();

LinkedList<SDL_Surface*, Image_node>image_list;
LinkedList<char*, String_node>string_list;
Vehical vc;

int main (int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("Argument missing\n");
		exit(1);
	}

	try
	{
		string_list.add((char*)"hello");
		char *t = string_list.get_current();

		char *n = String_helper::add_string(t, (char*)" world");
		string_list.add(n);
	}
	catch(int ex)
	{
		printf("%d\n", ex);
	}

	/*
	init_system(argv[1]);
	game_loop();
	*/
	return EXIT_SUCCESS;
}

void init_game()
{
	try
	{
		char *gpath = string_list.get(1);
		printf("TEST\n");

		string_list.add(gpath, 1001);
		printf("%s", string_list.get(1001));

		string_list.add(strcat(gpath, "/game.ini"));
		printf("%s", string_list.get_current());

		string_list.add(gpath, 1001);
		string_list.add(strcat(gpath, "/missile.png"));
		printf("%s", string_list.get(1001));

		printf("TEST\n");

		for(string_list.rewind(); string_list.is_valid() ;string_list.next())
		{
			printf("%s\n", string_list.get_current());
		}
	}
	catch (int x)
	{
		switch(x)
		{
			case STRING_COPY_EXCEPTION:
				printf("Failed to copy string\n");
				break;
			default:
				printf("Unknown Error code\n");
		}
		exit(1);
	}
	//
	//iniparser_load();
	//image_list.add(IMG_Load(mpath), MISSILE_IMAGE);

	vc.set_obj_id(MISSILE_IMAGE);
	vc.set_life(100);
	vc.set_size(64, 86);
	vc.set_damage(10);
	vc.set_level(0);
	vc.set_position(100,100);
	vc.set_speed(2);
	vc.set_top_speed(20);
}

void init_system(char *game_name)
{	
	if(!start_sdl())
	{
		exit(DISPLAY_INIT_FAILED);
	}
	atexit(cleanup);
	clear_screen();

	string_list.add(game_name);
	init_game();
	
}

void clear_screen()
{
	Uint32 colorkey = SDL_MapRGB(sdm.get_display_format(), 0, 0, 0); 

	SDL_Rect rect;
	rect.x = vc.get_pos_x();
	rect.y = vc.get_pos_y();
	rect.w = vc.get_width();
	rect.h = vc.get_height();

	sdm.fill_rect(colorkey, &rect);
}

bool start_sdl()
{
	sdm.set_screen_size(800, 800);
	return sdm.init_dm();
}

void game_loop()
{
	try
	{
		while(app_status!=S_EXIT)
		{
			clear_screen();
			sdl_event();
			sdm.draw_image(image_list.get(MISSILE_IMAGE), vc.get_pos_x(),vc.get_pos_y());
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

void sdl_event()
{
	SDL_Event Event;
	while (SDL_PollEvent(&Event))
	{
		switch (Event.type)
		{
			case SDL_QUIT:
				app_status = S_EXIT;
				break;

			case SDL_KEYDOWN: //A key has been pressed
				get_keyboard_event(Event);
				break;

			case SDL_KEYUP:
				break;
		}
	}
	get_key_down();
}

void get_key_down()
{
	Uint8 *keystates = SDL_GetKeyState( NULL ); 
        if( keystates[ SDLK_UP ] )
        {
		vc.move(Up);
        }
        if( keystates[ SDLK_DOWN ] )
        {
		vc.move(Down);
        }
        if( keystates[ SDLK_LEFT ] )
        {
		vc.move(Left);
        }
        if( keystates[ SDLK_RIGHT ] )
        {
		vc.move(Right);
        }
}

void get_keyboard_event(SDL_Event Event)
{
	int Sym = Event.key.keysym.sym;
	switch (Sym)
	{
		case SDLK_ESCAPE: 
			app_status = S_EXIT; break; 

		case SDLK_LEFT:
			 move_left(); break; 

		case SDLK_RIGHT: 
			move_right(); break; 

		case SDLK_UP: 
			move_up(); break; 

		case SDLK_DOWN: 
			move_down(); break;
	}
}

void move_up()
{
	vc.move(Up);
}

void move_down()
{
	vc.move(Down);
}

void move_left()
{
	vc.move(Left);
}

void move_right()
{
	vc.move(Right);
}


