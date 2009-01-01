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


#include	"../mem_management/llist.h"

class Image_node
{
	SDL_Surface *data
	public:
		Image_node *next;
		Image_node *prev;
		int index;

		void set_data(char *d)
		{
			data = IMG_Load(d);
		}	

		T get_data()
		{
			return data;
		}
		~node()
		{
			printf("Deleting!");
		}

};

