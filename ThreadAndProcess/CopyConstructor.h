#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

/*拷贝构造函数类
 *
 */

//https://bbs.csdn.net/topics/391934069
//例子实验

#ifndef NOMINMAX

#ifndef min
#define min(a,b)   (((a) < (b)) ? (a) : (b))
#endif // !min

#ifndef max
#define max(a,b)   (((a) > (b)) ? (a) : (b))
#endif // !max

#endif // !NOMINMAX

//#define min(a,b)   (((a) < (b)) ? (a) : (b))
//#define max(a,b)   (((a) > (b)) ? (a) : (b))

class CopyConstructor
{
public:
	CopyConstructor();
    //CopyConstructor(const CopyConstructor& obj) = delete;
    CopyConstructor(const CopyConstructor& obj);
	CopyConstructor(int p);
	~CopyConstructor();
	int* pointer;
	CopyConstructor& operator=(const CopyConstructor& obj);
	void printop();

	int GetNumber();

	int InlineTest();


    int partition(vector<int>& nums, int low, int high)
    {
        int pivot = nums[low];
        while (low < high) 
        {
            while (low < high && nums[high] >= pivot) 
                high--;
            nums[low] = nums[high];
            while (low < high && nums[low] <= pivot) 
                low++;
            nums[high] = nums[low];
        }
        nums[low] = pivot;
        return low;
    }
    void quickSort(vector<int>& nums, int low, int high)
    {
        if (low >= high) return;
        int mid = partition(nums, low, high);
        quickSort(nums, low, mid - 1);
        quickSort(nums, mid + 1, high);
    }
    int minMoves2(vector<int>& nums)
    {
        quickSort(nums, 0, nums.size() - 1);
        long long result1 = 0, result2 = 0;
        int mid1 = (nums.size() - 1) / 2;
        int mid2 = (nums.size() - 1) / 2 - 1;
        if (mid2 < 0) mid2 = mid1;
        for (int i = 0; i < nums.size(); ++i) 
        {
            result1 += abs(nums[mid1] - nums[i]);
            result2 += abs(nums[mid2] - nums[i]);
        }
        return min(result1, result2);
    }

	/*EXCEPT Test*/
	void fun()noexcept;

private:
	int number;
};

