#pragma once


#include <iostream>
#include <vector> 

using namespace std;

/*ClassInternetA and ClassInternetB is parma diliver
 *������֮���ͨѶ
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

