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

//ţ����ϰ��Ϊ����
using namespace std;



class HuaweiDaily
{
public:
	//�ַ���ת��
	void print(string& str);
	void toString(string& str);
	string StringToGBK(string& str);

	//�ַ������һ�����ʵĳ���
	void PrintLastWord();
	//����ĳ�ַ����ֵĴ���
	void countword();
	//�����������
	void RandomNumber();
	//�ַ����ָ�
	void StringSplite();
	//ʮ����������Ƶ�ת��
	string BaseConversion(unsigned int num);
	//Ѱ��תΪ�����ƺ���ַ����ж��ٸ�1
	void findNumOfBinary(unsigned int nums);
	//n����ת��
	string Baseconversion(unsigned int num, int decimal); //ʧ��
	//ʹ��bitsetѰ�Ҷ������е�1����
	void findNumSetBitset();
	//Ѱ��DNA��������ռ����ߵ��Ӵ�
	string findGCSubstr(string &dna, int n);
	void findDna();
	//��ʰ��ƿ���㷨
	//int 
	vector<int> printNumbers(int n);
	

public:
	

};

