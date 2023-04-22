#pragma once
#define _CRT_SECURE_NO_WARNINGS 1 
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma waring(disable:4996)


#include <winsock2.h>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <iostream>
#pragma comment(lib,"WS2_32.lib")

class UdpDoubleCommit
{
public:
	UdpDoubleCommit();
	~UdpDoubleCommit();
public:
	WSADATA wsa;
	HANDLE rec;

	static DWORD WINAPI recv(LPVOID p);
	static DWORD WINAPI send(LPVOID p);
	void threadCreateTest();
private:
	
};
// UDP-2.cpp : 定义控制台应用程序的入口点。
//





