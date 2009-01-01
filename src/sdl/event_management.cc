/*
 * =====================================================================================
 *
 *       Filename:  event_management.cc
 *
 *    Description:  Implementation of Event_manager class
 *
 *        Version:  1.0
 *        Created:  01/01/2009 03:00:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Tarin Mahmood (tmn), mrlinux045@gmail.com
 *        Company:  tmnSoft
 *
 * =====================================================================================
 */

#include <SDL/sdl.h>
void on_key_down()
{
	int Sym = Event.key.keysym.sym;
	switch (Sym)
	{
		case SDLK_ESCAPE:
			break;

		case SDLK_LEFT:
			break;

		case SDLK_RIGHT:
			break;

		case SDLK_UP:
			break;


	}
	break;

}

void sdl_event()
{
	SDL_Event Event;
	int status;

	while (SDL_PollEvent(&Event))
	{
		switch (Event.type)
		{
			case SDL_QUIT:
				break;

			case SDL_KEYDOWN: //A key has been pressed
				on_key_down();
				break;
		}
	}
}
