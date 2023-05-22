#include <iostream>
#include <thread>
#include <atomic>
#include <time.h>
#include <mutex>
#include<stdio.h>
//#include<unistd.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <chrono>
#include <future>

#include "src/BaseHide.h"
#include "src/CopyConstructor.h"
#include "src/TestDaily.h"
#include "src/Log.h"
#include "src/DesignMode.h"
#include "src/BinToHex.h"
#include "src/CanGuanProcess.h"
#include "src/DailyBase.h"
#include "src/Linear_List.h"
#include "src/Smart_ptr.h"
#include "src/ThreadAndProcess.h"
#include "src/ClassInternetB.h"
#include "src/Calculator.h"
#include "src/ThreadAndProcess.h"
#include "src/Observer.h"
#include "src/Listenner.h"
#include "src/BasicAlgorithm.h"
#include "src/IPSubnetMask.h"
#include "src/ListNode.h"
#include "src/SuZhouTongYuan.h"
#include "src/HuaweiDaily.h"
#include "src/delipse.h"

//#include "../ThreadAndProcess/include/opencv/cv.h"
//#include "../ThreadAndProcess/include/opencv/cv.hpp"
//#include "../ThreadAndProcess/include/opencv2/objdetect.hpp"
#include "src/include/opencv/cv.h"
#include "src/include/opencv/cv.hpp"
#include "src/include/opencv2/objdetect.hpp"

using namespace std;
//struct ListNode
//{
//	int val;
//	struct ListNode* next;
//};
//ListNode* reset(ListNode* head,int k)
//{// write code here
//	if (!head)
//	{
//		return nullptr;
//	}
//	vector<ListNode*> v;
//	vector<ListNode*> end;
//	while (head)
//	{
//		v.push_back(head);
//		head = head->next;
//	}
//	int flag = fmod(v.size(), k);  //求余数
//	int flag1 = ceil(v.size() / k);//向下取整的结果
//	if (flag > 0 && flag < k )
//	{
//		for (int i = 0; i < flag1-1; i++)
//		{
//			int start = i * k;
//			int _end = (i + 1) * k;
//			reverse(v[start], v[_end]);
//			for (int j = 0; j < k; j++)
//			{
//				end.push_back(v[j]);
//			}
//		}
//		int start_op = (flag1 - 1) * k;
//		int end_op = (flag1 - 1) * k + flag - 1;
//		reverse(v[start_op], v[end_op]);
//		for (size_t i = 0; i < flag; i++)
//		{
//			end.push_back(v[(flag1-1)*k+i]);
//		}
//	}
//	else
//	{
//		for (int i = 0; i < flag1; i++)
//		{
//			reverse(v[i*k], v[(i+1)*k]);
//			for (int j = 0; j < k; j++)
//			{
//				end.push_back(v[j]);
//			}
//		}
//	}
//	ListNode* ops = v[0];
//	ListNode* iop = ops;
//	for (int i = 0; i < v.size(); i++)
//	{
//		iop = v[i];
//		iop = iop->next;
//	}
//	iop->next = nullptr;
//	return iop;
//}

bool Input(vector<string>& arr)
{
	string input;
	//vector<string>arr;
	bool flag = true;
	cin >> input;
	if ("x" != input)
	{
		arr.push_back(input);
		cout << "arr.size() is " << arr.size() << endl;
		cout << "length() is " << arr[arr.size() - 1].length() << endl;
	}
	else
	{
		flag = false;
	}
	return flag;
}
bool Inputs(vector<string>& arr)
{
	string input;
	//vector<string>arr;
	bool flag = true;
	if (cin >> input)
	{
		arr.push_back(input);
		//cout << "arr.size() is " << arr.size() << endl;
		//cout << "length() is " << arr[arr.size() - 1].length() << endl;
		if (arr[arr.size() - 1] == "x")
		{
			flag = false;
		}
	}
	else
	{
		flag = false;
	}
	return flag;
}

int ObserverTest12(void)
{
	//观察者模式
	Listenner* s1 = new Student("张三", "抄作业");
	Listenner* s2 = new Student("李四", "打lol");
	Listenner* s3 = new Student("王五", " 看李四玩lol");
	Notifier* bossXu = new Monitor;
	//将所有的学生列表告知通知者，好让通知者进行通知 
	bossXu->addListenner(s1);
	bossXu->addListenner(s2);
	bossXu->addListenner(s3);

	cout << "教师一片和谐，老师没有来 " << endl;
	s1->doBadthing();
	s2->doBadthing();
	s3->doBadthing();

	cout << "班长突然发现老师来了，给学生们使了一个眼神" << endl;
	bossXu->notify();
	return 0;
}
//原子操作，没发现什么好的事情
#if 1
//1.have atomic
atomic<int> g_count;

//2.no atomic
//int g_count = 0;

void work(string &str)
{
	for (int i = 0; i < 1000; i++)
	{
		g_count++;
		cout << str << " is " << g_count << "   ";
	}
	cout << endl;
}

void AtomicOperater()
{
	std::thread t1(work, "线程1");
	std::thread t2(work, "线程2");
	t1.join();
	t2.join();

	//如果没有使用atomic原子定义，打印的值是随机，是乱的
	cout << "g_count =  " << g_count << endl;
}

#endif // 1



int main(int argc, char* argv[])
{
#if 0
	delipse* a = new delipse;
	a->cpucomputerthread();
#endif // 1

#if 0
	HuaweiDaily a;
	//a.findNumOfBinary(10);
	a.findNumOfBinary32();
	a.findNumOfBinary64();
	/*a.RandomNumber();
	a.countword();
	a.PrintLastWord();
	a.StringSplite();*/
	/*unsigned int decimal = 123;
	cin >> decimal;
	a.findNumOfBinary(decimal);
	
	std::string binary = a.BaseConversion(decimal);
	std::cout << "The binary representation of " << decimal << " is " << binary << std::endl;
	a.findNumSetBitset();*/

#endif // 1

#if 0
	cout << 1 << endl;
	SuZhouTongYuan* a = new SuZhouTongYuan;
	cout << 2 << endl << endl << endl;
	SuZhouTongYuan b;
	b.Do();
	cout << 3 << endl;

#endif
#if 0
	ListNode* a = nullptr;
	a->insertNode(0, 0);
	a->insertNode(1, 1);
	a->insertNode(2, 2);
	a->insertNode(3, 3);
	a->ReserverList();
	ListNode* next = nullptr;
	if (a)
	{
		next = a->next;
		cout << a->data << endl;
		a = next;
	}
#endif
#if 0
	IPSubnetMask* a = NULL;
	a->Do1();
#endif // 1

#if 0
	string a;
	getline(cin, a);
	int n = a.length();
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] != ' ')
		{
			num++;
		}
		else
		{
			num = 0;
		}
	}
	cout << num << endl;
#endif
#if 0
	string a, b;
	while (cin >> a)
	{
		b.swap(a);
	}
	cout << "ops:" << b.size() << endl;
#endif
#if 0
	AtomicOperater();

#endif // 1

#if 0
	BasicAlgorithm a;
	a.automic_test();

	//ObserverTest12();
#endif // 1

#if 0
	Blog* blog1 = new BlogCSDN("WinkJie is me ");
	Observer* observer = new ObserverBlog("Wink is me also", blog1);
	blog1->Attach(observer);
	blog1->SetStatus("你说呢");
	blog1->Notidy();
	delete blog1;
	delete observer;
#endif // 1	
#if 0
	/*多线程*/
	ThreadAndProcess* a = new ThreadAndProcess();
	a->pointerFun1();
#endif // 1

#if 0
	UdpDoubleCommit* Udp = new UdpDoubleCommit();

#endif // 1

#if 0
	/*C++各个版本的特性测试*/
	vector<int> a{ 1,5,2,3,6,5,4,8 };
	for (auto i : a)
	{
		/*cout\cerr\clog之间的区别与联系
		* cout是会开辟一个缓冲区，在遇到程序结束或者换行符号或者endl后会刷新缓冲区，而且可以重定向
		* 为什么会有cerr和clog？
		* 程序遇到栈调用完了的威胁，我们没有内存存放我们的错误提示
		* 这个时候就有了cerr，目的是在非常紧急的情况下，还能得到输出功能的支持
		* 缓冲区的目的就是减少刷屏的次数
		*/
		cout << "cout is " << i << endl;
		cerr << "cerr is " << i << endl;
		clog << "clog is " << i << endl;
		clog << std::flush;
	}
#endif // 1

#if 0
	cout << argc << endl;
	for (int i = 0; i < argc; i++)
	{
		cout << argv[i] << endl;
	}
	BinToHex a(argc, argv);// = new BinToHex(argc, argv);
	//a.Do(argc, argv);
#endif // 1

#if 0
	int te = 1;
	cout << "this is :" << (te << 12) << endl;
	//1 2 4 8 16 32 64 128 256 512 1024 2048 4096 
#endif // 0

#if 0
	vector<string> tmp;

	while (true)
	{
		if (!Inputs(tmp))
			break;
		cout << tmp.size() << endl;
		cout << tmp[tmp.size() - 1] << endl;
		cout << tmp[tmp.size() - 1].length() << endl;
		cout << "----------------" << endl;

	}

#endif // 0

#if 0
	/*Factory* fac = new ConcreteFactory();
	fac->CreateProduct();
	Product* p = fac->CreateProduct();*/

	//AbstractFactoryOutput();
		//抽象工厂模式
	AbstractFactory* factory = NULL;
	AbstractApple* apple = NULL;
	AbstractBanana* Banana = NULL;
	AbstractPear* Pear = NULL;
	factory = new ChinaFactory;
	apple = factory->CreateApple();
	Banana = factory->CreateBanana();
	Pear = factory->CreatePear();
	apple->showName();
	Banana->showName();
	Pear->showName();
	delete Pear;
	delete apple;
	delete Banana;
	delete factory;	
	//CopyConstructor a;
	//SimilarRects
#endif // 1

#if 0
	CopyConstructor a;
	a.InlineTest();
	sort();
	stable_sort();
#endif // 0
#if 0
	//int[] arri = { 1,5,2,63,59,2,5 }; //Java写法
	int arr[] = { 1, 5, 6, 0, 7, 4, 9, 3 };
	int index[] = { 0, 1, 2, 3, 4, 0, 5, 0, 5, 6, 7 };
	int aop[56] = { 4,5,6,8,9 };
	string tel = "";
	for (int i : aop)
		tel += to_string(arr[i]);
	cout << tel << endl;
#endif // 1

#if 0
	/*拷贝构造函数
	 *如果没有自定义的拷贝构造函数，编译器有默认的
	 *
	 */
#if 0
	CopyConstructor s1;
	cout << "s1:" << endl;
	CopyConstructor s2(s1);  //拷贝构造函数的使用
	cout << "s2:" << endl;
	CopyConstructor s3 = s2; //拷贝构造函数的调用
	cout << "s3:" << endl;
	//cout << s1.GetNumber() << endl;
	//cout << s2.GetNumber() << endl;
	//cout << s3.GetNumber() << endl;
	ShowNumber(s2);
	ShowNumber(s1);
	ShowNumber(s3);
#endif // 0
	CopyConstructor s1(2);
	CopyConstructor s2(s1);
	s1.printop();
	delete s1.pointer;
	s2.printop();
	//sizeOp();

#endif // 1

#if 0	
	/*常量指针与常量指针
	 *
	 *
	 */
	int IntNum = 50;
	int IntNum1 = 60;
	const int* p = &IntNum; //常量指针
	cout << "初始化为:" << *p << "  ++" << p << endl;
	IntNum = 90;
	p = &IntNum1;
	cout << "改变后的值为：" << *p << "  ++" << p << endl;
	int* const q = &IntNum; //指针常量
	cout << "指针常量初始化：" << *q << "  ++" << q << endl;
	*q = IntNum1;

	cout << "指针常量改变后：" << *q << "  ++" << q << endl;
	int const* const L = &IntNum;
	cout << "常指针常量初始化：" << *L << "  ++" << L << endl;
	IntNum = 565;
	cout << "常指针常量改变后：" << *L << "  ++" << L << endl;

	BaseHide* a;
	a = new SonBaseHide;
	//a->BaseHide::m_op = 99;
	a->m_op = 100;
	a->m_ops();
	cout << "SonBaseHide子类中的公有变量为：" << a->m_op << endl;
	//a->Over(5);
	//a->OverWrite(6);
	a->overridetest();
	a = new BaseHide;
	a->BaseHide::m_op = 99;
	//a->Over(5);
	//a->OverWrite(6);
	cout << "BaseHide基类中的公有变量为：" << a->m_op << endl;

	a->m_ops();
	a->overridetest();
	SonBaseHide b;
	b.overridetest();
	b.m_ops();
	cout << "SonBaseHide子类中的公有变量为：" << b.m_op << endl;

	//给同名变量赋值时需要使用域名作用符区分赋值变量
	SonBaseHide c;
	c.BaseHide::m_op = 65;
	c.SonBaseHide::m_op = 99;
#endif // 0
#if 0	
	/*func SonBaseHide:
	 *func1 SonBaseHide:
	 *foo BaseHide:
	 *
	 *func BaseHide:
	 *func1 BaseHide:
	 *foo BaseHide:
	 */

	 /*多态的类调用如果没有关键字virtual
	  *那么C++就不能成为多态，但是在Java中是可以通过重写基类来实现多态的
	  *
	  */
	  /*
	  Java中实现类多态的方式
	  public class Main {
		  public static class Base
		  {
			  public void test() {
				  System.out.println("test base");
			  }
		  }
		  public static class Derive extends Base {
			  public void test() {
				  System.out.println("test Derive");
			  }
		  }
		  public static void main(String[] args) {
			  Derive d = new Derive();
			  Base b = d;
			  d.test();
			  b.test();//和C++效果一样
		  }
	  }
	  */
	  //char str[15];// = { 1,2,3,4,5,6,7,8 }
	char str[30] = "good morning \0 everybody";
	printf(" str = %s  strlen(str) = %d \n", str, strlen(str));
	cout << strlen(str) << "-----" << sizeof(str) << endl;

	cout << "------------------------------------------" << endl;
	BaseHide* a;
	SonBaseHide b;
	b.Test();
	cout << endl << "------------------------------------------" << endl;
	a = &b;
	a->func();
	a->func1();
	a->foo();
	cout << "------------------------------------------" << endl;
	b.func();
	b.func1();
	b.foo();
	cout << "------------------------------------------" << endl;
	BaseHide c;
	a = &c;
	a->func();
	a->func1();
	a->foo();
	cout << "------------------------------------------" << endl;
	BaseHide* op = &b;
	op->print();

	//SonBaseHide c;
	//c.SonSize();
	//SonBaseHide* d = new SonBaseHide;
	//d->SonSize();	
#endif // 1

#if 0
	BaseHide a;
	a.Over(2);
	a.OverWrite(5);
	SonBaseHide b;
	b.Over();
	b.OverWrite(6);
	Log A;
	A.Open("asda.txt");
	A.LogOutLn("sdsd");
	A << "sdfsd";
#endif // 1

#if 0
	for (;;)
	{
		Smart_ptr* ptr = NULL;
		cout << "\n==========LeakTest Begin==========" << endl;
		ptr->LeakTest();
		cout << "==========LeakTest End==========" << endl;

		cout << "\n==========NormalTestN1 Begin==========" << endl;
		ptr->NormalTestN1();
		cout << "==========NormalTestN1 End==========" << endl;

		cout << "\n==========NormalTestN2 Begin==========" << endl;
		ptr->NormalTestN2();
		cout << "==========NormalTestN2 End==========" << endl;
	}
#endif // 0   智能指针

#if 0
	//共享指针  实现机制

	Test_Pointer<int> testint(new int(2));
	Test_Pointer<int> testint1 = testint;
	Test_Pointer<int> testint2 = testint1;
	Test_Pointer<int> testint3 = testint;//指向到此处可以看到4个类对象共享类指针地址与共享计数相同
	testint.Reset();					 //共享计数减一 并且共享类指针地址与共享计数地址赋值为0
	testint1.Reset(new int(4));			 //共享计数减一 并且共享类指针地址与共享计数地址赋值为0
										 //然后分配新的共享类指针内存与共享计数
	testint1.SetCritical(0);			 //

	Test_Pointer<string> teststr("ceshiyixia");
	teststr.Reset();

#endif // 1


#if 0
	//创建加法计算器
	AbstractCalculator* abc = new AddCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;  //用完了记得销毁

	//创建减法计算器
	abc = new SubCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;

	//创建乘法计算器
	abc = new MulCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;
	//创建除法计算器
	abc = new DivisionCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 4;
	abc->str1 = "WinkJie";
	abc->str2 = "DiXiaoQing";
	cout << abc->m_Num1 << " / " << abc->m_Num2 << " = " << abc->getResult() << endl;
	cout << abc->sizeokasd() << endl;
	delete abc;


#endif // 1  多肽的实现

#if 0
	string name1 = "stringasd";
	string name2 = "WInkJie";
	ClassInternetB Ba(name1, 1);// = new ClassInternetB(name1, 1);
	ClassInternetB Bb(name2, 2);// = new ClassInternetB(name2, 2);
	vector<ClassInternetB> op;
	op.push_back(Ba);
	op.push_back(Bb);

	cout << op.size() << endl;

	ClassInternetB iop = op[0];
	//iop.CoutLog(name1, 3);
	//thread t1(B);
	//t1.join();

#endif // 0   类与类之间的信息交换

#if 0

	int _pipe[2] = { 0,0 };
	int ret = pipe(_pipe); //创建管道
	if (ret == -1)
	{
		perror("create pipe error");
		return 1;
	}
	printf("_pipe[0] is %d,_pipe[1] is %d\n", _pipe[0], _pipe[1]);
	pid_t id = fork(); //父进程fork子进程
	if (id < 0)
	{
		perror("fork error");
		return 2;
	}
	else if (id == 0) //child,写
	{
		printf("child writing\n");
		close(_pipe[0]);
		int count = 5;
		const char* msg = "i am from XATU";
		while (count--)
		{
			write(_pipe[1], msg, strlen(msg));
			sleep(1);
		}
		close(_pipe[1]);
		exit(1);
	}
	else //father,读
	{
		printf("father reading\n");
		close(_pipe[1]);
		char msg[1024];
		int count = 5;
		while (count--)
		{
			ssize_t s = read(_pipe[0], msg, sizeof(msg) - 1);
			if (s > 0) {
				msg[s] = '\0';
				printf("client# %s\n", msg);
			}
			else {
				perror("read error");
				exit(1);
			}
		}
		if (waitpid(id, 0, NULL) != -1) {
			printf("wait success\n");
		}
	}

#endif // 1   pipe管道进程之间的通信	

	/*CanGuanProcess canguan;
	canguan.vec();
	for (auto s : canguan.global)
		cout << s << "       " << endl;
	DailyBase a;
	a.opOne(canguan.global);
	for (auto l : a.ops)
		cout << l << "    " << endl;
	DailyBase::begin4();*/
	//静态函数
	/*类与类之间的通信*/
	//ClassInternetB *B = new ClassInternetB();	
	//ClassInternetA *A;	
	return 0;
}