#include "ClassInternetB.h"
#include "ClassInternetA.h"
//#include "Linear_List.h"




//ClassInternetB::ClassInternetB()
//{
//	A = new ClassInternetA;
//	
//	//this->A->threadTest();
//	//this->A = new ClassInternetA();
//	//this->A->size();
//}

ClassInternetB::ClassInternetB(string str,int x)
{
	this->CoutLog(str, x);
}

void ClassInternetB::CoutLog(string str, int x)
{
	A = new ClassInternetA;
	cout << str << "    is  :" << x << endl;
}

