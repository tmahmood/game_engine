#include	"../mem_manager/llist.h"
#include	"../mem_manager/pyobjs.h"


bool test_engine(char **argv, int argc)
{
	LinkedList<PyObject*, PyObject_node>pyobj_list;

	PyObject *t = pyobj_list.add(PyString_FromString("pyengine_test"), 1000);
	PyEngine py_engine(argv, argc);

	pyobj_list.add(py_engine.load_module(t), 1002);
	pyobj_list.add(PyString_FromString("print_test_data"), 1003);

	py_engine.call_method(pyobj_list.get(1003));
}

int main (int argc, char const* argv[])
{
	printf("Test started!\n");
	test_engine(argv, argc);
	return 0;
}

