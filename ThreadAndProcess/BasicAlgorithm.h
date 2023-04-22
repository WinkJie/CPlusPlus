#pragma once
#include "PublicHeader.h"
#include <algorithm>

/*ԭ�Ӳ���*/
#include <thread>
#include <atomic>
#include <time.h>
#include <mutex>

/*
 *C++�Ļ����㷨
 */



class BasicAlgorithm
{
public:
	void Swap(int& a, int& b)
	{
		int t = a;
		a = b;
		b = t;
	}
	//�����������ѡȡ�ڱ���ǰ�� 
	void QuickSort(int* h, int left, int right);

	//ð������
	void BubbleSort(int* h, size_t len);

	//ѡ������
	void SelectionSort(int* h, size_t len);

	//��������
	void InsertSort(int* h, size_t len);

	//�鲢����
	void  MergeArray(int* arr, size_t left, size_t mid, size_t right, int* temp);
	void MMergeSort(int* arr, size_t left, size_t right, int* temp);
	void MergeSort(int* h, size_t len);

	//ϣ������
	void ShellSort(int* h, size_t len);

	//������
 /*
 �󶥶�sort֮������Ϊ��С��������
 */
 //====����=====
	//----nodeΪ��Ҫ�����Ľ���ţ���0��ʼ���;lenΪ�ѳ��� 
	void AdjustHeap(int* h, int node, int len);
	//====����=====
	void MakeHeap(int* h, int len);
	//====����=====
	void HeapSort(int* h, int len);

	//��������
	 /*
	  * LSD�㷨ʵ��
	  * ��λ����λ����
	  */

	  //
	int GetMaxDight(int* h, int len);
	int GetReminder(int value, int digit);
	void RadixSort_LSD(int* h, int len);
	void RadixSort_LSD_Reverse(int* h, int len);
	/*
	* MSD�㷨ʵ��
	* ��λ����λ����
	*/
	void RRadixSort_MSD(int* h, int begin, int end, int digit);
	void RadixSort_MSD(int* h, int len);
	void RRadixSort_MSD_Reverse(int* h, int begin, int end, int digit);
	void RadixSort_MSD_Reverse(int* h, int len);
	void CSerialPort();
};

