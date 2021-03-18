// working dir cannot starts with \\diskstation.sabu.mtu.edu\DS

#include<iostream>
#include <stdio.h>
#include <Python.h>

using namespace std;

int main()
{
	cout << "--------Testing---------" << endl;
	system("pwd");
	system("demo_test.bat");
	system("pause");
}

