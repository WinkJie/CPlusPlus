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
	hThread = CreateThread(NULL, 0, ThreadAndProcess::ThreadFunc, 0, 0, &threadId); // �����߳�
	
	hThread1 = CreateThread(NULL, 0, ThreadAndProcess::ThreadFunc, 0, 0, &threadId1); // �����߳�
	SwitchToThread();
	while (++iRunTime<50)
	{
		cout << "main is Running. And the Thread is " << threadId << endl;
		Sleep(10);
	}
	printf("�������̣߳� pid = %d\n", GetCurrentThreadId());  //������߳�pid
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
	printf("�������̣߳� pid = %d\n", GetCurrentThreadId());   //������߳�pid
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
//	/*C++��Ķ�̬����
//	*��̬������Ҫ.dll��.lib��.h  �����ļ�
//	*��̬���ý���Ҫ.dll����
//	*
//	* ���ط�ʽ��
//	* �Ȼ�ȡHINSTANCE ���ģ�ͣ�
//	* �ٶ���typedef �����ͣ�
//	* ֮����ݾ��ģ�ͻ�ȡ���еĺ�����ַ
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
//	//	MYFUNC youFuntionNameAlias = NULL; // youFuntionNameAlias ��������
//	//	youFuntionNameAlias = (MYFUNC)GetProcAddress
//	//	(hDllInst, "youFuntionName");
//	//	// youFuntionName ��DLL�������ĺ�����
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
//	WaitForSingleObject(threadA, INFINITE);  //�ȴ��߳�A����
//	CloseHandle(threadA);//CloseHandleֻ�ǹر���ϵͳ���,���̻߳��ǿ�������������
//	CloseHandle(threadB);
//
//	WaitForSingleObject(threadD, INFINITE);
//	CloseHandle(threadC);//CloseHandleֻ�ǹر���ϵͳ���,���̻߳��ǿ�������������
//	CloseHandle(threadD);
//
//	WaitForSingleObject(threadE, INFINITE);
//	CloseHandle(threadE);//CloseHandleֻ�ǹر���ϵͳ���,���̻߳��ǿ�������������
//	CloseHandle(threadF);
//
//	WaitForSingleObject(threadX, INFINITE);
//	CloseHandle(threadX);//CloseHandleֻ�ǹر���ϵͳ���,���̻߳��ǿ�������������
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
//	//�Ի���������,����Ѿ���������ȴ������,�ȴ�ʱ��ΪINFINITE(��ʾ����)
//	WaitForSingleObject(mutex, INFINITE);
//	/*
//		WaitForSingleObject(mutex, INFINITE);
//
//		����������Թ�����Դ�Ĳ���
//
//		ReleaseMutex(mutex);
//	*/
//	printf("threadFuncC lock mutex��please wait~~~~~~\n");
//	Sleep(5000);
//	printf("threadFuncC unlock mutex!!!!!!!!!!!!!!!!\n");
//	//����������
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
//	printf("threadFuncE ʹ����һ���ź���!\n");
//	Sleep(2000);
//	printf("threadFuncE �ͷ���һ���ź���!\n");
//	ReleaseSemaphore(signalSemaphore, 1, NULL);
//}
//
//void ThreadAndProcess::threadFuncF()
//{
//	//�����ʹ�ź�����1
//	WaitForSingleObject(signalSemaphore, INFINITE);
//	printf("threadFuncF ʹ����һ���ź���!\n");
//	Sleep(5000);
//	//�ź���+1
//	printf("threadFuncF �ͷ���һ���ź���!\n");
//	ReleaseSemaphore(signalSemaphore, 1, NULL);
//}
//
//void ThreadAndProcess::threadFuncG()
//{
//	printf("threadFuncG �ȴ��¼����ź�!\n");
//	WaitForSingleObject(ThreadEvent, INFINITE);
//	printf("threadFuncG �ȴ��¼��źųɹ�,�����¼��Զ�����Ϊ���ź�״̬!\n");
//}
//
//void ThreadAndProcess::threadFuncH()
//{
//	Sleep(5000);
//	//���¼������ź�
//	SetEvent(ThreadEvent);
//	printf("threadFuncH �����¼��ź�!\n");
//}
////
////void ThreadAndProcess::threadFuncX()
////{
////	Sleep(2000);
////	printf("**************threadFuncX �ȴ��ٽ�������!\n");
////	cs.Lock();
////	printf("**************threadFuncX �ȴ��ٽ��������ɹ�,�������!\n");
////	printf("**************threadFuncX ���ٽ�������!\n");
////	cs.Unlock();
////}
////
////void ThreadAndProcess::threadFuncY()
////{
////	cs.Lock();
////	printf("**************threadFuncY ���ٽ�����ס��!\n");
////	Sleep(5000);
////	printf("**************threadFuncY ���ٽ�������!\n");
////	cs.Unlock();
////}
