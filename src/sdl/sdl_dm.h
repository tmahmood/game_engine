#ifndef SDL_DM_H_

#define SDL_DM_H_

#include<SDL/SDL.h>
#include "../point.h"

#define Surface SDL_Surface
#define load_image IMG_Load
#define unload_image SDL_FreeSurface
#define Rectangle SDL_Rect

class SDL_DM
{
	private:
		SDL_Surface *Display;
		int scr_width;
		int scr_height;
		int wbit;
		int wflag;
		Uint32 background_color;
		bool initialized;

	public:
		SDL_DM();
		~SDL_DM();

		bool is_initialized();

		void set_screen_size(int, int);
		void set_display_flags(int);
		void set_display_color_bit(int);

		bool init_dm();
		void close_display_manager();
		void redraw();

		bool copy_img_to(SDL_Surface*, Rectangle, Point);
		bool draw_image(SDL_Surface *image, int x=0, int y=0);
		void fill_rect(Uint32, SDL_Rect*);
		void fill_surface(Uint32);

		long get_ticks();
		void put_pixel(int , int , Uint32 );
		Uint8 get_pixel(int , int ); 
		SDL_PixelFormat *get_display_format ();
		Uint32 get_colorkey(int , int , int );
};

#endif /* SDL_DM_H_ */

