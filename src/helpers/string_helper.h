#ifndef STRING_HELPER_H_

#define STRING_HELPER_H_

#define STRING_COPY_EXCEPTION 1001

#include<stdio.h>
#include<string.h>

class String_helper
{
	public:
		static bool copy_string(char *&dest, const char *src);
		static void trim(char *, char);
		static void trim_left(char *, char);
		static void trim_right(char *, char);
		static char* search(char *, char, char);
};

#endif /* SRC/STRING_HELPER_H_ */

