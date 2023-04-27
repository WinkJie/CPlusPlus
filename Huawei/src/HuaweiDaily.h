#pragma once

#include <string>
#include <iostream>
#include <Windows.h>

//#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <bitset>
#include <vector>
//#include <Windows.h>

//牛客练习华为机试
using namespace std;



class HuaweiDaily
{
public:
	//字符串转换
	void print(string& str);
	void toString(string& str);
	string StringToGBK(string& str);

	//字符串最后一个单词的长度
	void PrintLastWord();
	//计算某字符出现的次数
	void countword();
	//明明的随机数
	void RandomNumber();
	//字符串分割
	void StringSplite();
	//十进制与二进制的转换
	string BaseConversion(unsigned int num);
	//寻找转为二进制后的字符串有多少个1
	void findNumOfBinary(unsigned int nums);
	//n进制转换
	string Baseconversion(unsigned int num, int decimal); //失败
	//使用bitset寻找二进制中的1数量
	void findNumSetBitset();
	//寻找DNA中子序列占比最高的子串
	string findGCSubstr(string &dna, int n);
	void findDna();
	//收拾旧瓶子算法
	//int 
	vector<int> printNumbers(int n);
	

public:
	

};

