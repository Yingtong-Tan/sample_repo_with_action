// code from https://blog.csdn.net/i6223671/article/details/99832186
// cmaklist refer to https://blog.csdn.net/qq_38638132/article/details/105597856

#include<iostream>
#include <stdio.h>
#include <Python.h>

using namespace std;

int main()
{
	Py_Initialize();
	if (!Py_IsInitialized())
	{
		cout << "initialize failed" << endl;
		Py_Finalize();
	}
	PyObject *pModule;
	PyObject*pFunc = NULL;
	PyObject*pArg = NULL;

	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append('./')");
	pModule = PyImport_ImportModule("demo_test");//Python script name  

	if (!pModule) 
	{
		cout << "load py file failed" << endl;
		Py_Finalize();
	}
	else
	{
		pFunc = PyObject_GetAttrString(pModule, "run");//Python function name to call
		if (!pFunc)
		{
			cout << "load function failed" << endl;
			Py_Finalize();
		}
	}

	PyObject* pyParams = Py_BuildValue("(s)","lalala");//c++ type to python type
	char * result1;
	pArg = PyEval_CallObject(pFunc, pyParams);//call function
	PyArg_Parse(pArg, "s", &result1);//python type to c++ type
	cout << result1<< endl;
	cout << "call python finished!" << endl;

	system("pause");
}

