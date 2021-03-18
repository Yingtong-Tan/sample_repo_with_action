#pragma once
#include <vector>
#include <string>
#include <windows.h>
#include <wincon.h>
#include <stdio.h>
#include <time.h>
#include <Nb30.h>
#pragma comment(lib,"netapi32.lib") 
//https ://blog.csdn.net/ytusdc/java/article/details/78480806
using namespace std;

namespace utility_function
{
	string generate_uuid();
	string get_mac_address();
	string get_ipv4_address();
	string get_ipv6_address();
}