#include <python2.5/Python.h>

class PyObject_node
{
	public:
	PyObject_node *next;
	PyObject_node *prev;

	int index;
	bool empty;

	PyObject_node ( )
	{
		empty = true;

	}
	virtual ~PyObject_node()
	{
		if(empty)
		{
			return;
		}
		Py_DECREF(data);
		if(data!=NULL)
		{
			Py_XDECREF(data);
		}
	}

	void set_data(PyObject *obj)
	{
		if(!empty)
		{
			Py_DECREF(data);
		}

		data = obj;
		empty = false;
	}

	PyObject* get_data()
	{
		return data;
	}

	bool equals(PyObject *target)
	{
		return(target == data);
	}


	private:
	PyObject *data;
};

