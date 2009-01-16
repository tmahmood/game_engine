#include	<stdio.h>
#include	<stdlib.h>
#include	<SDL/SDL_image.h>

#include 	"resources.h"

#include	"mem_manager/llist.h"
#include	"sdl/sdl_dm.h"
#include	"sdl/image.h"




int status;
SDL_DM sdm;
int system_status = ALL_GOOD;

void init_system();
bool start_sdl();
void cleanup();
void draw_test_image();
void on_key_down();
void sdl_event();

void move_up();
void move_down();
void move_left();
void move_right();

LinkedList<SDL_Surface*, Image_node>image_list;

int main ( int argc, char *argv[] )
{
	init_system();
	return EXIT_SUCCESS;
}


void init_system()
{	
	if(!start_sdl())
	{
		exit(DISPLAY_INIT_FAILED);
	}
	atexit(cleanup);
}

bool start_sdl()
{
	sdm.set_screen_size(800, 800);
	if(!sdm.init_dm())
	{
		return false;
	}
	draw_test_image();
	scanf("%*c");
	return true;
}

void draw_test_image()
{
	image_list.add(IMG_Load("missile.png"), MISSILE_IMAGE);
	sdm.draw_image(image_list.get(MISSILE_IMAGE), 438,128);
	sdm.redraw();
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
				status = S_EXIT;
				break;

			case SDL_KEYDOWN: //A key has been pressed
				int Sym = Event.key.keysym.sym;
				switch (Sym)
				{
					case SDLK_ESCAPE:
						status = S_EXIT;
						break;

					case SDLK_LEFT:
						move_left();
						break;

					case SDLK_RIGHT:
						move_right();
						break;

					case SDLK_UP:
						move_up();
						break;

					case SDLK_DOWN:
						move_down();
						break;
				}
				break;
		}
	}
}

void move_up()
{
}

void move_down()
{
}

void move_left()
{
}

void move_right()
{
}

