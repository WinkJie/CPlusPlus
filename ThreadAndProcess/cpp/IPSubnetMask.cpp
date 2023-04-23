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
		//���ַ�����"~"��ΪIP������
		string ip, mask;
		auto pos = str.find('~');
		ip = str.substr(0, pos);
		mask = str.substr(pos + 1);

		// �����ڡ�0.*.*.*���͡�127.*.*.*������ʱ�����
		if (ip_ignore(ip)) {
			continue;
		}

		// �������Ƿ�������IP��ַ������������+1
		else if (!mask_legal(mask)) {
			err++;
		}

		// ���ip�Ƿ�������IP��ַ������������+1
		else if (!ip_legal(ip)) {
			err++;
		}
		// �ж�ip�������Ƿ���˽��
		else {
			// �ж�ip�Ƿ���˽��
			if (ip_private(ip)) 
			{
				p++;
			}
			// �ж�ip���
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
	int n = 0; //��¼"."�ĸ���
	ip += ".";
	auto pos = ip.find('.');
	while (pos != -1) {
		//���"."������3������ڿնΣ���Ƿ�
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
//�ж������Ƿ�Ϸ�
//�Ƿ�������пնΣ�������ǰ1��0��ȫ1��ȫ0
bool IPSubnetMask::mask_legal(string mask) {
	int num[4];
	bool flag = true; //ǰ1Ϊtrue����0Ϊfalse
	//�����밴"."�ֿ�
	if (split_ip(mask, num)) {
		for (int i = 0; i < 4; i++) {
			//ȫ1��ȫ0��������Ƿ�
			if (num[0] == 0 || num[3] == 255) {
				return false;
			}
			if (flag) {
				//������η�ȫ0����ѱ��flag��Ϊfalse��֮��Ķ�ֻ��Ϊ0
				if (num[i] == 254 || num[i] == 252 || num[i] == 248 || num[i] == 240 ||
					num[i] == 224 || num[i] == 192 || num[i] == 128 || num[i] == 0) {
					flag = false;
				}
				else if (num[i] !=
					255) { //������η�ǰ0��1�ĺϷ�ֵ��������Ƿ�
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
	else { //�пն���Ƿ�
		return false;
	}
	return true;
}

//�����ڡ�0.*.*.*���͡�127.*.*.*����IP��ַ������ʱ�����
bool IPSubnetMask::ip_ignore(string ip) {
	int num[4];
	split_ip(ip, num);
	if (num[0] == 0 || num[0] == 127) {
		return true;
	}
	return false;
}

//�ж�ip�Ƿ�Ϸ�
//�Ƿ�������пնΣ���Χ����0��255
bool IPSubnetMask::ip_legal(string ip)
{
	int num[4];
	if (split_ip(ip, num)) {
		//��Χ����0��255����Ƿ�
		for (int i = 0; i < 4; i++) {
			if (num[i] < 0 || num[i] > 255) {
				return false;
			}
		}
	}
	else { //�пն���Ƿ�
		return false;
	}
	return true;
}

//�ж�ip�Ƿ���˽��
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

//ip����
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
