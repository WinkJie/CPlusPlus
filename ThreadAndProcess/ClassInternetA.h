#pragma once

/*ClassInternetA and ClassInternetB is parma diliver
 *类与类之间的通讯
 */

/*2022年10月4日06:24:00*/
#include <iostream>
#include <thread>
#include <mutex>
#include "ClassInternetB.h"
using namespace std;


//mutex m;
class ClassInternetA
{
public:
	ClassInternetA();

	void size();
	static void test();
	void thre()
	{
		for (int i = 0; i < 5; i++)
		{
			//m.lock();
			std::cout << "thread :" << i << "\n";
			//m.unlock();
		}
	}
	//void threadTest() 
	//{
	//	std::thread t1(thre);
	//	std::thread t2(run);
	//	t1.join();
	//	t2.join();
	//	std::cin.get();
	//}
	//ClassInternetB* B;

private:
	int pro;


};

