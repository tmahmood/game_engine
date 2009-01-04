/*
 * =====================================================================================
 *
 *       Filename:  int_node.h
 *
 *    Description:  int node
 *
 *        Version:  1.0
 *        Created:  01/01/2009 02:05:11 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Tarin Mahmood (tmn), mrlinux045@gmail.com
 *        Company:  tmnSoft
 *
 * =====================================================================================
 */

class Int_node
{
	int data;
	public:
	Int_node *next;
	Int_node *prev;
	int index;

	void set_data(int d)
	{
		data = d;
	}	

	int get_data()
	{
		return data;
	}

	~Int_node()
	{
		printf("Deleting!\n");
	}

	bool equals(int d)
	{
		return data == d;
	}
};


