#include	<stdio.h>
#include	<stdlib.h>

#include	"mem_manager/llist.h"
#include	"sdl/sdl_dm.h"
#include	"sdl/image.h"

#include	<SDL/SDL_image.h>

#define	DISPLAY_INIT_FAILED 100
#define	ALL_GOOD 0

#define BKGROUND_IMAGE 1001
#define ROCKET_IMAGE 1002
#define MISSILE_IMAGE 1003
#define PLANET_1 1005
#define PLANET_2 1006
#define PLANET_3 1007
#define PLANET_4 1008


SDL_DM sdm;
int system_status = ALL_GOOD;

void init_system();
bool start_sdl();
void cleanup();
void draw_test_image();

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
	image_list.add(IMG_Load("background.png"), BKGROUND_IMAGE);
	image_list.add(IMG_Load("rocket.png"), ROCKET_IMAGE);
	image_list.add(IMG_Load("missile.png"), MISSILE_IMAGE);

	image_list.add(IMG_Load("31.png"), PLANET_1);
	image_list.add(IMG_Load("32.png"), PLANET_2);
	image_list.add(IMG_Load("33.png"), PLANET_3);
	image_list.add(IMG_Load("34.png"), PLANET_4);

	sdm.draw_image(image_list.get(BKGROUND_IMAGE));
	sdm.draw_image(image_list.get(ROCKET_IMAGE), 128,128);
	sdm.draw_image(image_list.get(MISSILE_IMAGE), 438,128);

	sdm.draw_image(image_list.get(PLANET_1), 23, 32);
	sdm.draw_image(image_list.get(PLANET_2), 560,560);
	sdm.draw_image(image_list.get(PLANET_3), 600,100);

	sdm.redraw();
}

void cleanup()
{
	sdm.close_display_manager();
}


