/*
 * =====================================================================================
 *
 *       Filename:  time.h
 *
 *    Description:  Timer class using SDL tick, stolen from a 
 *    			game tutorial
 *
 *        Version:  1.0
 *        Created:  01/19/2009 05:36:36 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Tarin Mahmood (tmn), mrlinux045@gmail.com
 *        Company:  tmnSoft
 *
 * =====================================================================================
 */
#ifndef TIME_H_

#define TIME_H_

class Timer
{
	private:
		//The clock time when the timer started
		int start_ticks;

		//The ticks stored when the timer was paused
		int paused_ticks;

		//The timer status
		bool paused;
		bool started;

	public:
		//Initializes variables
		Timer();

		//The various clock actions
		void start();
		void stop();
		void pause();
		void unpause();

		//Gets the timer's time
		int get_ticks();

		//Checks the status of the timer
		bool is_started();
		bool is_paused();
};

#endif /* TIME_H_ */

