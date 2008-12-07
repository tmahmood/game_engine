#include<SDL/SDL.h>
#include"all_structs.h"
#include"display_manager.h"

DisplayManager::DisplayManager ()
{
	// default configuration
	scr_width	= 300;
	scr_height	= 300;
	wbit 		= 16;
	wflag 		= SDL_HWSURFACE|SDL_DOUBLEBUF;
}

DisplayManager::DisplayManager (int sw, int sh, int bit, int flag)
{
	// default configuration
	scr_width	= sw;
	scr_height	= sh;
	wbit 		= bit;
	wflag 		= flag;
}

SDL_PixelFormat *DisplayManager::get_display_format ()
{
	return Display->format;	
}

long DisplayManager::get_ticks ()
{
	return SDL_GetTicks();
}

bool DisplayManager::init_display_manager (int sw, int sh, int bit, int flag, char *window_title)
{
	scr_width	= sw;
	scr_height	= sh;
	wbit 		= bit;
	wflag 		= flag;

	int sdl_status = SDL_Init(SDL_INIT_VIDEO);

	printf ("[i] SDL Initialized\n");

	if(sdl_status<0)
	{ 
		printf("[e] Error Occurred\n");
		return false;
	}

	Display = SDL_SetVideoMode(scr_width, scr_height, wbit, wflag);

	printf ("[i] Video Mode set to %dx%d with %d bit color\n", scr_width, scr_height, wbit);


	if (!Display)
	{
		printf ("[e] Error Occurred");
		return false;
	}

	printf ("[i] Display Initialized\n");

	SDL_WM_SetCaption("A SDL Window","Icon");
	return true;
}

Uint8 DisplayManager::get_pixel (int x, int y)
{	
	int bpp = Display->format->BytesPerPixel;
	/* Here p is the address to the pixel we want to retrieve */
	Uint8 *p = (Uint8 *)Display->pixels + y * Display->pitch + x * bpp;

	switch(bpp) {
		case 1:
			return *p;

		case 2:
			return *(Uint16 *)p;

		case 3:
			if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
				return p[0] << 16 | p[1] << 8 | p[2];
			else
				return p[0] | p[1] << 8 | p[2] << 16;

		case 4:
			return *(Uint32 *)p;

		default:
			return 0;       /* shouldn't happen, but avoids warnings */
	}
}


void DisplayManager::put_pixel(int x, int y, Uint32 pixel)
{
	int bpp = Display->format->BytesPerPixel;
	/* Here p is the address to the pixel we want to set */
	Uint8 *p = (Uint8 *)Display->pixels + y * Display->pitch + x * bpp;

	switch(bpp) 
	{
		case 1:
			*p = pixel;
			break;

		case 2:
			*(Uint16 *)p = pixel;
			break;

		case 3:
			if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
				p[0] = (pixel >> 16) & 0xff;
				p[1] = (pixel >> 8) & 0xff;
				p[2] = pixel & 0xff;
			} else {
				p[0] = pixel & 0xff;
				p[1] = (pixel >> 8) & 0xff;
				p[2] = (pixel >> 16) & 0xff;
			}
			break;

		case 4:
			*(Uint32 *)p = pixel;
			break;
	}
}

bool DisplayManager::draw_image(SDL_Surface *image, int x, int y)
{
	SDL_Rect DestR, SrcR;
	if (!image) 
	{		
		return false;
	} 

	SrcR.x = 0;
	SrcR.y = 0;
	SrcR.w = image->w;
	SrcR.h = image->h;

	DestR.x = x;
	DestR.y = y;
	DestR.w = image->w;
	DestR.h = image->h;

	SDL_BlitSurface(image, &SrcR, Display, &DestR);
	return true;

}

bool DisplayManager::draw_image (SDL_Surface *image, Point Src, Point Dest, Point size)
{
	SDL_Rect DestR, SrcR;
	if (!image) 
	{		
		return false;
	} 

	SrcR.x = Src.x;
	SrcR.y = Src.y;
	SrcR.w = size.x;
	SrcR.h = size.y;

	DestR.x = Dest.x;
	DestR.y = Dest.y;
	DestR.w = size.x;
	DestR.h = size.y;

	SDL_BlitSurface(image, &SrcR, Display, &DestR);
	return true;
}

void DisplayManager::redraw ()
{
	SDL_Flip(Display);
}

void DisplayManager::fill_surface (Uint32 colorkey)
{
	SDL_FillRect(Display, NULL, colorkey);
}

void DisplayManager::fill_rect (Uint32 colorkey, SDL_Rect *rect)
{
	SDL_FillRect(Display, rect, colorkey);
}

void DisplayManager::close_display_manager()
{
	printf ("[i] Shuting down SDL ...\n");

	if(Display)
	{
		SDL_FreeSurface(Display);	
	}
	SDL_Quit();	

	printf ("[i] SDL closed\n");

}

DisplayManager::~DisplayManager()
{
	close_display_manager();
}

