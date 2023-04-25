#include "UdpDoubleCommit.h"



UdpDoubleCommit::UdpDoubleCommit()
{
	this->threadCreateTest();
}

UdpDoubleCommit::~UdpDoubleCommit()
{
}

DWORD __stdcall UdpDoubleCommit::recv(LPVOID p)
{
	char buf[20];
	sockaddr_in addr_in;
	SOCKET s;
	int len;
	s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (s == INVALID_SOCKET)
	{
		printf("socket failed\n");
		return -1;
	}
	addr_in.sin_family = AF_INET;
	addr_in.sin_port = htons(8000);
	addr_in.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	if (bind(s, (sockaddr*)&addr_in, sizeof(sockaddr)) == SOCKET_ERROR)
	{
		printf("bind failed\n");
		return -1;
	}
	len = sizeof(addr_in);
	while (1)
	{
		memset(buf, 0, sizeof(buf));
		if (recvfrom(s, buf, sizeof(buf), 0, (sockaddr*)&addr_in, &len) == SOCKET_ERROR)
		{
			printf("recvfrom error\n");
			return -1;
		}
		printf("from: %s:%d\n", inet_ntoa(addr_in.sin_addr), ntohs(addr_in.sin_port));
		printf("content: %s\n\n", buf);
		if (strcmp(buf, "quit") == 0)
		{
			break;
		}
	}
	closesocket(s);
	return 0;
}

DWORD __stdcall UdpDoubleCommit::send(LPVOID p)
{
	int retval;
	std::string str;
	char buf[20];
	SOCKET s;
	sockaddr_in addr_in;
	s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	addr_in.sin_family = AF_INET;
	addr_in.sin_port = htons(9000);
	addr_in.sin_addr.S_un.S_addr = inet_addr("192.168.132.1");//***************
	while (1)
	{
		//printf("input the content:\n");
		memset(buf, 0, sizeof(buf));
		std::getline(std::cin, str);
		strcpy(buf, str.c_str());
		retval = sendto(s, buf, sizeof(buf), 0, (sockaddr*)&addr_in, sizeof(addr_in));
		if (retval == SOCKET_ERROR)
		{
			printf("sendt0 failed\n");
			closesocket(s);
			WSACleanup();
			return -1;
		}
		printf("send succeeded\n\n");
		if (strcmp(buf, "quit") == 0)
		{
			break;
		}
	}
	closesocket(s);
	return 0;
}

void UdpDoubleCommit::threadCreateTest()
{
	HANDLE recvh, sendh;
	DWORD recv_id, send_id, recv_excode, send_excode;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) == 0)
	{
		recvh = CreateThread(NULL, 0, recv, 0, 0, &recv_id);
		//recvh = CreateThread(NULL, 0, UdpDoubleCommit::recv, 0, 0, &recv_id);

		sendh = CreateThread(NULL, 0, send, 0, 0, &send_id);
		while (1)
		{
			Sleep(1000);
			GetExitCodeThread(recvh, &recv_excode);
			GetExitCodeThread(sendh, &send_excode);
			if (recv_excode != STILL_ACTIVE || send_excode != STILL_ACTIVE)
			{
				break;
			}
		}
		printf("\n*****end*****\n");
		getchar();
		system("pause");
	}
	else
	{
		printf("startup failed\n");
	}
}
