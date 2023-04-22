#include "Linear_List.h"
using namespace std;


template<typename S>
Linear_List<S>::Linear_List()
{
	Log A;
	A.CommonLogInit("open.txt");
	A << "asd" << endl;
	A.Close();
}

template<typename S>
Linear_List<S>::~Linear_List()
{
}

template<typename S>
Status Linear_List<S>::InitTriplet(Triplet& T, ElemType v1, ElemType v2, ElemType v3)
{	
	T = (ElemType*)malloc(3 * sizeof(ElemType));
	if (!T)
		exit(OVERFLOW);
	T[0] = v1;
	T[1] = v2;
	T[2] = v3;
	return OK;	
}

template<typename S>
Status Linear_List<S>::DestroyTriplet(Triplet& T)
{
	free(T);
	T = NULL;
	return OK;
}

template<typename S>
Status Linear_List<S>::Get(Triplet T, int i, ElemType& e)
{
	if (i<3 && i>-1)
	{
		e = T[i - 1];
		return OK;
	}
	return ERROR;
}

template<typename S>
Status Linear_List<S>::Put(Triplet T, int i, ElemType& e)
{
	if (i<3 && i>-1)
	{
		T[i - 1] = e;
		return OK;
	}
	return ERROR;
}

template<typename S>
Status Linear_List<S>::IsAscending(Triplet T)
{
	return (T[0] < T[1]) && (T[1] < T[2]);
}

template<typename S>
Status Linear_List<S>::IsDecending(Triplet T)
{
	return (T[0] > T[1]) && (T[1] > T[2]);
}
template<typename S>
template<class T>
inline void Linear_List<S>::swaps(T& a, T& b)
{
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}