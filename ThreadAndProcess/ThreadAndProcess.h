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
////	①：A和B为全局变量进行线程之间的通信
////	②：C和D为互斥量进行线程之间的通信
////	③：E和F为信号量进行线程之间的通信
////	④：G和H为事件进行线程之间的通信
////	⑤：临界区（MFC中的通信方式）
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
//	//全局变量
//
//	volatile int signalNum = 0;   //①
//	HANDLE mutex = CreateMutex(NULL, FALSE, NULL);  //②：C和D为互斥量进行线程之间的通信
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
