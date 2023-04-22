#include "IPSubnetMask.h"

IPSubnetMask::IPSubnetMask()
{

}

bool IPSubnetMask::isValidCover(vector<int>& ipCover) {
	for (int i = 0; i < 4; i++) {
		if (!validCover.count(ipCover[i])) {
			return 0;
		}
		if (ipCover[i] != 255) {
			for (int j = i + 1; j < 4; j++) {
				if (ipCover[j] != 0) {
					return 0;
				}
			}
			break;
		}
	}
	if (ipCover[0] == 0) {
		return 0;
	}
	if (ipCover[3] == 255) {
		return 0;
	}
	return 1;
}
void IPSubnetMask::myClassify(vector<int>& ans, vector<int>& ip) {
	if (ip[0] >= 1 && ip[0] <= 126) {
		ans[0]++;
		if (ip[0] == 10) {
			ans[6]++;
		}
	}
	else if (ip[0] >= 128 && ip[0] <= 191) {
		ans[1]++;
		if (ip[0] == 172 && ip[1] >= 16 && ip[1] <= 31) {
			ans[6]++;
		}
	}
	else if (ip[0] >= 192 && ip[0] <= 223) {
		ans[2]++;
		if (ip[0] == 192 && ip[1] == 168) {
			ans[6]++;
		}
	}
	else if (ip[0] >= 224 && ip[0] <= 239) {
		ans[3]++;
	}
	else {
		ans[4]++;
	}
}
void IPSubnetMask::Do1() {
	string str;
	vector<int>ans(7, 0), ip, ipCover;
	int left = 0, right = 0, temp;
	bool isValid = 1;
	while (cin >> str) 
	{
		left = 0;
		right = 0;
		isValid = 1;
		ip.clear();
		ipCover.clear();
		for (; str[right] != '~'; right++) {
			if (str[right] == '.') {
				if (right == left) {
					isValid = 0;
					break;
				}
				temp = stoi(str.substr(left, right - left));
				ip.push_back(temp);
				left = right + 1;
			}
		}
		if (!isValid) {
			ans[5]++;
			continue;
		}
		if (right == left) {
			ans[5]++;
			continue;
		}
		temp = stoi(str.substr(left, right - left));
		ip.push_back(temp);
		if (ip[0] == 0 || ip[0] == 127) {
			continue;
		}

		left = right + 1;
		right++;
		isValid = 1;

		for (; right < str.size(); right++) {
			if (str[right] == '.') {
				if (right == left) {
					isValid = 0;
					break;
				}
				temp = stoi(str.substr(left, right - left));
				ipCover.push_back(temp);
				left = right + 1;
			}
		}
		if (!isValid) {
			ans[5]++;
			continue;
		}
		if (right == left) {
			ans[5]++;
			continue;
		}
		temp = stoi(str.substr(left, right - left));
		ipCover.push_back(temp);
		if (!isValidCover(ipCover)) {
			ans[5]++;
			continue;
		}
		myClassify(ans, ip);		
	}
	for (int i = 0; i < 7; i++) {
		cout << ans[i] << ' ';
	}
}
void IPSubnetMask::Do2()
{
	int A = 0, B = 0, C = 0, D = 0, E = 0, err = 0, p = 0;
	string str;	
	cin >> str;
	while (cin >> str) 
	{		
		//将字符串按"~"分为IP、掩码
		string ip, mask;
		auto pos = str.find('~');
		ip = str.substr(0, pos);
		mask = str.substr(pos + 1);

		// 类似于【0.*.*.*】和【127.*.*.*】计数时请忽略
		if (ip_ignore(ip)) {
			continue;
		}

		// 如果掩码非法，错误IP地址或错误掩码个数+1
		else if (!mask_legal(mask)) {
			err++;
		}

		// 如果ip非法，错误IP地址或错误掩码个数+1
		else if (!ip_legal(ip)) {
			err++;
		}
		// 判断ip类别或者是否是私网
		else {
			// 判断ip是否是私网
			if (ip_private(ip)) 
			{
				p++;
			}
			// 判断ip类别
			switch (ip_classify(ip)) 
			{
			case 'A':
				A++;
				break;
			case 'B':
				B++;
				break;
			case 'C':
				C++;
				break;
			case 'D':
				D++;
				break;
			case 'E':
				E++;
				break;
			default:
				break;
			}
		}		
	}
	cout << A << " " << B << " " << C << " " << D << " " << E << " " << err << " " << p;
}
bool IPSubnetMask::split_ip(string ip, int(&num)[4])
{
	int n = 0; //记录"."的个数
	ip += ".";
	auto pos = ip.find('.');
	while (pos != -1) {
		//如果"."数大于3，或存在空段，则非法
		if (n > 3 || pos == 0) {
			return false;
		}
		string s = ip.substr(0, pos);
		num[n] = stoi(s);

		ip = ip.erase(0, pos + 1);
		pos = ip.find('.');
		n++;
	}
	return true;
}
//判断掩码是否合法
//非法情况：有空段，不符合前1后0，全1或全0
bool IPSubnetMask::mask_legal(string mask) {
	int num[4];
	bool flag = true; //前1为true，后0为false
	//将掩码按"."分开
	if (split_ip(mask, num)) {
		for (int i = 0; i < 4; i++) {
			//全1或全0，则掩码非法
			if (num[0] == 0 || num[3] == 255) {
				return false;
			}
			if (flag) {
				//如果本段非全0，则把标记flag记为false，之后的段只能为0
				if (num[i] == 254 || num[i] == 252 || num[i] == 248 || num[i] == 240 ||
					num[i] == 224 || num[i] == 192 || num[i] == 128 || num[i] == 0) {
					flag = false;
				}
				else if (num[i] !=
					255) { //如果本段非前0后1的合法值，则掩码非法
					return false;
				}
			}
			else {
				if (num[i] != 0) {
					return false;
				}
			}
		}
	}
	else { //有空段则非法
		return false;
	}
	return true;
}

//类似于【0.*.*.*】和【127.*.*.*】的IP地址，计数时请忽略
bool IPSubnetMask::ip_ignore(string ip) {
	int num[4];
	split_ip(ip, num);
	if (num[0] == 0 || num[0] == 127) {
		return true;
	}
	return false;
}

//判断ip是否合法
//非法情况：有空段，范围不在0～255
bool IPSubnetMask::ip_legal(string ip)
{
	int num[4];
	if (split_ip(ip, num)) {
		//范围不在0～255，则非法
		for (int i = 0; i < 4; i++) {
			if (num[i] < 0 || num[i] > 255) {
				return false;
			}
		}
	}
	else { //有空段则非法
		return false;
	}
	return true;
}

//判断ip是否是私网
bool IPSubnetMask::ip_private(string ip)
{
	int num[4];
	split_ip(ip, num);
	if (num[0] == 10) {
		return true;
	}
	else if (num[0] == 172 && num[1] >= 16 && num[1] <= 31) {
		return true;
	}
	else if (num[0] == 192 && num[1] == 168) {
		return true;
	}
	else {
		return false;
	}
}

//ip分类
char IPSubnetMask::ip_classify(string ip) {
	int num[4];
	split_ip(ip, num);
	if (num[0] >= 0 && num[0] <= 126) {
		return 'A';
	}
	else if (num[0] >= 128 && num[0] <= 191) {
		return 'B';
	}
	else if (num[0] >= 192 && num[0] <= 223) {
		return 'C';
	}
	else if (num[0] >= 224 && num[0] <= 239) {
		return 'D';
	}
	else if (num[0] >= 240 && num[0] <= 255) {
		return 'E';
	}
	return ' ';
}
