#include "string_helper.h"
#include "file_helper.h"
#include <stdio.h>

File_helper::File_helper()
{
	last_read_data = NULL;
}

File_helper::~File_helper()
{
	if (last_read_data !=NULL)
	{
		delete last_read_data;
	}

	if(file_name == NULL)
	{
		delete file_name;
	}
}

long File_helper::get_file_size(char *fname)
{
	FILE *fp = fopen(fname, "r");
	if(!fp)
		return -1;

	fseek (fp , 0 , SEEK_END);
	long size = ftell (fp);
	fclose(fp);
	return size;
}

long File_helper::get_file_size(FILE *fp)
{
	fseek (fp , 0 , SEEK_END);
	long size = ftell (fp);
	rewind (fp);
	return size;
}

bool File_helper::read_file(char *fname)
{
	string_helper.copy_string(file_name, fname);

	FILE *fp = fopen(fname, "r");
	if(fp == NULL)
		return false;

	file_size = get_file_size(fp);

	last_read_data = new char[file_size * sizeof(char)];
	size_t result = fread (last_read_data, 1, file_size, fp);

	if(result != file_size)
		return false;

	fclose(fp);
	return true;
}

char *File_helper::get_last_read_data()
{
	char *rvalue;
	if(!string_helper.copy_string(rvalue, last_read_data))
	{
		throw (STRING_COPY_EXCEPTION);
	}
	return rvalue;
}

long File_helper::get_last_file_size()
{
	return file_size;
}
