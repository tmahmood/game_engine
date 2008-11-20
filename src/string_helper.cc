#include "string_helper.h"

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

char* String_helper::trim(char *src, char trim_char)
{
	char *result, *orig_str;

	if(!copy_string(result, src))
	{
		return NULL;
	}


	int i, j ,k;
	int len = strlen(trim_char);

	bool found_match_start = true;
	bool found_match_end;

	while(found_match_start) 
	{
		int f_char = strchr(src, trim_char[i]);
		if (f_char == 0) 
		{
			src[0] = '\0';
			
		}
	}
}

void String_helper::trim(char *&src, char *trim_char)
{
}
