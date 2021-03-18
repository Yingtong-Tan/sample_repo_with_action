#include "util_file_operation.h"

void utility_function::get_files_name_in_a_directory(string path, vector<string>& files)
{
	long long  hFile = 0;
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			if ((fileinfo.attrib &  _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					get_files_name_in_a_directory(p.assign(path).append("\\").append(fileinfo.name), files);
			}
			else
			{
				//files.push_back(p.assign(path).append("\\").append(fileinfo.name));
				files.push_back(fileinfo.name);
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}

void utility_function::delete_files_in_a_derectory(string path)
{
	const char * folderPath = path.c_str();
	char fileFound[256];
	WIN32_FIND_DATA info;
	HANDLE hp;

	sprintf(fileFound, "%s\\*.*", folderPath);
	hp = FindFirstFile(fileFound, &info);
	do
	{
		sprintf(fileFound, "%s\\%s", folderPath, info.cFileName);
		DeleteFile(fileFound);

	} while (FindNextFile(hp, &info));

	FindClose(hp);
}

bool utility_function::remove_directory(string path)
{
	return RemoveDirectory(path.c_str());
}

bool utility_function::create_directory(string path)
{
	return CreateDirectory(path.c_str(), NULL);
}

string utility_function::get_current_work_directory()
{
	char * input_dir_path;
	input_dir_path = _getcwd(NULL, 255);
	return string(input_dir_path);
}

void utility_function::create_new_file(fstream * file, string path, string file_name, vector<string> headers, ios_base::openmode mode, string delimeter)
{
	file = new fstream(path + file_name, mode);
	for (int i = 0; i < headers.size(); i++)
	{
		*file << headers[i].c_str() << delimeter.c_str();
	}
}

void utility_function::write_string_to_file(fstream * file, string path, string file_name, ios_base::openmode mode, string new_line)
{
	if (!file->is_open())
		file->open(path + file_name, mode);
	if (file->is_open())
	{
		*file << new_line.c_str() << endl;
	}
	else
	{
		cout << "error: fail to open the file: " << file_name.c_str() << endl;
	}
}

void utility_function::write_string_to_file(std::shared_ptr<fstream> file, string path, string file_name, ios_base::openmode mode, string new_line)
{
	if (!file->is_open())
		file->open(path + file_name, mode);
	if (file->is_open())
	{
		*file << new_line.c_str() << endl;
		(*file).flush();
	}
	else
	{
		cout << "error: fail to open the file: " << file_name.c_str() << endl;
	}
}
