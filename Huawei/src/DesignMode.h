#pragma once
class DesignMode
{
};
/*����ģʽ*/
#if 1
//Product.h 
#ifndef _PRODUCT_H_ 
#define _PRODUCT_H_ 
#include <iostream>
using namespace std;
class Product
{
public:
	virtual ~Product() = 0;

protected:
	Product();
private:
};
class ConcreteProduct :public Product
{
public:
	~ConcreteProduct();
	ConcreteProduct();

protected:
private:
};
#endif //~_PRODUCT_H_

//Factory.h 
#ifndef _FACTORY_H_ 
#define _FACTORY_H_ 
class Product;
class Factory
{
public:
	virtual ~Factory() = 0;
	virtual Product* CreateProduct() = 0;
protected:
	Factory();
private:
};
class ConcreteFactory :public Factory
{
public:
	~ConcreteFactory();
	ConcreteFactory();
	Product* CreateProduct();
	/*auto�Զ�������*/
protected:
private:
};
#endif //~_FACTORY_H_ 

#endif // 1


/*���󹤳�ģʽ*/
#if 1
	//ƻ���ĳ���
class AbstractApple {
public:
	virtual void showName() = 0;
};
//�й�ƻ��
class ChinaApple :public AbstractApple {
public:
	ChinaApple()
	{
		this->showName();
	}
	virtual void showName() {
		cout << "�й�ƻ��" << endl;
	}
};
//����ƻ��
class USAApple :public AbstractApple {
public:
	virtual void showName() {
		cout << "����ƻ��" << endl;
	}
};
//�ձ�ƻ��
class JapanApple :public AbstractApple {
public:
	virtual void showName() {
		cout << "�ձ�ƻ��" << endl;
	}
};
//�㽶�ĳ���
class AbstractBanana {
public:
	virtual void showName() = 0;
};
//�й��㽶
class ChinaBanana :public AbstractBanana {
public:
	ChinaBanana()
	{
		this->showName();
	}
	virtual void showName() {
		cout << "�й��㽶" << endl;
	}
};
//�����㽶
class USABanana :public AbstractBanana {
public:
	virtual void showName() {
		cout << "�����㽶" << endl;
	}
};
//�ձ��㽶
class JapanBanana :public AbstractBanana {
public:
	virtual void showName() {
		cout << "�ձ��㽶" << endl;
	}
};
//Ѽ��ĳ���
class AbstractPear {
public:
	virtual void showName() = 0;
};
//�й�Ѽ��
class ChinaPear :public AbstractPear {
public:
	virtual void showName() {
		cout << "�й�Ѽ��" << endl;
	}
};
//����Ѽ��
class USAPear :public AbstractPear {
public:
	virtual void showName() {
		cout << "����Ѽ��" << endl;
	}
};
//�ձ�Ѽ��
class JapanPear :public AbstractPear {
public:
	virtual void showName() {
		cout << "�ձ�Ѽ��" << endl;
	}
};
//���󹤳�  ��Բ�Ʒ��  //�����ӿں���  �����ڲ����� ���ݰ�ȫ����
class AbstractFactory {
public:
	virtual AbstractApple* CreateApple() = 0;
	virtual AbstractBanana* CreateBanana() = 0;
	virtual AbstractPear* CreatePear() = 0;
};
//�й�����      //����ӿ�
class ChinaFactory :public AbstractFactory {
	virtual AbstractApple* CreateApple() {
		return new ChinaApple;
	}
	virtual AbstractBanana* CreateBanana() {
		return new ChinaBanana;
	}
	virtual AbstractPear* CreatePear() {
		return new ChinaPear;
	}
};
//��������
class USAFactory :public AbstractFactory {
	virtual AbstractApple* CreateApple() {
		return new USAApple;
	}
	virtual AbstractBanana* CreateBanana() {
		return new USABanana;
	}
	virtual AbstractPear* CreatePear() {
		return new USAPear;
	}
};
//�ձ�����
class JapanFactory :public AbstractFactory {
	virtual AbstractApple* CreateApple() {
		return new JapanApple;
	}
	virtual AbstractBanana* CreateBanana() {
		return new JapanBanana;
	}
	virtual AbstractPear* CreatePear() {
		return new JapanPear;
	}
};

#if 0


//����ģʽ
class Singleton
{
public:


private:
	Singleton();

};


class A
{
public:
	static A* getInstace()
	{
		return a;
	}
private:
	A()
	{
		a = new A;
	}
	static A* a;
};
//A* A::a = NULL;//����ʽ   ����Ĵ����ڵ�һ�ε���getInstance����ʱ����
//����ʽ���̲߳���ȫ��
class SingletonLazy
{
public:
	static SingletonLazy* getInstance()
	{
		if (pSingleton == NULL)
		{
			pSingleton = new SingletonLazy;
		}
		return pSingleton;
	}
private:
	SingletonLazy()
	{}
	static SingletonLazy* pSingleton;
};
//����������г�ʼ��
//SingletonLazy* SingletonLazy::pSingleton = NULL;//����ʽ    �����ڳ���ִ��ʱ���ȴ���

//����ʽ���̰߳�ȫ��
class SingletonHungry
{
public:
	static SingletonHungry* getInstance()
	{
		return pSingleton;
	}
	static void freeSpace()
	{
		if (pSingleton != NULL)
		{
			delete pSingleton;
		}
	}
private:
	SingletonHungry()
	{}
	static SingletonHungry* pSingleton;
};
//������佫����main��������ǰִ��
//SingletonHungry* SingletonHungry::pSingleton = new SingletonHungry; 
void test01()
{
	SingletonLazy* p1 = SingletonLazy::getInstance();
	SingletonLazy* p2 = SingletonLazy::getInstance();
	if (p1 == p2)
	{
		cout << "����ģʽ" << endl;
	}
	else
	{
		cout << "���ǵ���ģʽ" << endl;
	}
	SingletonHungry* p3 = SingletonHungry::getInstance();
	SingletonHungry* p4 = SingletonHungry::getInstance();
	if (p3 == p4)
	{
		cout << "����ģʽ" << endl;
	}
	else
	{
		cout << "���ǵ���ģʽ" << endl;
	}
}

#endif // 0



#endif

