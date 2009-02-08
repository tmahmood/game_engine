class Graphics
{
	public:
		Graphics ( );
		virtual ~Graphics();

		bool copy_img_to(SDL_Surface*, SDL_Rect, Point);
		bool draw_image(SDL_Surface *image, int x=0, int y=0);
		void fill_rect(Uint32, SDL_Rect*);
		void fill_rect(Uint32, Rectangle*);
		void fill_surface(Uint32);
		void put_pixel(int , int , Uint32 );
		Uint8 get_pixel(int , int ); 
		Uint32 get_colorkey(int , int , int );


	private:

};

