
bool Graphics::draw_image(SDL_Surface *image, int x, int y)
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

bool Graphics::copy_img_to( SDL_Surface *image, SDL_Rect src, Point destp)
{
	if (!image) 
	{		
		return false;
	} 

	SDL_Rect dest;
	dest.x = destp.x;
	dest.y = destp.y;
	dest.w = image->w;
	dest.h = image->h;

	SDL_BlitSurface(image, &src, Display, &dest);
	return true;
}


void Graphics::fill_surface (Uint32 colorkey)
{
	SDL_FillRect(Display, NULL, colorkey);
}

void Graphics::fill_rect (Uint32 colorkey, SDL_Rect *rect)
{
	SDL_FillRect(Display, rect, colorkey);
}

void Graphics::fill_rect (Uint32 colorkey, Rectangle *rect)
{
	SDL_Rect sr;
	sr.x = rect->x;
	sr.y = rect->y;
	sr.w = rect->width;
	sr.h = rect->height;

	SDL_FillRect(Display, &sr, colorkey);
}

Uint32 Graphics::get_colorkey(int r, int g, int b)
{
	return SDL_MapRGB(get_display_format(), r, g , b); 
}

void Graphics::put_pixel(int x, int y, Uint32 pixel)
{
	int bpp = Display->format->BytesPerPixel;
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


