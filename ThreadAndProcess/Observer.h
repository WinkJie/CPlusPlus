#pragma once
#include <iostream>
#include <list>
#include <string>




// Demo.cpp : 定义控制台应用程序的入口点。
#define  _CRT_SECURE_NO_WARNINGS 


using namespace std;
class Observer
{
public:
	Observer() {}
	virtual ~Observer() {}
	virtual void Update() {}
};

class Blog
{
public:
	Blog() {}
	virtual ~Blog() {}
	void Attach(Observer* observer) { m_observers.push_back(observer); }
	void Remove(Observer* observer) { m_observers.remove(observer); }
	void Notidy()
	{
		list<Observer*>::iterator iter = m_observers.begin();
		for (; iter != m_observers.end(); iter++)
		{
			(*iter)->Update();
			
		}
	}
	virtual void SetStatus(string s) { m_status = s; }
	virtual string GetStatus() 
	{ 
		cout << m_status << endl;
		return m_status; 
	}

private:
	list<Observer*> m_observers;

protected:
	string m_status;
};

class BlogCSDN :public Blog
{
private:
	string m_name;
public:
	BlogCSDN(string name) :m_name(name) {}
	~BlogCSDN() {}
	void SetStatus(string s) { m_status = "CSDN通知：" + m_name + s; }
	string GetStatus() { return m_status; }
	
protected:
};
class ObserverBlog :public Observer
{
private:
	string m_name;
	Blog* m_blog;
public:
	ObserverBlog(string name, Blog* blog) :m_name(name), m_blog(blog) {}
	~ObserverBlog() {}
	void Update()
	{
		string status = m_blog->GetStatus();
		cout << m_blog->GetStatus() << endl;
	}

protected:
};






#if 0
int main()
{
	Blog* blog1 = new BlogCSDN("WinkJie is me ");
	Observer* observer = new ObserverBlog("Wink is me also", blog1);
	blog1->Attach(observer);
	blog1->SetStatus("你说呢");
	blog1->Notidy();
	delete blog1;
	delete observer;
	return 0;
}
#endif // 0

