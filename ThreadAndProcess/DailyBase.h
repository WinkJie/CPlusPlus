#pragma once

#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
using namespace std;

/*
 * 1��C++��֮����Ϣ�Ĵ���
 * 2��������֮����໥����
 */

struct range {
	int x, y;
	int sum;
};

class DailyBase
{
public:
	DailyBase();    //���캯��  �����ڴ�ĺ���Ҳ�����Լ�����
	~DailyBase();   //��������  Ĭ�ϵ��ͷ��ڴ�ĺ���
public:
	 void opOne(vector<int>& op);
	 vector<int> ops ;
public:
	static range MaxSum(int a[], range e);
	static void  begin4();



};

