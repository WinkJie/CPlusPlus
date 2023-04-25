#pragma once
#include "PublicHeader.h"
#include <string>
using namespace std;
//普通实现

/*计算机
 *加减乘除
 *计算器
 *--------------基类--------------*
 */

class Calculator {
public:
	int getResult(string oper)
	{
		if (oper == "+") {
			return m_Num1 + m_Num2;
		}
		else if (oper == "-") {
			return m_Num1 - m_Num2;
		}
		else if (oper == "*") {
			return m_Num1 * m_Num2;
		}
		//如果要提供新的运算，需要修改源码
		//如果想扩展新的功能，需要修改源码
		//在真实开发中，提倡开闭原则
		//开闭原则：对拓展进行开放，对修改进行关闭
	}
public:
	int m_Num1;
	int m_Num2;
};

//void test01()
//{
//	//普通实现测试
//	Calculator c;
//	c.m_Num1 = 10;
//	c.m_Num2 = 10;
//	cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;
//
//	cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;
//
//	cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
//}



//多态实现
//抽象计算器类
//多态优点：
//1.代码组织结构清晰，
//2.可读性强
//3.利于前期和后期的扩展以及维护
class AbstractCalculator
{
	//抽象类
public:

	virtual int getResult()
	{
		return 0;
	}

	virtual string sizeokasd()
	{
		return str1 +" + " + str2;
	}

	int m_Num1;
	int m_Num2;
	string str1;
	string str2;
};

//加法计算器
class AddCalculator :public AbstractCalculator
{
	//加法计算器
public:
	int getResult()
	{
		return m_Num1 + m_Num2;
	}
	string sizeokasd()
	{
		return str1 + str2;
	}
};

//释放的是堆区的内存，但是指针依然存在
//减法计算器
class SubCalculator :public AbstractCalculator
{
	//减法计算器
public:
	int getResult()
	{
		return m_Num1 - m_Num2;
	}
};

//乘法计算器
class MulCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 * m_Num2;
	}
};
class DivisionCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 / m_Num2;
	}
};


//void test02()
//{
//	//创建加法计算器
//	AbstractCalculator* abc = new AddCalculator;
//	abc->m_Num1 = 10;
//	abc->m_Num2 = 10;
//	cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
//	delete abc;  //用完了记得销毁
//
//	//创建减法计算器
//	abc = new SubCalculator;
//	abc->m_Num1 = 10;
//	abc->m_Num2 = 10;
//	cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
//	delete abc;
//
//	//创建乘法计算器
//	abc = new MulCalculator;
//	abc->m_Num1 = 10;
//	abc->m_Num2 = 10;
//	cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
//	delete abc;
//}

//https://www.cnblogs.com/daimasanjiaomao/p/13823231.html
