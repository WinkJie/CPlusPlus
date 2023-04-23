#pragma once
// Demo.cpp : 定义控制台应用程序的入口点。
#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string>
#include <list>
using namespace std;
// 抽象的观察者， （监听者）
class Listenner
{
public:
	//老师来了 我改怎么办
	virtual void onTeacherComming() = 0;

	//学生干坏事的方法
	virtual void doBadthing() = 0;
};

//抽象的 被观察者， （通知者）
class Notifier
{
public:
	//添加观察者的方法
	virtual void addListenner(Listenner* listenner) = 0;
	//删除观察者的方法
	virtual void delListenner(Listenner* listenner) = 0;

	//通知所有观察者的方法
	virtual void notify() = 0;
};

//具体的观察者
class Student :public Listenner
{
public:
	Student(string name, string badthing)
	{
		this->name = name;
		this->badthing = badthing;
	}

	//老师来了学生该怎么办
	virtual void onTeacherComming()
	{
		cout << "学生" << name << "发现班长给我使眼神了， 停止" << badthing << endl;
		cout << "改为写作业" << endl;
	}

	virtual void doBadthing() {
		cout << " 学生 " << name << "目前正在 " << badthing << endl;
	}
private:
	string name;
	string badthing;
};


//具体的通知者(班长)
class Monitor :public Notifier
{
public:
	//添加观察者的方法
	virtual void addListenner(Listenner* listenner) {
		this->l_list.push_back(listenner);
	}
	//删除观察者的方法
	virtual void delListenner(Listenner* listenner) {
		this->l_list.remove(listenner);
	}

	//通知所有观察者的方法
	//班长使眼神的方法
	virtual void notify() {
		//广播信息，让每一个学生都执行各自的重写的onTeacherComming方法
		for (list<Listenner*>::iterator it = l_list.begin(); it != l_list.end(); it++) {
			(*it)->onTeacherComming();
			//在此处如果触发班长的notify（）
		}
	}
private:
	list<Listenner*> l_list; //班长手中所有的学生(观察者)
};