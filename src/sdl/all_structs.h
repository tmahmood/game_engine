///////////////////////////////////////////
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define WBIT 16
#define DEFAULT_SCREEN SDL_HWSURFACE|SDL_DOUBLEBUF
////////////////
enum Directions 
{ 
	LEFT, 
	RIGHT, 
	UP, 
	DOWN 
};
/////////////
struct Point
{
	int x;
	int y;
};

