#pragma once

#include "PublicHeader.h"
#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
#include <stdio.h>


class ThreadAndProcess
{
public:
	ThreadAndProcess();
	~ThreadAndProcess();

	void pointerFun1();
	void pointerFun2();
	static DWORD WINAPI ThreadFunc(LPVOID);

public:
	std::atomic_flag flag = ATOMIC_FLAG_INIT;
	DWORD threadIdop = GetCurrentThreadId();


private:

};






////#pragma once
//#include "PublicHeader.h"
//////#include "PublicHeader.h"
//////#include <stdio.h>
////
//////using namespace std;
/////*
////	�٣�A��BΪȫ�ֱ��������߳�֮���ͨ��
////	�ڣ�C��DΪ�����������߳�֮���ͨ��
////	�ۣ�E��FΪ�ź��������߳�֮���ͨ��
////	�ܣ�G��HΪ�¼������߳�֮���ͨ��
////	�ݣ��ٽ�����MFC�е�ͨ�ŷ�ʽ��
////*/
//
//class ThreadAndProcess
//{
//
//public:
//	ThreadAndProcess();
//	~ThreadAndProcess();
//
//public:
//	//ȫ�ֱ���
//
//	volatile int signalNum = 0;   //��
//	HANDLE mutex = CreateMutex(NULL, FALSE, NULL);  //�ڣ�C��DΪ�����������߳�֮���ͨ��
//	HANDLE signalSemaphore = CreateSemaphore(NULL, 1, 1, NULL);
//	HANDLE ThreadEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
//
//	void copysum();
//	static HANDLE mutexop;
//	static HANDLE signalSemaphoreop;
//	static HANDLE ThreadEventop;
//
//	
//	static void threadFuncA();
//	static void threadFuncB();
//	static void threadFuncC();
//	static void threadFuncD();
//	static void threadFuncE();
//	static void threadFuncF();
//	static void threadFuncG();
//	static void threadFuncH();
//	//void threadFuncX();
//	//void threadFuncY();
//};
////
////
