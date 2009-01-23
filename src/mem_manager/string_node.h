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
	bool empty;

	String_node()
	{
		data = NULL;
		empty = false;
	}

	void set_data(char *d=NULL)
	{
		if(!empty)
		{
			delete data;
		}
		int len;
		if(d==NULL)
		{
			empty = true;
			len = 10;
		}
		else
		{
			len = strlen(d);
		}

		data = new char[len];
		strcpy(data, d);
	
	}	

	char *get_data()
	{
		return data;
	}

	~String_node()
	{
		printf(">%s\n", data);
		delete data;
	}

	bool equals(char *d)
	{
		return strcmp(d, data) == 0;
	}
};




#endif /* STRING_NODE_H_ */


