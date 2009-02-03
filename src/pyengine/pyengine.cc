#include 	<python2.5/Python.h>
#include	"pyengine.h"

PyEngine::PyEngine(char **argv, int argc)
{
	Py_SetProgramName(argv[0]);
	Py_Initialize();
	PySys_SetArgv(argc, argv); 
	check_error();

}

void PyEngine::check_error()
{	
	if (PyErr_Occurred())
	{
		PyErr_Print();
	}
}

PyEngine::~PyEngine()
{
	Py_Finalize();
}

PyObject* PyEngine::load_module(PyObject *module_name)
{
	return PyImport_Import(module_name);
}

PyObject* call_method(PyObject *method, PyObject *args=NULL)
{
	return PyObject_CallObject(method, args);
}
