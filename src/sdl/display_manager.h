#define Surface SDL_Surface
#define load_image IMG_Load
#define unload_image SDL_FreeSurface
#define Rectangle SDL_Rect
/*
 * This is the main surface where we will draw all the stuffs
 * There should be one and only one Display manager, 
 * */
class DisplayManager
{
	private:
		SDL_Surface *Display;
		int scr_width;
		int scr_height;
		int wbit;
		int wflag;
		Uint32 background_color;
			
	public:
		DisplayManager();
		DisplayManager(int,int,int,int);
		~DisplayManager();
		////////////////////////////////////
		bool init_display_manager(int, int, int, int, char *);
		void close_display_manager();
		void put_pixel(int , int , Uint32 );
		Uint8 get_pixel(int , int ); 
		////////////////////////////////////
		bool draw_image (SDL_Surface *, Point, Point, Point);
		bool draw_image (SDL_Surface *,int , int);
		void fill_rect (Uint32, SDL_Rect*);
		void fill_surface (Uint32);
		void redraw ();
		long get_ticks();

		SDL_PixelFormat *get_display_format ();
};
