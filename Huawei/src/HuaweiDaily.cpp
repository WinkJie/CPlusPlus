#include "HuaweiDaily.h"

void HuaweiDaily::PrintLastWord()
{
	string str1, str2;
	int num = 0;
	cout << "������һ�����ʵĳ��ȣ������ַ�����������һ�����ʵĳ��ȣ�" << endl;
	getline(cin, str1);
	//��ʽһ ֱ��ʹ���ַ������ܺ���
	num = str1.find_last_of(" ");
	str2 = str1.substr(num + 1, str1.length());
	cout << str2.length() << endl;
	//��ʽ�� ��������ַ�������
	int numb = 0;
	string str3, str4;
	cin >> str3;
	for (int i = str3.length() - 1; i >= 0; i--)
	{
		if (str3[i] == ' ')
		{
			break;
		}
		else
		{
			str4[numb] = str3[i];
			numb++;
		}
	}
	cout << numb << endl;
}

void HuaweiDaily::countword()
{
	string s;
	char c;
	int count = 0;
	cout << "����ĳ���ַ����ֵĴ���,�������ַ�����������ĳ���ַ���" << endl;
	getline(cin, s); // ����һ���ַ���
	cin >> c; // ����Ŀ���ַ�
	for (int i = 0; i < s.length(); i++)
	{
		if (tolower(s[i]) == tolower(c)) // ���ַ�ת��ΪСд��ĸ���бȽ�
		{
			count++;
		}
	}
	cout << "�ַ� '" << c << "' ���ַ����г����� " << count << " �Ρ�" << endl;
}

void HuaweiDaily::RandomNumber()
{
	//
	cout << "�����������������������������������" << endl;
	int N, n;
	while (cin >> N)
	{
		int a[1001] = { 0 };
		while (N--) {
			cin >> n;
			a[n] = 1;
		}
		for (int i = 0; i < 1001; i++)
			if (a[i]&&a[i]<1001&&a[i]>0)
				cout << i << endl;
		break;
	}
}

void HuaweiDaily::StringSplite()
{
	string str;
	cout << "�ָ��ַ������������ַ�����" << endl;
	while (cin >> str)
	{
		int len = str.size();
		int cnt = len / 8 + (len % 8 == 0 ? 0 : 1);
		for (int i = 0; i < cnt; i++)
		{
			string temp = str.substr(i * 8, 8);
			if (temp.size() != 8)  // ���� 8 λ���� 0
				temp.append(8 - temp.size(), '0');
			cout << temp << endl;
		}
		break;
	}
}

