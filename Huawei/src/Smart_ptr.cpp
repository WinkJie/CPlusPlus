#include "Smart_ptr.h"

Smart_ptr::Smart_ptr(string nameTmp)
{
	name = nameTmp;
	cout << "Node constructor, name=" << name.c_str() << endl;

}

Smart_ptr::~Smart_ptr()
{
	cout << "Node destructor, name=" << name.c_str() << endl;
}

void Smart_ptr::LeakTest()
{
	// 创建内存块 M_N1
	auto n1 = make_shared<Smart_ptr>("n1");
	// 创建内存块 M_N2
	auto n2 = make_shared<Smart_ptr>("n2");
	cout << "n1.ref=" << n1.use_count() << ", n2.ref=" << n2.use_count() << endl;
	
	n1->next = n2;
	cout << "n1.ref=" << n1.use_count() << ", n2.ref=" << n2.use_count() << endl;
	
	n2->next = n1;
	// M_N1.ref==2, M_N2.ref==2;
	cout << "n1.ref=" << n1.use_count() << ", n2.ref=" << n2.use_count() << endl;
	// 1. n1先销毁, 则M_N1的内存引用计数变为1, 还被n2->next引用
	// 2. n2销毁, 则M_N2的内存引用计数变为1, 还被n1->next引用
	// 3. 产生内存泄露
	
	/// 最终输出
	/// Node constructor, name=n1
	/// Node constructor, name = n2
	/// n1.ref = 1, n2.ref = 1
	/// n1.ref = 1, n2.ref = 2
	/// n1.ref = 2, n2.ref = 2
}

void Smart_ptr::NormalTestN1()
{
	// 创建内存块 M_N1
	auto n1 = make_shared<Smart_ptr>("n1");
	// 创建内存块 M_N2
	auto n2 = make_shared<Smart_ptr>("n2");
	cout << "n1.ref=" << n1.use_count() << ", n2.ref=" << n2.use_count() << endl;
	
	n1->next = n2;
	// M_N1.ref==1, M_N2.ref==2;
	cout << "n1.ref=" << n1.use_count() << ", n2.ref=" << n2.use_count() << endl;
	// 1. n1先销毁, 则M_N1的内存引用计数变为0, 内存块M_N1需要销毁, 则此时会走到了n1的析构方法, n1析构时n1->next也被销毁, 此时n1->next(即内存块M_N2)引用计数变为1
	// 2. n2销毁, 则M_N2的内存引用计数变为0, 内存块M_N2需要销毁
	// 3. 无内存泄露
	
	/// 最终输出
	/// Node constructor, name=n1
	/// Node constructor, name = n2
	/// n1.ref = 1, n2.ref = 1
	/// n1.ref = 1, n2.ref = 2
	/// Node destructor, name = n1
	/// Node destructor, name = n2
}

void Smart_ptr::NormalTestN2()
{
	// 创建内存块 M_N1
	auto n1 = make_shared<Smart_ptr>("n1");
	// 创建内存块 M_N2
	    auto n2 = make_shared<Smart_ptr>("n2");
	cout << "n1.ref=" << n1.use_count() << ", n2.ref=" << n2.use_count() << endl;
	
	n2->next = n1;
	// M_N1.ref==1, M_N2.ref==2;
	cout << "n1.ref=" << n1.use_count() << ", n2.ref=" << n2.use_count() << endl;
	// 1. n1先销毁, 则M_N1的内存引用计数变为1
	// 2. n2销毁, 则M_N2的内存引用计数变为0, 内存块M_N2需要销毁, 则此时会走到了n2的析构方法, n2析构时n2->next也被销毁, 此时n2->next(即内存块M_N1)引用计数变为0
	// 3. 此时M_N1被销毁, 走到M_N1的析构函数
	// 4. 无内存泄露
	
	/// 最终输出
	/// Node constructor, name=n1
	/// Node constructor, name = n2
	/// n1.ref = 1, n2.ref = 1
	/// n1.ref = 2, n2.ref = 1
	/// Node destructor, name = n2
	 /// Node destructor, name = n1
}
