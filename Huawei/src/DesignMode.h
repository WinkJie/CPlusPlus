#pragma once
class DesignMode
{
};
/*工厂模式*/
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
	/*auto自动化类型*/
protected:
private:
};
#endif //~_FACTORY_H_ 

#endif // 1


/*抽象工厂模式*/
#if 1
	//苹果的抽象
class AbstractApple {
public:
	virtual void showName() = 0;
};
//中国苹果
class ChinaApple :public AbstractApple {
public:
	ChinaApple()
	{
		this->showName();
	}
	virtual void showName() {
		cout << "中国苹果" << endl;
	}
};
//美国苹果
class USAApple :public AbstractApple {
public:
	virtual void showName() {
		cout << "美国苹果" << endl;
	}
};
//日本苹果
class JapanApple :public AbstractApple {
public:
	virtual void showName() {
		cout << "日本苹果" << endl;
	}
};
//香蕉的抽象
class AbstractBanana {
public:
	virtual void showName() = 0;
};
//中国香蕉
class ChinaBanana :public AbstractBanana {
public:
	ChinaBanana()
	{
		this->showName();
	}
	virtual void showName() {
		cout << "中国香蕉" << endl;
	}
};
//美国香蕉
class USABanana :public AbstractBanana {
public:
	virtual void showName() {
		cout << "美国香蕉" << endl;
	}
};
//日本香蕉
class JapanBanana :public AbstractBanana {
public:
	virtual void showName() {
		cout << "日本香蕉" << endl;
	}
};
//鸭梨的抽象
class AbstractPear {
public:
	virtual void showName() = 0;
};
//中国鸭梨
class ChinaPear :public AbstractPear {
public:
	virtual void showName() {
		cout << "中国鸭梨" << endl;
	}
};
//美国鸭梨
class USAPear :public AbstractPear {
public:
	virtual void showName() {
		cout << "美国鸭梨" << endl;
	}
};
//日本鸭梨
class JapanPear :public AbstractPear {
public:
	virtual void showName() {
		cout << "日本鸭梨" << endl;
	}
};
//抽象工厂  针对产品族  //创建接口函数  隐藏内部数据 数据安全保密
class AbstractFactory {
public:
	virtual AbstractApple* CreateApple() = 0;
	virtual AbstractBanana* CreateBanana() = 0;
	virtual AbstractPear* CreatePear() = 0;
};
//中国工厂      //抽象接口
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
//美国工厂
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
//日本工厂
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


//单例模式
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
//A* A::a = NULL;//懒汉式   对象的创建在第一次调用getInstance函数时创建
//懒汉式是线程不安全的
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
//在类外面进行初始化
//SingletonLazy* SingletonLazy::pSingleton = NULL;//饿汉式    对象在程序执行时优先创建

//饿汉式是线程安全的
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
//以下语句将会在main函数运行前执行
//SingletonHungry* SingletonHungry::pSingleton = new SingletonHungry; 
void test01()
{
	SingletonLazy* p1 = SingletonLazy::getInstance();
	SingletonLazy* p2 = SingletonLazy::getInstance();
	if (p1 == p2)
	{
		cout << "单例模式" << endl;
	}
	else
	{
		cout << "不是单例模式" << endl;
	}
	SingletonHungry* p3 = SingletonHungry::getInstance();
	SingletonHungry* p4 = SingletonHungry::getInstance();
	if (p3 == p4)
	{
		cout << "单例模式" << endl;
	}
	else
	{
		cout << "不是单例模式" << endl;
	}
}

#endif // 0



#endif

