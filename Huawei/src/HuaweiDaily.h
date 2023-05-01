#pragma once
/*
 * author��ɹ̫���Ⱦ�
 * time:2023��4��28��07:27:10
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
	/*���������λΪ32λ
	 * �Լ�ʵ��ͬbitset<n>(num);
	 */
	string BaseConversions(unsigned int num, int digits = 0);
	//��һ������תΪ������32λ��
	void bitset32();

	//Ѱ��תΪ�����ƺ���ַ����ж��ٸ�1
	void findNumOfBinary(unsigned int nums);

	//Ѱ��תΪ�����ƺ���ַ����ж��ٸ�1��32λ��������
	void findNumOfBinary32();

	//Ѱ��תΪ�����ƺ���ַ����ж��ٸ�1��64λ��������
	void findNumOfBinary64();

	//ʹ��bitsetѰ�Ҷ������е�1����
	void findNumSetBitset();

	//n����ת��
	string Baseconversion(unsigned int num, int decimal); //ʧ��

	//Ѱ��DNA��������ռ����ߵ��Ӵ�
	/*һ�� DNA ������ A/C/G/T �ĸ���ĸ�����������ɡ� G �� C �ı�
	��������Ϊ GC-Ratio ���������� G �� C ������ĸ���ܵĳ��ִ�������
	�ܵ���ĸ��Ŀ��Ҳ�������г��ȣ����ڻ��򹤳��У���������ǳ���Ҫ��
	��Ϊ�ߵ� GC-Ratio �����ǻ������ʼ�㡣����һ���ܳ��� DNA ���У�
	�Լ��޶����Ӵ����� N ��������о���Ա�ڸ����� DNA �����д�����
	���ҳ� GC-Ratio ����ҳ���Ϊ N �ĵ�һ���Ӵ���DNA����Ϊ ACGT ��
	�Ӵ���: ACG , CG , CGT �ȵȣ�����û�� AGT �� CT �ȵ����ݷ�
	Χ���ַ�����������1��n��1000  ��������ַ���ֻ���� A/C/G/T ��ĸ
	*/
	string findGCSubstr(string& dna, int n);
	void findDna();

	//��ʰ��ƿ���㷨
	/*ĳ�̵�涨����������ˮƿ���Ի�һƿ��ˮ���������ϰ�����ˮ
	ƿ�����Ǳ���Ҫ�黹����С��������n������ˮƿ������֪���Լ����
	���Ժȵ�����ƿ��ˮ�����ݷ�Χ����������������� 1��n��100
	*/
	int BottleAlgorithm();

	//���nλ��֮�ڵ�������
	vector<int> printNumbers(int n);

	/*����һ������Ϊ n �����ӣ�������Ӽ����������� m �Σ� m �� n ����������
	 n > 1 ���� m > 1 �� m <= n ����ÿ�����ӵĳ��ȼ�Ϊ k[1],...,k[m] ��
	 ���� k[1]*k[2]*...*k[m] ���ܵ����˻��Ƕ��٣����磬�����ӵĳ����� 8 ʱ��
	 ���ǰ������ɳ��ȷֱ�Ϊ 2��3��3 �����Σ���ʱ�õ������˻��� 18 ��
	 */
	int CutRope(int n);

	/*����һ������Ϊ n �����ӣ�������Ӽ����������� m �Σ� m �� n ����������
	n > 1 ���� m > 1 �� m <= n ����ÿ�����ӵĳ��ȼ�Ϊ k[1],...,k[m] ��
	���� k[1]*k[2]*...*k[m] ���ܵ����˻��Ƕ��٣����磬�����ӵĳ����� 8 ʱ��
	���ǰ������ɳ��ȷֱ�Ϊ 2��3��3 �����Σ���ʱ�õ������˻��� 18 ��
	���ڴ𰸹������ 998244353 ȡģ��.
	��̬�滮
	*/
	void CutRope(long long n, const long long size = 998244353);//ʧ��


public:


};

