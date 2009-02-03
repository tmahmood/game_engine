#ifndef PYENGINE_H_

#define PYENGINE_H_

#include 	<python2.5/Python.h>

class PyEngine
{
	public:
	PyEngine (char **, int);
	virtual ~PyEngine();

	PyObject* load_module(PyObject *);
	PyObject* call_method(PyObject *,PyObject *);
	void check_error();

	private:
	
};

#endif /* SRC/PYENGINE/PYENGINE_H_ */

