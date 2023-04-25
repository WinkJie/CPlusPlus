#include "HuaweiDaily.h"

void HuaweiDaily::PrintLastWord()
{
	string str1, str2;
	int num = 0;
	cout << "输出最后一个单词的长度，输入字符串会计算最后一个单词的长度：" << endl;
	getline(cin, str1);
	//方式一 直接使用字符串功能函数
	num = str1.find_last_of(" ");
	str2 = str1.substr(num + 1, str1.length());
	cout << str2.length() << endl;
	//方式二 倒序遍历字符串数组
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
	cout << "计算某个字符出现的次数,先输入字符串，再输入某个字符：" << endl;
	getline(cin, s); // 读入一个字符串
	cin >> c; // 读入目标字符
	for (int i = 0; i < s.length(); i++)
	{
		if (tolower(s[i]) == tolower(c)) // 将字符转换为小写字母进行比较
		{
			count++;
		}
	}
	cout << "字符 '" << c << "' 在字符串中出现了 " << count << " 次。" << endl;
}

void HuaweiDaily::RandomNumber()
{
	//
	cout << "请输入随机数的总数，在输入逐个随机数：" << endl;
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
	cout << "分割字符串，请输入字符串：" << endl;
	while (cin >> str)
	{
		int len = str.size();
		int cnt = len / 8 + (len % 8 == 0 ? 0 : 1);
		for (int i = 0; i < cnt; i++)
		{
			string temp = str.substr(i * 8, 8);
			if (temp.size() != 8)  // 不足 8 位，补 0
				temp.append(8 - temp.size(), '0');
			cout << temp << endl;
		}
		break;
	}
}

