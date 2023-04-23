#pragma once
#include "PublicHeader.h"
#include <string>
using namespace std;
//��ͨʵ��

/*�����
 *�Ӽ��˳�
 *������
 *--------------����--------------*
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
		//���Ҫ�ṩ�µ����㣬��Ҫ�޸�Դ��
		//�������չ�µĹ��ܣ���Ҫ�޸�Դ��
		//����ʵ�����У��ᳫ����ԭ��
		//����ԭ�򣺶���չ���п��ţ����޸Ľ��йر�
	}
public:
	int m_Num1;
	int m_Num2;
};

//void test01()
//{
//	//��ͨʵ�ֲ���
//	Calculator c;
//	c.m_Num1 = 10;
//	c.m_Num2 = 10;
//	cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;
//
//	cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;
//
//	cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
//}



//��̬ʵ��
//�����������
//��̬�ŵ㣺
//1.������֯�ṹ������
//2.�ɶ���ǿ
//3.����ǰ�ںͺ��ڵ���չ�Լ�ά��
class AbstractCalculator
{
	//������
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

//�ӷ�������
class AddCalculator :public AbstractCalculator
{
	//�ӷ�������
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

//�ͷŵ��Ƕ������ڴ棬����ָ����Ȼ����
//����������
class SubCalculator :public AbstractCalculator
{
	//����������
public:
	int getResult()
	{
		return m_Num1 - m_Num2;
	}
};

//�˷�������
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
//	//�����ӷ�������
//	AbstractCalculator* abc = new AddCalculator;
//	abc->m_Num1 = 10;
//	abc->m_Num2 = 10;
//	cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
//	delete abc;  //�����˼ǵ�����
//
//	//��������������
//	abc = new SubCalculator;
//	abc->m_Num1 = 10;
//	abc->m_Num2 = 10;
//	cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
//	delete abc;
//
//	//�����˷�������
//	abc = new MulCalculator;
//	abc->m_Num1 = 10;
//	abc->m_Num2 = 10;
//	cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
//	delete abc;
//}

//https://www.cnblogs.com/daimasanjiaomao/p/13823231.html
