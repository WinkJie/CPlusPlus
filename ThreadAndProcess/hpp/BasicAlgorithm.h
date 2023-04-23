#pragma once
#include "PublicHeader.h"
#include <algorithm>

/*原子操作*/
#include <thread>
#include <atomic>
#include <time.h>
#include <mutex>

/*
 *C++的基本算法
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
	//快速排序，随机选取哨兵放前面 
	void QuickSort(int* h, int left, int right);

	//冒泡排序
	void BubbleSort(int* h, size_t len);

	//选择排序
	void SelectionSort(int* h, size_t len);

	//插入排序
	void InsertSort(int* h, size_t len);

	//归并排序
	void  MergeArray(int* arr, size_t left, size_t mid, size_t right, int* temp);
	void MMergeSort(int* arr, size_t left, size_t right, int* temp);
	void MergeSort(int* h, size_t len);

	//希尔排序
	void ShellSort(int* h, size_t len);

	//堆排序
 /*
 大顶堆sort之后，数组为从小到大排序
 */
 //====调整=====
	//----node为需要调整的结点编号，从0开始编号;len为堆长度 
	void AdjustHeap(int* h, int node, int len);
	//====建堆=====
	void MakeHeap(int* h, int len);
	//====排序=====
	void HeapSort(int* h, int len);

	//基数排序
	 /*
	  * LSD算法实现
	  * 低位到高位排序
	  */

	  //
	int GetMaxDight(int* h, int len);
	int GetReminder(int value, int digit);
	void RadixSort_LSD(int* h, int len);
	void RadixSort_LSD_Reverse(int* h, int len);
	/*
	* MSD算法实现
	* 高位到低位排序
	*/
	void RRadixSort_MSD(int* h, int begin, int end, int digit);
	void RadixSort_MSD(int* h, int len);
	void RRadixSort_MSD_Reverse(int* h, int begin, int end, int digit);
	void RadixSort_MSD_Reverse(int* h, int len);
	void CSerialPort();
};

