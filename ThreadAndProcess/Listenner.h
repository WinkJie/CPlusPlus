#pragma once
// Demo.cpp : �������̨Ӧ�ó������ڵ㡣
#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string>
#include <list>
using namespace std;
// ����Ĺ۲��ߣ� �������ߣ�
class Listenner
{
public:
	//��ʦ���� �Ҹ���ô��
	virtual void onTeacherComming() = 0;

	//ѧ���ɻ��µķ���
	virtual void doBadthing() = 0;
};

//����� ���۲��ߣ� ��֪ͨ�ߣ�
class Notifier
{
public:
	//���ӹ۲��ߵķ���
	virtual void addListenner(Listenner* listenner) = 0;
	//ɾ���۲��ߵķ���
	virtual void delListenner(Listenner* listenner) = 0;

	//֪ͨ���й۲��ߵķ���
	virtual void notify() = 0;
};

//����Ĺ۲���
class Student :public Listenner
{
public:
	Student(string name, string badthing)
	{
		this->name = name;
		this->badthing = badthing;
	}

	//��ʦ����ѧ������ô��
	virtual void onTeacherComming()
	{
		cout << "ѧ��" << name << "���ְ೤����ʹ�����ˣ� ֹͣ" << badthing << endl;
		cout << "��Ϊд��ҵ" << endl;
	}

	virtual void doBadthing() {
		cout << " ѧ�� " << name << "Ŀǰ���� " << badthing << endl;
	}
private:
	string name;
	string badthing;
};


//�����֪ͨ��(�೤)
class Monitor :public Notifier
{
public:
	//���ӹ۲��ߵķ���
	virtual void addListenner(Listenner* listenner) {
		this->l_list.push_back(listenner);
	}
	//ɾ���۲��ߵķ���
	virtual void delListenner(Listenner* listenner) {
		this->l_list.remove(listenner);
	}

	//֪ͨ���й۲��ߵķ���
	//�೤ʹ����ķ���
	virtual void notify() {
		//�㲥��Ϣ����ÿһ��ѧ����ִ�и��Ե���д��onTeacherComming����
		for (list<Listenner*>::iterator it = l_list.begin(); it != l_list.end(); it++) {
			(*it)->onTeacherComming();
			//�ڴ˴���������೤��notify����
		}
	}
private:
	list<Listenner*> l_list; //�೤�������е�ѧ��(�۲���)
};