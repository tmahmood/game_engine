#include<SDL/SDL.h>
#include "../point.h"
#include"sdl_dm.h"

SDL_DM::SDL_DM ()
{
	// default configuration
	scr_width	= 300;
	scr_height	= 300;
	wbit 		= 24;
	wflag 		= SDL_HWSURFACE|SDL_DOUBLEBUF;
}


SDL_PixelFormat* SDL_DM::get_display_format () 
{
	return Display->format;	
}

long SDL_DM::get_ticks () 
{
	return SDL_GetTicks();
}

void SDL_DM::set_screen_size(int sw, int sh)
{
	scr_width = sw;
	scr_height = sh;
}

void SDL_DM::set_display_flags(int flag)
{
	wflag = flag;
}

void SDL_DM::set_display_color_bit(int bit)
{
	wbit = bit;
}

bool SDL_DM::init_dm ()
{
	int sdl_status = SDL_Init(SDL_INIT_VIDEO);

	if(sdl_status<0)
	{ 
		return false;
	}

	Display = SDL_SetVideoMode( 	scr_width,
					scr_height, 
					wbit, wflag);

	if (!Display)
	{
		return false;
	}

	SDL_WM_SetCaption("A SDL Window","Icon");
	return true;
}

Uint8 SDL_DM::get_pixel (int x, int y)
{	
	int bpp = Display->format->BytesPerPixel;

	Uint8 *p = (Uint8 *)Display->pixels 
			+ y * Display->pitch 
			+ x * bpp;

	switch(bpp) 
	{
	case 1:
		return *p;

	case 2:
		return *(Uint16 *)p;

	case 3:
		if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
		{
			return p[0]<<16|p[1]<<8|p[2];
		}
		else
		{
			return p[0]|p[1]<<8|p[2]<<16;
		}

	case 4:
		return *(Uint32 *)p;

	default:
		return 0;
	}
}


void SDL_DM::put_pixel(int x, int y, Uint32 pixel)
{
	int bpp = Display->format->BytesPerPixel;
	Uint8 *p = (Uint8 *)Display->pixels 
			+ y * Display->pitch 
			+ x * bpp;

	switch(bpp) 
	{
	case 1:
		*p = pixel;
		break;

	case 2:
		*(Uint16 *)p = pixel;
		break;

	case 3:
		if(SDL_BYTEORDER == SDL_BIG_ENDIAN) 
		{
			p[0] = (pixel >> 16) & 0xff;
			p[1] = (pixel >> 8) & 0xff;
			p[2] = pixel & 0xff;
		} 
		else 
		{
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

bool SDL_DM::draw_image(SDL_Surface *image, int x, int y)
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

bool SDL_DM::copy_img_to(
			SDL_Surface *image, 
			Rectangle src, 
			Point destp)
{
	if (!image) 
	{		
		return false;
	} 

	Rectangle dest;
	dest.x = destp.x;
	dest.y = destp.y;
	dest.w = image->w;
	dest.h = image->h;

	SDL_BlitSurface(image, &src, Display, &dest);
	return true;
}

void SDL_DM::redraw ()
{
	SDL_Flip(Display);
}

void SDL_DM::fill_surface (Uint32 colorkey)
{
	SDL_FillRect(Display, NULL, colorkey);
}

void SDL_DM::fill_rect (Uint32 colorkey, SDL_Rect *rect)
{
	SDL_FillRect(Display, rect, colorkey);
}

void SDL_DM::close_display_manager()
{
	if(Display)
	{
		SDL_FreeSurface(Display);	
	}
	SDL_Quit();	
}

SDL_DM::~SDL_DM()
{
	close_display_manager();
}

