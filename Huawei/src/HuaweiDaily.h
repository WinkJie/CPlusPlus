#pragma once
/*
 * author：晒太阳喝酒
 * time:2023年4月28日07:27:10
 */

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

//牛客练习华为机试
using namespace std;



class HuaweiDaily
{
public:
	//字符串转换
	void print(string& str);
	void toString(string& str);
	string StringToGBK(string& str);

	//字符串最后一个单词的长度
	void PrintLastWord();

	//计算某字符出现的次数
	void countword();

	//明明的随机数
	void RandomNumber();

	//字符串分割
	void StringSplite();

	//十进制与二进制的转换
	string BaseConversion(unsigned int num);
	/*输出二进制位为32位
	 * 自己实现同bitset<n>(num);
	 */
	string BaseConversions(unsigned int num, int digits = 0);
	//将一个数字转为二进制32位的
	void bitset32();

	//寻找转为二进制后的字符串有多少个1
	void findNumOfBinary(unsigned int nums);

	//寻找转为二进制后的字符串有多少个1在32位二进制中
	void findNumOfBinary32();

	//寻找转为二进制后的字符串有多少个1在64位二进制中
	void findNumOfBinary64();

	//使用bitset寻找二进制中的1数量
	void findNumSetBitset();

	//n进制转换
	string Baseconversion(unsigned int num, int decimal); //失败

	//寻找DNA中子序列占比最高的子串
	/*一个 DNA 序列由 A/C/G/T 四个字母的排列组合组成。 G 和 C 的比
	例（定义为 GC-Ratio ）是序列中 G 和 C 两个字母的总的出现次数除以
	总的字母数目（也就是序列长度）。在基因工程中，这个比例非常重要。
	因为高的 GC-Ratio 可能是基因的起始点。给定一个很长的 DNA 序列，
	以及限定的子串长度 N ，请帮助研究人员在给出的 DNA 序列中从左往
	右找出 GC-Ratio 最高且长度为 N 的第一个子串。DNA序列为 ACGT 的
	子串有: ACG , CG , CGT 等等，但是没有 AGT ， CT 等等数据范
	围：字符串长度满足1≤n≤1000  ，输入的字符串只包含 A/C/G/T 字母
	*/
	string findGCSubstr(string& dna, int n);
	void findDna();

	//收拾旧瓶子算法
	/*某商店规定：三个空汽水瓶可以换一瓶汽水，允许向老板借空汽水
	瓶（但是必须要归还）。小张手上有n个空汽水瓶，她想知道自己最多
	可以喝到多少瓶汽水。数据范围：输入的正整数满足 1≤n≤100
	*/
	int BottleAlgorithm();

	//输出n位数之内的所有数
	vector<int> printNumbers(int n);

	/*给你一根长度为 n 的绳子，请把绳子剪成整数长的 m 段（ m 、 n 都是整数，
	 n > 1 并且 m > 1 ， m <= n ），每段绳子的长度记为 k[1],...,k[m] 。
	 请问 k[1]*k[2]*...*k[m] 可能的最大乘积是多少？例如，当绳子的长度是 8 时，
	 我们把它剪成长度分别为 2、3、3 的三段，此时得到的最大乘积是 18 。
	 */
	int CutRope(int n);

	/*给你一根长度为 n 的绳子，请把绳子剪成整数长的 m 段（ m 、 n 都是整数，
	n > 1 并且 m > 1 ， m <= n ），每段绳子的长度记为 k[1],...,k[m] 。
	请问 k[1]*k[2]*...*k[m] 可能的最大乘积是多少？例如，当绳子的长度是 8 时，
	我们把它剪成长度分别为 2、3、3 的三段，此时得到的最大乘积是 18 。
	由于答案过大，请对 998244353 取模。.
	动态规划
	*/
	void CutRope(long long n, const long long size = 998244353);//失败


public:


};

