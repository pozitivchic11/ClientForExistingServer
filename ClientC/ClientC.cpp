#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable: 4996)

#include <WinSock2.h>
#include <iostream>

int main()
{
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);

	if (WSAStartup(DLLVersion, &wsaData)) {
		std::cout << "Starting up error!" << std::endl;
		std::exit(1);
	}

	SOCKADDR_IN addr;
	int size_of_addr = sizeof(addr);

	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;

	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);

	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr))) {
		std::cout << "Connection error!" << std::endl;
		return 1;
	}
	std::cout << "User succesfully connected!" << std::endl;

	char msg[256];
	recv(Connection, msg, sizeof(msg), NULL);

	std::cout << msg << std::endl;

	return 0;
}