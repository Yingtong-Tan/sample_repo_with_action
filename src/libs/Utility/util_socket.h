#pragma once
//#include <WinSock2.h>
#include <iostream>
#include <string>
//#pragma comment(lib,"ws2_32.lib")
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define BUF_SIZE    64
#pragma warning(disable:4996)
using namespace std;
namespace util_function
{ 
	class Socket_Server_TCP
	{
	private:
		/*WSADATA wsaData;
		WORD DllVersion;
		int init;
		SOCKADDR_IN addr;
		SOCKET sListen;
		SOCKET newConnection;*/
	public:
		Socket_Server_TCP(int port, string ip = "127.0.0.1");
		~Socket_Server_TCP();
		void send_message(string message);
		string receive_message();
	};

	class Socket_Client_TCP
	{
	private:
		/*WSADATA wsaData;
		WORD DllVersion;
		int init;
		SOCKADDR_IN addr;
		SOCKET connection;*/
		int connected;
	public:
		void intialize(int port, string ip = "127.0.0.1");

		Socket_Client_TCP();
		~Socket_Client_TCP();
		string receive_message();
		void send_message(string message);
	};

	class Socket_Server_UDP
	{
	private:
		/*WSADATA wsd;
		WORD DllVersion;
		int init;
		SOCKET s;
		SOCKET socketSrv;
		SOCKADDR_IN addrSrv;
		SOCKADDR_IN addrClient;*/ 
		char buf[BUF_SIZE];
		int nRet;
	public:
		void initialize(int port, string ip = "127.0.0.1");
		Socket_Server_UDP();
		~Socket_Server_UDP();
		void send_message(string message);
		string receive_message();
	};

	class Socket_Client_UDP
	{
	private:
		/*WSADATA wsd;
		WORD DllVersion;
		int init;
		SOCKET sockClient;
		SOCKET s;
		SOCKADDR_IN servAddr;
		char buf[BUF_SIZE];
		int nServAddLen;
		int nRet;*/
	public:
		void initialize(int port, string ip = "127.0.0.1");
		Socket_Client_UDP();
		~Socket_Client_UDP();
		void send_message(string message);
		string receive_message();
	};
};