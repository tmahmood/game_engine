#ifndef STRING_HELPER_H_

#define STRING_HELPER_H_

#define STRING_COPY_EXCEPTION 1001

#include<stdio.h>
#include<string.h>

class String_helper
{
	public:
		bool copy_string(char *&dest, const char *src);
		void split(char *string, char );
};

#endif /* SRC/STRING_HELPER_H_ */

