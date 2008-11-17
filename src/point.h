/*
 * =====================================================================================
 *
 *       Filename:  point.h
 *
 *    Description:  Point's header 
 *
 *        Version:  1.0
 *        Created:  11/17/2008 12:09:34 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Tarin Mahmood (tmn), mrlinux045@gmail.com
 *        Company:  tmnSoft
 *
 * =====================================================================================
 */

class Point
{
	int x;
	int y;

	public:
	void set_position(int, int);
	int get_x_position();
	int get_y_position();

	void move_left(int);
	void move_right(int);
	void move_up(int);
	void move_down(int);
};


