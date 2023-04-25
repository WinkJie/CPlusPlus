#pragma once


#include <iostream>
#include <vector> 

using namespace std;

/*ClassInternetA and ClassInternetB is parma diliver
 *类与类之间的通讯
 */

class ClassInternetA;

class ClassInternetB 
{
public:
	//ClassInternetB();
	ClassInternetB(string str,int x);
	void CoutLog(string str, int x);

private:

	ClassInternetA* A;//= new ClassInternetA();


};

