#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
class IPSubnetMask
{
	//IP��ַ����������
	//�������룺SubnetMask
public:
	IPSubnetMask();
public:
	//��ʽһ
	void Do1();
	bool isValidCover(vector<int>& ipCover);
	void myClassify(vector<int>& ans, vector<int>& ip);

	unordered_set<int> validCover = { 0,128,192,224,240,248,252,254,255 };
public:
	//��ʽ��
	void Do2();
	bool split_ip(string ip, int(&num)[4]);
	bool mask_legal(string mask);
	bool ip_ignore(string ip);
	bool ip_legal(string ip);
	bool ip_private(string ip);
	char ip_classify(string ip);




};

