#include "HuaweiDaily.h"

void HuaweiDaily::print(string& str)
{
	// 将 GBK 编码转换为 Unicode 编码
	const char* gbk = str.c_str();
	int len = MultiByteToWideChar(CP_ACP, 0, gbk, -1, NULL, 0);
	wchar_t* unicode = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, gbk, -1, unicode, len);

	// 设置输出流的编码格式为 Unicode，并输出到控制台
	_setmode(_fileno(stdout), _O_WTEXT);
	std::wcout.imbue(std::locale(""));
	std::wcout << unicode;
	// 释放内存
	delete[] unicode;
}
void HuaweiDaily::toString(string& str)
{
	// 将 UTF-8 格式的字符串转换为 GBK 编码格式
	const char* utf8 = u8"你好，世界！";
	int len = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);
	wchar_t* gbk = new wchar_t[len];
	MultiByteToWideChar(CP_UTF8, 0, utf8, -1, gbk, len);

	// 设置输出编码格式为 GBK
	_setmode(_fileno(stdout), _O_U8TEXT);
	locale loc("zh-CN");
	setlocale(LC_ALL, "zh-CN");

	// 输出 GBK 编码格式的字符串
	wcout.imbue(loc);
	wcout << gbk << endl;
	delete[] gbk;
}
string HuaweiDaily::StringToGBK(string& str)
{
	// 将原始字符串转换为宽字节字符串
	const int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);
	wchar_t* unicode = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, unicode, len);

	// 将宽字节字符串转换为 GBK 编码
	const int gbklen = WideCharToMultiByte(CP_ACP, 0, unicode, -1, NULL, 0, NULL, NULL);
	char* gbk = new char[gbklen];
	WideCharToMultiByte(CP_ACP, 0, unicode, -1, gbk, gbklen, NULL, NULL);

	// 释放内存并返回结果
	std::string result(gbk);
	delete[] unicode;
	delete[] gbk;
	return result;
}
void HuaweiDaily::PrintLastWord()
{
	string str1, str2;
	int num = 0;
	string msg = "输出最后一个单词的长度，输入字符串会计算最后一个单词的长度:";
	cout << StringToGBK(msg) << endl;
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
	cout << "字符 '" << c << "在字符串中出现了 " << count << " 次。" << endl;
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
			if (a[i] && a[i] < 1001 && a[i]>0)
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

string HuaweiDaily::BaseConversion(unsigned int num)
{
	string str;
	if (num == 0)
		return str = "0";
	else
		return (BaseConversion(num / 2) + to_string(num % 2));
}

string HuaweiDaily::BaseConversions(unsigned int num, int digits)
{
	string str;
	if (num == 0)
	{
		str = "0";
	}
	else
	{
		// 计算新的digit
		int newDigits = digits + 1;
		if (newDigits < 32) {
			str = BaseConversions(num / 2, newDigits) + to_string(num % 2);
		}
		else {
			str = "1" + string(31, '0'); // 返回一个全零的32位二进制数
		}
	}
	// 在结果前补零，确保返回的字符串长度为32
	while (str.size() < 32) {
		str = "0" + str;
	}
	return str;
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
	cout << str.c_str() << endl;
	cout << num << endl;
}

void HuaweiDaily::bitset32()
{
	int n;
	cin >> n;
	cout << bitset<32>(n) << endl;//使用bitset库将整数转为二进制并输出
}

void HuaweiDaily::findNumOfBinary32()
{
	long long n;
	int count = 0;
	cin >> n;
	string str = (bitset<32>(n).to_string());
	cout << str.c_str() << endl;
	cout << bitset<32>(n) << endl;
	unsigned int m = (unsigned int)n;//将n强制转换为无符号整数
	while (m != 0)
	{
		//判断m中所有二进制位
		if (m & 1) //如果当前二进制位为1，count + 1
			count++;
		m = m >> 1;//将m右移一位，使下一位成为最低位
	}
	cout << count << endl;//输出1的个数
	//return count;
}

void HuaweiDaily::findNumOfBinary64()
{
	long long n;
	int count = 0;
	cin >> n;
	cout << bitset<64>(n) << endl;
	string str = (bitset<64>(n).to_string());
	cout << str.c_str() << endl;
	while (n != 0)
	{
		//判断n中所有二进制位
		if (n & 1LL) //如果当前二进制位为1，count + 1
			count++;
		n = n >> 1;//将n右移一位，使下一位成为最低位
	}
	cout << count << endl;//输出1的个数
	//return count;
}

string HuaweiDaily::Baseconversion(unsigned int num, int decimal)
{
	string str;
	if (num == 0)
		return str = "0";
	else
		return Baseconversion(num / decimal, decimal) + to_string(num % decimal);
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
	double maxRatio = -1.0;    // 最大 GC-Ratio 值
	std::string maxSubstr;     // 最大 GC-Ratio 子串
	for (int i = 0; i <= dna.size() - n; i++)
	{   // 枚举所有可能的子串
		std::string substr = dna.substr(i, n);
		double gcCount = 0;
		for (char ch : substr)
		{   // 统计当前子串中 G 和 C 的个数
			if (ch == 'G' || ch == 'C')
			{
				gcCount += 1;
			}
		}
		double gcRatio = gcCount / n;   // 计算当前子串的 GC-Ratio 值
		if (gcRatio > maxRatio)
		{   // 如果当前子串的 GC-Ratio 值比之前的最大值大，更新结果
			maxRatio = gcRatio;
			maxSubstr = substr;
		}
	}
	return maxSubstr;
}

void HuaweiDaily::findDna()
{
	string dna, maxStr;
	int n = 0;
	while (cin >> dna >> n)
	{
		maxStr = findGCSubstr(dna, n);
		cout << "The substring with the highest GC-Ratio and length of " << n <<
			" is " << maxStr << std::endl;
	}
}

int HuaweiDaily::BottleAlgorithm()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
			return 0;
		int count = 0;
		while (n > 3)
		{
			count += n / 3;
			n = n / 3 + n % 3;
		}
		if (n == 2)
			count++;
		return count;
	}
}

vector<int> HuaweiDaily::printNumbers(int n)
{
	// write code here
	//pow(n,i);函数是返回n的i次方的值，其中n是底数，i是指数。
	vector<int> vec;
	for (int i = 1; i < pow(10, n); i++)
	{
		vec.push_back(i);
	}
	return vec;
}

int HuaweiDaily::CutRope(int n)
{
	if (n < 4)
		return n - 1;
	int res = 1;
	while (n > 4)
	{
		res *= 3;
		n -= 3;
	}
	return res * n;
}

void HuaweiDaily::CutRope(long long n, const long long size)
{

}
