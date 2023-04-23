#pragma once

#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
using namespace std;

/*
 * 1、C++类之间信息的传递
 * 2、类与类之间的相互调用
 */

struct range {
	int x, y;
	int sum;
};

class DailyBase
{
public:
	DailyBase();    //构造函数  分配内存的函数也可以自己定义
	~DailyBase();   //析构函数  默认的释放内存的函数
public:
	 void opOne(vector<int>& op);
	 vector<int> ops ;
public:
	static range MaxSum(int a[], range e);
	static void  begin4();



};

