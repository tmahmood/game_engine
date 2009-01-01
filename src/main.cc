#include	<stdio.h>
#include	<stdlib.h>
#include	"mem_manager/llist.h"
#include	"sdl/sdl_dm.h"

#define	DISPLAY_INIT_FAILED 100
#define	ALL_GOOD 0

SDL_DM sdm;
int system_status = ALL_GOOD;

void init_system();
bool start_sdl();
void cleanup();

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
	sdm.set_screen_size(640, 480);
	if(!sdm.init_dm())
	{
		return false;
	}
	return true;
}

void cleanup()
{
	sdm.close_display_manager();
}


