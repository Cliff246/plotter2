#include <iostream>
#include <Python.h>


int32_t main() 
{

	Py_Initialize();
	PyRun_SimpleString("print('hello')");
	return 0;
}
