#pragma once
#include "PublicHeader.h"
#include "Log.h"
using namespace std;

#define LIST_INIT_SIZE 100     //线性表存储空间的初始分配量
#define LISTINCREMENT 10       //线性表存储空间的分配增量

#define TRUE 1					//true
#define FALSE 0					//false
#define OK 1					//ok
#define ERROR 0					//error
#define INFEASIBLE -1			//infeasible
//#define OVERFLOW -1				//overflow
//template <class T>;
typedef int Status;
typedef char ElemType;
typedef ElemType* Triplet;
template <typename S>

class Linear_List
{
public:
	Linear_List();
	~Linear_List();

public:	
	Status InitTriplet(Triplet& T, ElemType v1, ElemType v2, ElemType v3);
	Status DestroyTriplet(Triplet& T);
	Status Get(Triplet T, int i, ElemType& e);
	Status Put(Triplet T, int i, ElemType& e);
	Status IsAscending(Triplet T);
	Status IsDecending(Triplet T);
	template <class T> void swaps(T& a, T& b);
};
/*数据结构*/