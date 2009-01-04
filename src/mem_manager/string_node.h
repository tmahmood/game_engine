/*
 * =====================================================================================
 *
 *       Filename:  string_node.h
 *
 *    Description:  String node
 *
 *        Version:  1.0
 *        Created:  01/01/2009 01:59:32 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Tarin Mahmood (tmn), mrlinux045@gmail.com
 *        Company:  tmnSoft
 *
 * =====================================================================================
 */
#ifndef STRING_NODE_H_

#define STRING_NODE_H_

char test[][5] = {"123", "234"};

class String_node
{
	char* data;
	public:
	String_node *next;
	String_node *prev;
	int index;

	void set_data(char *d)
	{
		data = new char[strlen(d)];
		strcpy(data, d);
	}	

	char *get_data()
	{
		return data;
	}

	~String_node()
	{
		printf("Goodbye %s\n", data);
		delete data;
	}

	bool equals(char *d)
	{
		if(!strcmp(d, data))
		{
			return true;
		}
		return false;			
	}
};




#endif /* STRING_NODE_H_ */


