#include "../resources.h"
#include "string_helper.h"

bool String_helper::copy_string(char *&dest, const char *src)
{
	try
	{
		int len = strlen(src);
		dest = new char[len];
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

char *String_helper::search(char *src, char search_key,
				 char direction = 'f')
{
	if(direction == 'f')
	{
		return strchr(src, search_key);
	}
	else 
	{
		return strrchr(src, search_key);
	}
}

void String_helper::trim_right(char *string, char trim_char)
{
	int i = strlen(string)-1;

	while( string[i] == trim_char)
	{
		i--;
	}
	string[i+1] = '\0';
}

void String_helper::trim_left(char *src, char trim_char)
{
	char *result = src;
	char *orig_str;
	
	orig_str = &result[0];

	while(result[0] == trim_char) 
	{
		result = &result[1];
	}
	strcpy(src, result);
}

void String_helper::trim(char *src, char trim_char)
{
	trim_right(src, trim_char);
	trim_left(src, trim_char);
}

char* String_helper::add_string(char *src1, char *src2)
{
	char *tmp = new char[strlen(src1) + strlen(src2) + 1];
	if(tmp == NULL)
	{
		throw MEMORY_ALLOCATION_ERROR;
	}
	sprintf(tmp, "%s%s", src1, src2);
	return tmp;
}
