#include "ThreadAndProcess.h"
using namespace std;
#define _SAL2_Source_(Name, args, annotes) _SA_annotes3(SAL_name, #Name, "", "2") _Group_(annotes _SAL_nop_impl_)


ThreadAndProcess::ThreadAndProcess()
{
	HANDLE hThread;
	HANDLE hThread1;
	DWORD  threadId;
	DWORD  threadId1;
	int iRunTime = 0;
	hThread = CreateThread(NULL, 0, ThreadAndProcess::ThreadFunc, 0, 0, &threadId); // 创建线程
	
	hThread1 = CreateThread(NULL, 0, ThreadAndProcess::ThreadFunc, 0, 0, &threadId1); // 创建线程
	SwitchToThread();
	while (++iRunTime<50)
	{
		cout << "main is Running. And the Thread is " << threadId << endl;
		Sleep(10);
	}
	printf("我是主线程， pid = %d\n", GetCurrentThreadId());  //输出主线程pid
	Sleep(2000);
	
}

ThreadAndProcess::~ThreadAndProcess()
{
}

void ThreadAndProcess::pointerFun1()
{
	cout << "func() is Running. And the Thread is " << GetCurrentThreadId() << endl;
}

void ThreadAndProcess::pointerFun2()
{
}

DWORD __stdcall ThreadAndProcess::ThreadFunc(LPVOID)
{
	int iRunTime = 0;
	printf("我是子线程， pid = %d\n", GetCurrentThreadId());   //输出子线程pid
	while (++iRunTime < 50)
	{
		cout << "func() is Running. And the Thread is " << GetCurrentThreadId() << endl;
		Sleep(10);
	}
	Sleep(10);
	return 0;
}












//#include "ThreadAndProcess.h"
//
////ThreadAndProcess *ThreadAndProcess::fThis;
//
//ThreadAndProcess::ThreadAndProcess()
//{
//	/*C++库的动态调用
//	*静态调用需要.dll、.lib、.h  三个文件
//	*动态调用仅需要.dll即可
//	*
//	* 加载方式：
//	* 先获取HINSTANCE 句柄模型，
//	* 再定义typedef 新类型，
//	* 之后根据句柄模型获取库中的函数地址
//	*
//	*
//	*/
//
//	//DWORD param1 = 56, param2 = 99;
//	//HINSTANCE hDllInst = LoadLibrary("youApp.DLL");
//	////HINSTANCE hDllInst = LoadLibraryA(TEXT("youApp.DLL"));
//	////HINSTANCE hDllInst = LoadLibraryA("youApp.DLL");
//
//
//	//if (hDllInst)
//	//{
//	//	typedef DWORD(WINAPI* MYFUNC)(DWORD, DWORD);
//	//	MYFUNC youFuntionNameAlias = NULL; // youFuntionNameAlias 函数别名
//	//	youFuntionNameAlias = (MYFUNC)GetProcAddress
//	//	(hDllInst, "youFuntionName");
//	//	// youFuntionName 在DLL中声明的函数名
//	//	if (youFuntionNameAlias)
//	//	{
//	//		youFuntionNameAlias(param1, param2);
//	//	}
//	//	FreeLibrary(hDllInst);
//	//}
//
//	ThreadAndProcess a;
//	HANDLE threadA = CreateThread(NULL, 0, threadFuncA, NULL, 0, NULL);
//	HANDLE threadB = CreateThread(NULL, 0, threadFuncB, NULL, 0, NULL);
//	HANDLE threadC = CreateThread(NULL, 0, threadFuncB, NULL, 0, NULL);
//	HANDLE threadD = CreateThread(NULL, 0, threadFuncB, NULL, 0, NULL);
//	HANDLE threadE = CreateThread(NULL, 0, threadFuncB, NULL, 0, NULL);
//	HANDLE threadF = CreateThread(NULL, 0, threadFuncB, NULL, 0, NULL);
//	HANDLE threadG = CreateThread(NULL, 0, threadFuncB, NULL, 0, NULL);
//	HANDLE threadH = CreateThread(NULL, 0, threadFuncB, NULL, 0, NULL);
//
//	/*HANDLE threadX = CreateThread(NULL, 0, threadFuncX, NULL, 0, NULL);
//	HANDLE threadY = CreateThread(NULL, 0, threadFuncY, NULL, 0, NULL);*/
//
//	WaitForSingleObject(threadA, INFINITE);  //等待线程A结束
//	CloseHandle(threadA);//CloseHandle只是关闭了系统句柄,该线程还是可以正常的运行
//	CloseHandle(threadB);
//
//	WaitForSingleObject(threadD, INFINITE);
//	CloseHandle(threadC);//CloseHandle只是关闭了系统句柄,该线程还是可以正常的运行
//	CloseHandle(threadD);
//
//	WaitForSingleObject(threadE, INFINITE);
//	CloseHandle(threadE);//CloseHandle只是关闭了系统句柄,该线程还是可以正常的运行
//	CloseHandle(threadF);
//
//	WaitForSingleObject(threadX, INFINITE);
//	CloseHandle(threadX);//CloseHandle只是关闭了系统句柄,该线程还是可以正常的运行
//	CloseHandle(threadY);
//
//}
//
//ThreadAndProcess::~ThreadAndProcess()
//{
//}
//
//void ThreadAndProcess::copysum()
//{
//	mutexop = ThreadAndProcess::mutex;
//	signalSemaphoreop = ThreadAndProcess::signalSemaphore;
//	ThreadEventop = ThreadAndProcess::ThreadEvent;
//
//
//}
//
//void ThreadAndProcess::threadFuncA()
//{
//	Sleep(2000);
//	if (0 == mutexop)
//	{
//		printf("signalNum not changed!\n");
//	}
//	else
//	{
//		printf("signalNum has changed!\n");
//	}
//
//}
//
//
//void ThreadAndProcess::threadFuncB()
//{
//	//Sleep(3000);
//	ThreadAndProcess::signalNum = 2;
//}
//
//void ThreadAndProcess::threadFuncC()
//{
//	//对互斥量加锁,如果已经加锁了则等待其解锁,等待时间为INFINITE(表示永久)
//	WaitForSingleObject(mutex, INFINITE);
//	/*
//		WaitForSingleObject(mutex, INFINITE);
//
//		这里可以做对共享资源的操作
//
//		ReleaseMutex(mutex);
//	*/
//	printf("threadFuncC lock mutex，please wait~~~~~~\n");
//	Sleep(5000);
//	printf("threadFuncC unlock mutex!!!!!!!!!!!!!!!!\n");
//	//互斥量解锁
//	ReleaseMutex(mutex);
//}
//
//void ThreadAndProcess::threadFuncD()
//{
//	Sleep(2000);
//	WaitForSingleObject(mutex, INFINITE);
//	printf("This is threadFuncB ~~~~~~\n");
//	ReleaseMutex(mutex);
//}
//
//void ThreadAndProcess::threadFuncE()
//{
//	Sleep(2000);
//	WaitForSingleObject(signalSemaphore, INFINITE);
//	printf("threadFuncE 使用了一个信号量!\n");
//	Sleep(2000);
//	printf("threadFuncE 释放了一个信号量!\n");
//	ReleaseSemaphore(signalSemaphore, 1, NULL);
//}
//
//void ThreadAndProcess::threadFuncF()
//{
//	//这里会使信号量减1
//	WaitForSingleObject(signalSemaphore, INFINITE);
//	printf("threadFuncF 使用了一个信号量!\n");
//	Sleep(5000);
//	//信号量+1
//	printf("threadFuncF 释放了一个信号量!\n");
//	ReleaseSemaphore(signalSemaphore, 1, NULL);
//}
//
//void ThreadAndProcess::threadFuncG()
//{
//	printf("threadFuncG 等待事件有信号!\n");
//	WaitForSingleObject(ThreadEvent, INFINITE);
//	printf("threadFuncG 等待事件信号成功,并把事件自动设置为无信号状态!\n");
//}
//
//void ThreadAndProcess::threadFuncH()
//{
//	Sleep(5000);
//	//给事件赋予信号
//	SetEvent(ThreadEvent);
//	printf("threadFuncH 给了事件信号!\n");
//}
////
////void ThreadAndProcess::threadFuncX()
////{
////	Sleep(2000);
////	printf("**************threadFuncX 等待临界区解锁!\n");
////	cs.Lock();
////	printf("**************threadFuncX 等待临界区解锁成功,对其加锁!\n");
////	printf("**************threadFuncX 把临界区解锁!\n");
////	cs.Unlock();
////}
////
////void ThreadAndProcess::threadFuncY()
////{
////	cs.Lock();
////	printf("**************threadFuncY 把临界区锁住了!\n");
////	Sleep(5000);
////	printf("**************threadFuncY 把临界区解锁!\n");
////	cs.Unlock();
////}
