#include "HuaweiDaily.h"

void HuaweiDaily::print(string& str)
{
	// �� GBK ����ת��Ϊ Unicode ����
	const char* gbk = str.c_str();
	int len = MultiByteToWideChar(CP_ACP, 0, gbk, -1, NULL, 0);
	wchar_t* unicode = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, gbk, -1, unicode, len);

	// ����������ı����ʽΪ Unicode�������������̨
	_setmode(_fileno(stdout), _O_WTEXT);
	std::wcout.imbue(std::locale(""));
	std::wcout << unicode;
	// �ͷ��ڴ�
	delete[] unicode;
}
void HuaweiDaily::toString(string& str)
{
	// �� UTF-8 ��ʽ���ַ���ת��Ϊ GBK �����ʽ
    const char* utf8 = u8"��ã����磡";
    int len = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);
    wchar_t* gbk = new wchar_t[len];
    MultiByteToWideChar(CP_UTF8, 0, utf8, -1, gbk, len);

    // ������������ʽΪ GBK
    _setmode(_fileno(stdout), _O_U8TEXT);
    locale loc("zh-CN");
    setlocale(LC_ALL, "zh-CN");

    // ��� GBK �����ʽ���ַ���
    wcout.imbue(loc);
    wcout << gbk << endl;
    delete[] gbk;
}
string HuaweiDaily::StringToGBK(string& str)
{
	// ��ԭʼ�ַ���ת��Ϊ���ֽ��ַ���
	const int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);
	wchar_t* unicode = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, unicode, len);

	// �����ֽ��ַ���ת��Ϊ GBK ����
	const int gbklen = WideCharToMultiByte(CP_ACP, 0, unicode, -1, NULL, 0, NULL, NULL);
	char* gbk = new char[gbklen];
	WideCharToMultiByte(CP_ACP, 0, unicode, -1, gbk, gbklen, NULL, NULL);

	// �ͷ��ڴ沢���ؽ��
	std::string result(gbk);
	delete[] unicode;
	delete[] gbk;
	return result;
}
void HuaweiDaily::PrintLastWord()
{
	string str1, str2;
	int num = 0;
	string msg = "������һ�����ʵĳ��ȣ������ַ�����������һ�����ʵĳ���:";
	cout << StringToGBK(msg)<< endl;
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
	cout << "�ַ� '" << c << "���ַ����г����� " << count << " �Ρ�" << endl;
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

string HuaweiDaily::BaseConversion(unsigned int num)
{
	string str;
	if (num == 0)
		return str="0";
	else
		return BaseConversion(num / 2) + std::to_string(num % 2);
}

void HuaweiDaily::findNumOfBinary(unsigned int nums)
{
	int num = 0;
	string str = BaseConversion(nums);
	if (str.length() < 0)
		return;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '1')
			num++;
	}
	cout << num << endl;	
}

string HuaweiDaily::Baseconversion(unsigned int num, int decimal)
{
	string str;
	if (num == 0)
		return str = "0";
	else
		return Baseconversion(num / decimal,decimal) + to_string(num % decimal);
}

void HuaweiDaily::findNumSetBitset()
{
	int n;
	while (cin >> n) {
		bitset<32> bs(n);
		cout << bs.count() << endl;
	}
}

string HuaweiDaily::findGCSubstr(string& dna, int n)
{
	if (n <= 0 || n > dna.size()) 
	{
		return "";
	}
	double maxRatio = -1.0;    // ��� GC-Ratio ֵ
	std::string maxSubstr;     // ��� GC-Ratio �Ӵ�
	for (int i = 0; i <= dna.size() - n; i++) 
	{   // ö�����п��ܵ��Ӵ�
		std::string substr = dna.substr(i, n);
		double gcCount = 0;
		for (char ch : substr) 
		{   // ͳ�Ƶ�ǰ�Ӵ��� G �� C �ĸ���
			if (ch == 'G' || ch == 'C') 
			{
				gcCount += 1;
			}
		}
		double gcRatio = gcCount / n;   // ���㵱ǰ�Ӵ��� GC-Ratio ֵ
		if (gcRatio > maxRatio) 
		{   // �����ǰ�Ӵ��� GC-Ratio ֵ��֮ǰ�����ֵ�󣬸��½��
			maxRatio = gcRatio;
			maxSubstr = substr;
		}
	}
	return maxSubstr;
}

void HuaweiDaily::findDna()
{
	string dna,maxStr;
	int n = 0;
	while (cin>>dna>>n)
	{
		maxStr = findGCSubstr(dna, n);
		cout << "The substring with the highest GC-Ratio and length of " << n <<
			" is " << maxStr << std::endl;
	}
	
}
