#pragma once

#include <string>
#include <iostream>
#include <Windows.h>

//#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <string>
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
	void findNumOfBinary(unsigned int nums);
	//n����ת��
	string Baseconversion(unsigned int num, int decimal); //ʧ��
public:
	

};

