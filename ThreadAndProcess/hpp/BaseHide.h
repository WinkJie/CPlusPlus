#pragma once
#pragma warning(disable:4996)

#include "PublicHeader.h"
#include <stdio.h>
using namespace std;


class BaseHide
{
public:
	//virtual void s() = 0;
	virtual void OverWrite(int x);   //覆盖
	void Over(float x); // 隐藏   被子类中的成员函数隐藏
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
	void Over();    //隐藏了基类中的成员函数
					//同名成员函数覆盖基类中的同名函数

	/*C++11新特新 
	 *如果存在override关键字
	 *是为了检查派生类中虚函数是否重写了基类中的某个虚函数
	 *如果没有重写编译器就会报错
	 *比如下面overridetest虚函数
	 *如果要重写
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
