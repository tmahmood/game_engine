/*
 * =====================================================================================
 *
 *       Filename:  resources.h
 *
 *    Description:  All the required images are defined here
 *
 *        Version:  1.0
 *        Created:  01/16/2009 03:19:24 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Tarin Mahmood (tmn), mrlinux045@gmail.com
 *        Company:  tmnSoft
 *
 * =====================================================================================
 */

#ifndef RESOURCES_H_
#define RESOURCES_H_

#define	DISPLAY_INIT_FAILED 100
#define STRING_COPY_EXCEPTION 101
#define MEMORY_ALLOCATION_ERROR 102
#define	ALL_GOOD 0

#define MISSILE_IMAGE 1003

#define S_EXIT 1000

typedef void (*Fx)();

#define Image SDL_Surface*

enum Direction
{
	Left, Right, Up, Down
};

struct Rectangle
{
	int x;
	int y;
	int width;
	int height;
};

struct Point
{
	int x;
	int y;
};

#include	<stdio.h>
#include	<stdlib.h>
#include	<SDL/SDL_image.h>

#include	"sdl/sdl_dm.h"
#include	"sdl/event.h"

#include	"objects/vehical.h"
#include	"helpers/file_helper.h"
#include 	"helpers/string_tokenizer.h"
#include 	"ini_parser/iniparser.h"
#include 	"ini_parser/dictionary.h"

#include	"mem_manager/llist.h"
#include	"mem_manager/image_node.h"
#include	"mem_manager/string_node.h"
#include	"sdl/timer.h"
#include	"mem_manager/pyobjs.h"


#endif /* SRC/RESOURCES_H_ */


