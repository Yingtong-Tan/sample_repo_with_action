#pragma once
#include "util_include_all.h"
#include <windows.h>
#include <corecrt_io.h>
#include <direct.h>	 
#pragma comment(lib, "User32.lib")
namespace utility_function
{
	void get_files_name_in_a_directory(string path, vector<string>& files);
	void delete_files_in_a_derectory(string path);
	string get_current_work_directory();
	bool remove_directory(string path);
	bool create_directory(string path);

	void create_new_file(fstream * file, string path, string file_name, vector<string> headers, ios_base::openmode mode, string delimeter);
	void write_string_to_file(fstream * file, string path, string file_name, ios_base::openmode mode, string new_line);
	void write_string_to_file(shared_ptr<fstream> file, string path, string file_name, ios_base::openmode mode, string new_line);
}