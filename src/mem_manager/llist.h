#ifndef LLIST_H_

#define LLIST_H_

#include<stdio.h>
#include<exception>

#define NOT_INITIALIZED 10001
#define ILLIGAL_OFFSET 10002

// exception class for linked list

class Linked_list_exception
{
	public:
	virtual const char* message(int code) const throw()
	{
		switch(code)
		{
			case NOT_INITIALIZED: 
				return "List not initialized yet";

			case ILLIGAL_OFFSET:
				return "Invalid index given";

			default:
				return "Unknown error";
		}
	}
};

template<class T, class Node>
class LinkedList
{
	private:

		Node *current;
		Node *head;
		Node *last;
		int index;
		int count;
		Linked_list_exception err_handler;

	public:
		LinkedList ( )
		{
			index = 0;
			head = NULL;
			current = NULL;
			last = NULL;
		}

		virtual ~LinkedList()
		{
			clear();
		}

		void clear()
		{
			current = head;
			Node *n;
			while(1)
			{
				if(current == NULL)
				{
					break;
				}
				n = current;
				current = n->next;
				delete n;
			}
		}

		void remove(int index)
		{
			try
			{
				get(index);
			}
			catch (int ex)
			{
				printf("%s\n", err_handler.message(ex));
				return;
			}

			Node *n;
			if(current == head)
			{
				n = head;
				head = current->next;
				head->prev = NULL;
			}
			else if(current == last)
			{
				n = last;
				last = current->prev;
				last->next = NULL;

			}
			else
			{
				n = current;
				current->prev->next = current->next;
				current->next->prev = current->prev;
			}

			delete n;
			count--;
		}

		void add(T data, int index=-1)
		{
			Node *new_node = init_new_node();
			new_node->set_data(data);

			if(head == NULL)
			{ 
				head = new_node;
				current = new_node;
				last = new_node;
			}
			else
			{
				last->next = new_node;
				new_node->prev = last;
				last = new_node;
			}

			if(index >= 0)
			{
				new_node->index = index;
			}
			count++;
		}

	private:
		Node *init_new_node()
		{	
			Node *new_node = new Node;
			new_node->next = NULL;
			new_node->prev = NULL;
			new_node->index = index++;
			count++;
			return new_node;
		}

	public:
		bool find(T data)
		{
			for( reset(); is_valid(); next())
			{
				if (current->equals(data))
				{
					return true;
				}
			}
			return false;
		}

		T get(int index)
		{
			reset();
			while(is_valid())
			{
				if(current->index == index)
				{
					return current->get_data();
				}
				next();
			}
			throw ILLIGAL_OFFSET;
		}

		bool is_valid()
		{
			if(current == NULL)
			{
				reset();
				return false;
			}
			return true;
		}

		bool next()
		{
			if (current==NULL)
			{
				return false;
			}
			current = current->next;
			return true;
		}

		bool previous()
		{
			if (current==NULL)
			{
				return false;
			}
			current = current->prev;
			return true;
		}

		void rewind()
		{
			current = head;
		}

		void reset()
		{
			current = head;
		}

		void forward()
		{
			current = last;
		}

		bool current_equals(T d)
		{
			if(current->equals(d))
			{
				return true;
			}
			return false;
		}

		T get_current()
		{
			if(current == NULL)
			{
				reset();
				throw NOT_INITIALIZED;
			}
			return current->get_data();
		}

		int get_current_index()
		{
			if(current == NULL)
			{
				throw ILLIGAL_OFFSET;
			}
			return current->index;
		}

		int get_count()
		{
			return count;
		}

};


#endif /* SRC/MEM_MANAGER/LLIST_H_ */
