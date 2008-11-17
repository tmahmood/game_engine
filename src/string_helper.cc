#include "string_helper.h"

#include<stdio.h>
#include<string.h>

bool String_helper::copy_string(char *&dest, const char *src)
{
	try
	{
		dest = new char[strlen(src) * sizeof(char)];
		strcpy(dest, src);
		return true;
	}
	catch(...)
	{
		if(dest !=NULL)
		{
			delete dest;
		}
		return false;
	}
}

