#pragma once
#pragma warning(disable:4996)

#include "PublicHeader.h"
#include <stdio.h>
using namespace std;


class BaseHide
{
public:
	//virtual void s() = 0;
	virtual void OverWrite(int x);   //����
	void Over(float x); // ����   �������еĳ�Ա��������
	virtual void overridetest();

	void m_ops();
	virtual void func();
	virtual void func1();
	void foo();
	virtual void print() {
		cout << "print() in Base." << endl;
	}

public:
	int m_op = 0;
private:
};

class SonBaseHide :public BaseHide
{
public:
	virtual void OverWrite(int x);  //
	void Over();    //�����˻����еĳ�Ա����
					//ͬ����Ա�������ǻ����е�ͬ������

	/*C++11������ 
	 *�������override�ؼ���
	 *��Ϊ�˼�����������麯���Ƿ���д�˻����е�ĳ���麯��
	 *���û����д�������ͻᱨ��
	 *��������overridetest�麯��
	 *���Ҫ��д
	 */
	virtual void overridetest() override;
	//virtual void overridetest(int x) override;

	void SonSize();
	virtual void func();
	void func1();
	void foo();
	void print() {
		cout << "print() in Derived." << endl;
	}
	void GetMemory(char** p, int num) 
	{
		*p = (char*)malloc(num);
	}
	void Test(void) 
	{
		char* str = NULL;
		GetMemory(&str, 100);
		strcpy(str, "hello");
		printf(str);
	}

public:
	int m_op = 0;

private:

};
