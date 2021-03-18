#include "util_socket.h"

util_function::Socket_Server_TCP::Socket_Server_TCP(int port, string ip)
{
	//DllVersion = MAKEWORD(2, 1);
	//init = WSAStartup(DllVersion, &wsaData);
	//int addrlen = sizeof(addr); //length of the address (required for accept call)
	//addr.sin_addr.s_addr = inet_addr(ip.c_str()); //Broadcast locally
	//addr.sin_port = htons(port); //port
	//addr.sin_family = AF_INET; //IPv4 Socket
	//sListen = socket(AF_INET, SOCK_STREAM, NULL); //Create socket to listen for new connections
	//bind(sListen, (SOCKADDR*)&addr, sizeof(addr)); //Bind the address to the socket
	//listen(sListen, SOMAXCONN); //Places sListen socket in a state in which it is listening for an incoming connections. Note: SOMAXCONN = Socket Oustanding 
	//newConnection = accept(sListen, (SOCKADDR*)&addr, &addrlen); //Accept a new connection
}

util_function::Socket_Server_TCP::~Socket_Server_TCP()
{
}

void util_function::Socket_Server_TCP::send_message(string message)
{
	//if (newConnection != 0)
	//{
	//	send(newConnection, message.c_str(), message.length(), NULL);	//Send MOTD buffer
	//}
}

string util_function::Socket_Server_TCP::receive_message()
{
	return string();
}

//util_function::Socket_Client_TCP::intialize(int port, string ip)
//{
//	DllVersion = MAKEWORD(2, 1);
//	init = WSAStartup(DllVersion, &wsaData);
//	int addrlen = sizeof(addr); //length of the address (required for accept call)
//	addr.sin_addr.s_addr = inet_addr(ip.c_str()); //Broadcast locally
//	addr.sin_port = htons(port); //port
//	addr.sin_family = AF_INET; //IPv4 Socket
//	connection = socket(AF_INET, SOCK_STREAM, NULL);
//	connected = connect(connection, (SOCKADDR*)&addr, addrlen);
//}

void util_function::Socket_Client_TCP::intialize(int port, string ip)
{
}

util_function::Socket_Client_TCP::Socket_Client_TCP()
{
}

util_function::Socket_Client_TCP::~Socket_Client_TCP()
{
}

string util_function::Socket_Client_TCP::receive_message()
{
	/*char getMessage[256];
	if (init == 0 || connected == 0)
	{
		recv(connection, getMessage, sizeof(getMessage), NULL);
	}
	return getMessage;*/
	return string();
}

void util_function::Socket_Client_TCP::send_message(string message)
{
}

void util_function::Socket_Server_UDP::initialize(int port, string ip)
{
	//init = WSAStartup(MAKEWORD(2, 2), &wsd);
	//s = socket(AF_INET, SOCK_DGRAM, 0);
	//init = s != INVALID_SOCKET;
	//socketSrv = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	//init = init && (s != INVALID_SOCKET);
	//int len = sizeof(SOCKADDR);
	//if (!strcmp(ip.c_str(), ""))
	//{
	//	addrSrv.sin_addr.s_addr = inet_addr(INADDR_ANY);
	//}
	//else
	//{
	//	addrSrv.sin_addr.s_addr = inet_addr(ip.c_str()); //Broadcast locally
	//}
	//addrSrv.sin_port = htons(port); //port
	//addrSrv.sin_family = AF_INET; //IPv4 Socket
	//nRet = bind(socketSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
}

util_function::Socket_Server_UDP::Socket_Server_UDP()
{
}

util_function::Socket_Server_UDP::~Socket_Server_UDP()
{
	/*WSACleanup();*/
}

void util_function::Socket_Server_UDP::send_message(string message)
{
}

string util_function::Socket_Server_UDP::receive_message()
{/*
	int len = 0;
	nRet = recvfrom(socketSrv, buf, BUF_SIZE, 0, (SOCKADDR*)&addrClient, &len);
	return buf;*/
	return string();
};

util_function::Socket_Client_UDP::Socket_Client_UDP()
{
}

void util_function::Socket_Client_UDP::initialize(int port, string ip)
{
	/*s = socket(AF_INET, SOCK_DGRAM, 0);*/
}

util_function::Socket_Client_UDP::~Socket_Client_UDP()
{
	/*closesocket(s);
	WSACleanup();*/
}

void util_function::Socket_Client_UDP::send_message(string message)
{
	/*ZeroMemory(buf, BUF_SIZE);
	strcpy(buf, message.c_str());
	nServAddLen = sizeof(servAddr);
	sendto(sockClient, buf, BUF_SIZE, 0, (sockaddr*)&servAddr, nServAddLen);*/
}

string util_function::Socket_Client_UDP::receive_message()
{
	return string();
}
