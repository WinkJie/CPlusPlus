#include "SharePointer.h"
#pragma warning(disable:4996)
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <memory>
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype> //判断字符类型需要的头文件


#include "Log.h"
#include "SharePointer.h"

using namespace std;

class Ax
{
public:
	void foo() { printf("11 \n"); }
	virtual void fun() { printf("22 \n"); }
	virtual void vir() = 0;   //纯虚函数不能实例化
};
//基类，可以设置参数，供子类使用。

class A :public Ax
{
public:
	void foo() { printf("1\n"); }
	virtual void fun() { printf("2\n"); }
	virtual void vir() { printf("纯虚函数 \n"); }
};
class B : public A
{
public:
	void foo() { printf("3\n"); }
	void fun() { printf("4\n"); }
	void vir() { printf("子类中的子类\n"); }
};

int main_test(void)
{
#if 0
	A a;
	B b;
	A* p = &a;
	p->foo();
	p->fun();
	p->vir();
	p = &b;
	p->foo();
	p->fun();
	p->vir();

	int x = 35; char str[10] = "1234";

	strlen(str);
	printf("strlen(str) is %d \n", strlen(str));
	printf("sizeof(str) is %d \n", sizeof(str));
#endif //0


#if 1

#if 0
	//创建shared_ptr智能指针对象language1、language2、language3
	shared_ptr<string> language1(new string("C++"));
	shared_ptr<string> language2 = language1;
	shared_ptr<string> language3 = language1;
	//通过智能指针对象language1、language2、language3调用get()函数
	cout << "language1: " << language1.get() << endl;
	cout << "language2: " << language2.get() << endl;
	cout << "language3: " << language3.get() << endl;
	cout << "引用计数：";
	cout << language1.use_count() << " ";
	cout << language2.use_count() << " ";
	cout << language3.use_count() << endl;
	language2.reset();
	cout << "引用计数：";
	cout << language1.use_count() << " ";
	cout << language2.use_count() << " ";
	cout << language3.use_count() << endl;
	cout << "language1: " << language1.get() << endl;
	cout << "language2: " << language2.get() << endl;
	cout << "language3: " << language3.get() << endl;

	cout << "引用计数：";
	language3.reset();
	cout << language1.use_count() << " ";
	cout << language2.use_count() << " ";
	cout << language3.use_count() << endl;
	//system("notepad E:\Text.bat");
	//system("E:\Text.bat");
#endif // 0



#if 0
	bool flagNow = false;
	Log mainLog;
	string str = "Log";
	string dir = "测试";
	if (!mainLog.CommonLogInit(str, dir))
		return -1;


	//flagNow = mainLog.CommonLogInit(str);

	mainLog << "测试一下我的日志类" << endl << mainLog.Getstr() << endl;
	//<< mainLog.StrName << endl;
	str = "hello_world_yoyo";
	str.append("_" + str);
	str.substr();
	int num = str.find_first_of("_");
	mainLog << str.c_str() << endl;
	//mainLog.Disable();
	mainLog << num << endl;
	mainLog << str.length() << endl;
	str = str.substr(0, num);
	mainLog << str.c_str() << endl;
	mainLog.LogOutLn(str.c_str());

	mainLog << "one is now:" << Log::Getstr() << endl;
	//mainLog.Enable();
	mainLog << "one is nowtttt:" << Log::GetstrStdio() << endl << endl;


	int iop = 5;
	int& yinyong = iop;
	int* pointer = &iop;
	int*& yinyong0 = pointer;
	mainLog << &pointer << endl;// << *yinyong << endl;
	mainLog << iop << endl << yinyong << endl << *pointer << endl;
	mainLog << &iop << endl << *&yinyong << endl << pointer << endl;
	mainLog << sizeof(&yinyong) << endl;//分配地址的size   8个字节
	mainLog << sizeof(yinyong) << endl;//引用变量所分配的内存大小   4个字节
	mainLog << **&yinyong0 << endl << &*&yinyong0 << endl << yinyong0 << endl;

	int op = iop;
	iop = 1;
	mainLog << op << endl << iop << endl;

	//SharedPointer pointer;
	//string b = str.append()



#endif // 0

	int a = 9;
	auto func = [=]()mutable
	{
		string name = "string";
		++a;
		name += to_string(a);
		return name;
	};

	cout << func() << " " << a << endl;

	string op = "women5";
	for (int i = 0; i < op.length(); i++)
	{
		if (isdigit(op[i]))
			cout << "是数字" << endl;
		else
			cout << "是字母" << endl;


	}


#endif // 1


#if 0


	int a = 10;
	std::shared_ptr<int> ptra = std::make_shared<int>(a);
	std::shared_ptr<int> ptra2(ptra); //copy
	std::cout << ptra.use_count() << std::endl;  //2

	int b = 20;
	int* pb = &a;
	//std::shared_ptr<int> ptrb = pb;  //error
	std::shared_ptr<int> ptrb = std::make_shared<int>(b);
	ptra2 = ptrb; //assign
	pb = ptrb.get(); //获取原始指针

	std::cout << ptra.use_count() << std::endl;  //1
	std::cout << ptrb.use_count() << std::endl;  //2
#endif // 0

	return 0;
}



//const int maxn = 1e3 + 5;
//int ma[maxn][maxn];
//set<int> ans;
//set<int>::iterator it;
//int main() {
//    int N;
//    while (scanf("%d", &N) != EOF) 
//    {
//        memset(ma, 0, sizeof(ma));
//        ans.clear();
//        int  max_id = 0, min_id = 1e6 + 2;
//        for (int k = 0; k < N; k++) 
//        {
//            int a, b, c;
//            scanf("%d%d", &a, &b);
//            max_id = max(max_id, a);
//            min_id = min(min_id, a);
//            if (b > 1) ans.insert(a);
//            for (int i = 0; i < b; i++) 
//            {
//                scanf("%d", &c);
//                ma[a][c] = 1;
//            }
//        }
//        if (max_id == min_id) 
//        { 
//            cout << 0 << endl;
//            continue; 
//        }
//        for (int i = min_id; i <= max_id; i++)
//        { 
//            for (int j = min_id; j <= max_id; j++)
//            {
//                if (ma[i][j] == 1 && ma[j][i] == 1) ans.insert(i);
//            }
//        }
//            
//        int si = ans.size();
//        printf("%d\n", si);
//        if (si > 0) 
//        {
//            it = ans.begin();
//            for (int i = 0; i < si - 1; i++) 
//            { 
//                printf("%d ", *it);
//                it++; 
//            }
//            printf("%d\n", *it);
//        }
//
//    }
//}


//
//#pragma warning(disable:4996)
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//    char str1[1010], str2[1010];
//    memset(str1, 0, sizeof(str1));
//    memset(str2, 0, sizeof(str2));//将str1,str2每位取零，不能忘了，因为str1与str2长度不相等的时候，要将多余的部分与0相加
//
//    while (scanf("%s%s", str1, str2) != EOF)
//    {
//
//        int len1 = strlen(str1);
//        int len2 = strlen(str2);
//        int sum[1010] = { 0 };//不能放在while外面，如果在外面，会导致第二组数据不是从0开始的
//        //逆置
//        reverse(str1, str1 + len1);
//        reverse(str2, str2 + len2);
//        //转换为整型
//        int x[1010] = { 0 }, y[1010] = { 0 };
//        for (int i = 0; i < len1; i++)
//            x[i] = str1[i] - '0';
//        for (int i = 0; i < len2; i++)
//            y[i] = str2[i] - '0';
//
//        int len = len1 > len2 ? len1 : len2;//比较str1,str2的长度，取较长的作为循环上限
//        for (int i = 0; i < len; i++)
//        {
//            sum[i + 1] = (x[i] + y[i] + sum[i]) / 10;//①
//            sum[i] = (x[i] + y[i] + sum[i]) % 10;//②
//
//             //①与②的顺序不能倒过来，我一开始就是没注意到，写反了，导致1003+4=1017.......o(╥﹏╥)o
//
//        }
//        if (sum[len] != 0)
//            len++;
//        reverse(sum, sum + len);
//        for (int i = 0; i < len; i++)
//            printf("%d", sum[i]);
//        printf("\n");
//    }
//    return 0;
//}


//#include<bits/stdc++.h>
//
//using namespace std;
//const int N = 1e3 + 10;
//char a[N], b[N];
//struct bign
//{
//    int s[N];
//    int len;
//    bign() {
//        memset(s, 0, sizeof(s));
//        len = 0;
//    }
//};
//
//bign change(char str[])
//{
//    bign a;
//    a.len = strlen(str);
//    for (int i = 0; i < a.len; i++) {
//        a.s[i] = str[a.len - i - 1] - '0';
//    }
//    return a;
//}
//
//int comm(bign a, bign b)//大数的比较
//{
//    if (a.len > b.len) return 1;
//    else if (a.len < b.len) return -1;
//    else {
//        for (int i = a.len - 1; i >= 0; i--) {
//            if (a.s[i] > b.s[i]) return 1;
//            else if (a.s[i] < b.s[i]) return -1;
//        }
//    }
//    return 0;
//}
//
//bign add(bign a, bign b)
//{
//    bign c;
//    int carry = 0;
//    for (int i = 0; i < a.len || i < b.len; i++) {
//        int temp = a.s[i] + b.s[i] + carry;
//        c.s[c.len++] = temp % 10;
//        carry = temp / 10;
//    }
//    if (carry != 0) c.s[c.len++] = carry;
//    return c;
//}
//int main()
//{
//    while (~scanf("%s %s", a, b)) {
//        bign s1 = change(a);
//        bign s2 = change(b);
//        bign c = add(s1, s2);
//        for (int i = c.len - 1; i >= 0; i--) {
//            printf("%d", c.s[i]);
//        }
//        printf("\n");
//    }
//    return 0;
//}
//
//#pragma GCC optimize(2)
//#include <bits/stdc++.h>
//using namespace std;
//inline int read() { int x = 0, f = 1; char c = getchar(); while (c != '-' && (c < '0' || c>'9'))c = getchar(); if (c == '-')f = -1, c = getchar(); while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar(); return f * x; }
//typedef long long ll;
//const int maxn = 1e9 + 10;
//string str1, str2;
//int main()
//{
//    while (cin >> str1 >> str2) {
//        string str;
//        int len1 = str1.length();
//        int len2 = str2.length();
//        if (len1 < len2) {
//            for (int i = 1; i <= len2 - len1; i++) {
//                str1 = "0" + str1;
//            }
//        }
//        else {
//            for (int i = 1; i <= len1 - len2; i++) {
//                str2 = "0" + str1;
//            }
//        }
//        len1 = str1.length();
//        int c = 0;
//        int temp;
//        for (int i = len1 - 1; i >= 0; i--) {
//            temp = str1[i] - '0' + str2[i] - '0' + c;
//            c = temp / 10;
//            temp %= 10;
//            str = char(temp + '0') + str;
//        }
//        if (c != 0) {
//            str = char(c + '0') + str;
//        }
//        cout << str << endl;
//    }
//
//}
