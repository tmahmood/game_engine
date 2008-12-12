#ifndef SDL_DM_H_

#define SDL_DM_H_

#include<SDL/SDL.h>
#include "../point.h"

#define Surface SDL_Surface
#define load_image IMG_Load
#define unload_image SDL_FreeSurface
#define Rectangle SDL_Rect

/*
 * This is the main surface where we will draw all the stuffs
 * There should be one and only one Display manager, 
 * */
class SDL_DM
{
	private:
		SDL_Surface *Display;
		int scr_width;
		int scr_height;
		int wbit;
		int wflag;
		Uint32 background_color;

	public:
		SDL_DM();
		~SDL_DM();

		void set_screen_size(int, int);
		void set_display_flags(int);
		void set_display_color_bit(int);

		bool init_dm();
		void close_display_manager();
		void redraw();


		bool copy_img_to(SDL_Surface*, Rectangle, Point);
		bool draw_image(SDL_Surface*, int, int);
		void fill_rect(Uint32, SDL_Rect*);
		void fill_surface(Uint32);

		long get_ticks();
		void put_pixel(int , int , Uint32 );
		Uint8 get_pixel(int , int ); 
		SDL_PixelFormat *get_display_format ();
};

#endif /* SDL_DM_H_ */

