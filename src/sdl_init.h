class SDL_Manager
{
	public:
	SDL_Manager ( int, int );
	void set_bpp(int);
	virtual ~SDL_Manager();


	private:
	int height;
	int width;
	int bpp;
	
};

