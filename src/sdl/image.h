/*
 * =====================================================================================
 *
 *       Filename:  image.h
 *
 *    Description:  image class to use as node in LinkedList
 *
 *        Version:  1.0
 *        Created:  01/01/2009 02:04:08 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Tarin Mahmood (tmn), mrlinux045@gmail.com
 *        Company:  tmnSoft
 *
 * =====================================================================================
 */


#include<SDL/SDL_image.h>
#include	"../mem_manager/llist.h"

class Image_node
{
	SDL_Surface *data;
	public:
		Image_node *next;
		Image_node *prev;
		int index;

		void set_data(SDL_Surface *d)
		{
			data = d;
		}	

		SDL_Surface* get_data()
		{
			return data;
		}

		~Image_node()
		{
			if(data!=NULL)
			{
				printf("Deleting Image %d:    ", index);
				delete data;				
				printf("DONE\n");
			}
		}

		bool equals(SDL_Surface* tdata)
		{
			return tdata == data;
		}

};

