#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
/*第二个类*/
//#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility> //用于pair

using namespace std;
/*智能指针类*/

class Smart_ptr final
{
public:
	using this_type = Smart_ptr;
	using shared_type = shared_ptr<this_type>;
public:
	shared_type next;
	string name;
public:
	Smart_ptr(string nameTmp);
	~Smart_ptr();
public:
	void LeakTest();
	void NormalTestN1();
	void NormalTestN2();
};

/*
 *关于shared_ptr指针的几点介绍：
 *  1.共享指针在拷贝函数中拷贝已有的指针对象参数地址达到共享数据(简单的说就是一块类对象地址由多个指针同时指向并且使用)；
 *  2.共享指针内部通过计数形式来记录共享调用类对象内存的次数(创建共享指针对象时计数为1，每被拷贝一次(赋值给别的新对象)计数加1)，每释放一个共享指针对象计数减1，当指针计数为0时释放共享调用类对象内存；
 *  3.shared_ptr类共享指针内存及共享计数内存在没有通过手动释放的情况下，将会通过虚拟析构函数来做内存释放工作。
 */
//template<typename _Tp>
//class new_allocator//采用了模板类特有的内存分配类，保证分配产生碎片变少的同时并且提高运行效率
//{
//public:
//	typedef size_t     size_type;
//	typedef ptrdiff_t  difference_type;
//	typedef _Tp* pointer;
//	typedef const _Tp* const_pointer;
//	typedef _Tp& reference;
//	typedef const _Tp& const_reference;
//	typedef _Tp        value_type;
//
//	template<typename _Tp1>
//	struct rebind
//	{
//		typedef new_allocator<_Tp1> other;
//	};
//
//	new_allocator() throw() { }
//
//	new_allocator(const new_allocator&) throw() { }
//
//	template<typename _Tp1>
//	new_allocator(const new_allocator<_Tp1>&) throw() { }
//
//	~new_allocator() throw() { }
//
//	pointer
//		address(reference __x) const { return &__x; }
//
//	const_pointer
//		address(const_reference __x) const { return &__x; }
//
//	// NB: __n is permitted to be 0.  The C++ standard says nothing
//	// about what the return value is when __n == 0.
//	pointer
//		allocate(size_type __n, const void* = 0)
//	{
//		/*if (__builtin_expect(__n > this->max_size(), false))
//		__throw_bad_alloc();*/
//
//		return static_cast<_Tp*>(::operator new(__n * sizeof(_Tp)));
//	}
//
//	// __p is not permitted to be a null pointer.
//	void
//		deallocate(pointer __p, size_type)
//	{
//		::operator delete(__p);
//	}
//
//	size_type
//		max_size() const throw()
//	{
//		return size_t(-1) / sizeof(_Tp);
//	}
//
//	// _GLIBCXX_RESOLVE_LIB_DEFECTS
//	// 402. wrong new expression in [some_] allocator::construct
//	void
//		construct(pointer __p, const _Tp& __val)
//	{
//		::new((void*)__p) _Tp(__val);
//	}
//
//#ifdef __GXX_EXPERIMENTAL_CXX0X__
//	template<typename... _Args>
//	void
//		construct(pointer __p, _Args&&... __args)
//	{
//		::new((void*)__p) _Tp(forward<_Args>(__args)...);
//	}
//#endif
//
//	void
//		destroy(pointer __p) { __p->~_Tp(); }
//};
//
//
//
//
//template<typename _Tp>
//class allocator : public new_allocator<_Tp>
//{
//public:
//	typedef size_t     size_type;
//	typedef ptrdiff_t  difference_type;
//	typedef _Tp* pointer;
//	typedef const _Tp* const_pointer;
//	typedef _Tp& reference;
//	typedef const _Tp& const_reference;
//	typedef _Tp        value_type;
//
//	template<typename _Tp1>
//	struct rebind
//	{
//		typedef allocator<_Tp1> other;
//	};
//
//	allocator() throw() { }
//
//	allocator(const allocator& __a) throw()
//		: __glibcxx_base_allocator<_Tp>(__a) { }
//
//	template<typename _Tp1>
//	allocator(const allocator<_Tp1>&) throw() { }
//
//	~allocator() throw() { }
//
//	// Inherit everything else.
//};
//
//
//
//
//class Ref_count_base/* 指针计数管理 */
//{
//public:
//	Ref_count_base() :m_ncount(0)
//	{
//
//	}
//	long GetCount()//获取当前计数
//	{
//		return m_ncount;
//	}
//	int ResetCount(int nAdd)//设置当前计数 1. 计数增加1 ，0. 计数减少1
//	{
//		if (1 == nAdd)
//		{
//			++m_ncount;
//		}
//		else
//		{
//			--m_ncount;
//		}
//		return m_ncount;
//	}
//private:
//	long m_ncount;//计数变量
//};
//
//
//template <typename _Ty>
//class Point_Base/* 在这里做指针计数与数据对象的结合并且都是采用动态分配的方式(通过使用地址)达到数据共享  */
//{
//public:
//	Point_Base()
//	{
//		ref_count = 0;
//	}
//	typedef _Ty* pointer;
//	typedef _Ty& reference;
//protected:
//	pointer m_obj;//共享类指针对象
//	Ref_count_base* ref_count;//计数类指针对象
//};
//
//
//
//
//template <typename Pointer>
//class Test_Pointer : public Point_Base<Pointer>//模板指针调用类
//{
//	typedef Test_Pointer<Pointer> test_pointer;
//	typedef Pointer* pointer;
//	typedef Pointer& reference;
//	typedef allocator<Pointer> alloc_type;
//public:
//
//	virtual ~Test_Pointer()//每次类退出前会执行一次析构函数
//	{
//		if (!ref_count)/* 已经释放的情况下直接返回 */
//		{
//			return;
//		}
//		int ncount = ref_count->ResetCount(0);
//		if (0 == ncount && 0 != m_obj)//如果计数为0而且共享类指针还没有释放，那么这个共享指针没被共享和计数指针一起释放掉
//		{
//			m_alloc.deallocate(m_obj, sizeof(Pointer) * m_nSize);
//			delete ref_count;
//		}
//	}
//	Test_Pointer() :m_nCritical(0), m_nCriticalRun(1), m_nSize(1)//无参数构造函数 分配一个共享类内存
//	{
//		if (0 == ref_count)
//		{
//			ref_count = new Ref_count_base;
//		}
//		ref_count->ResetCount(1);
//		m_obj = m_alloc.allocate(1);
//	}
//
//	template<class _Ux>
//	explicit Test_Pointer(_Ux* _Px) :m_nCritical(0), m_nCriticalRun(1)//有参数构造函数 根据输入的数量进行分配内存
//	{
//		if (0 == ref_count)
//		{
//			ref_count = new Ref_count_base;
//		}
//		ref_count->ResetCount(1);
//		m_obj = m_alloc.allocate(*_Px);
//		m_nSize = *_Px;
//	}
//	pointer operator->() /* 增加临时临界区，在多个线程中保证智能指针数据同步，关于调用类对象的数据需要在线程中增加真正的临界区来同步化 */
//	{
//		if (1 == m_nCriticalRun)
//		{
//			int nRun = m_nCritical;
//			++m_nCritical;
//			while (nRun != 0 && nRun != m_nCritical)
//				;
//			--m_nCritical;
//		}
//		return m_obj;
//	}
//
//	Test_Pointer(test_pointer& _Other)//复制构造函数
//	{
//		*this = _Other;
//		ref_count->ResetCount(1);
//	}
//	void SetCritical(int nRun);//调用共享类成员数据保护临界区 1. 启动 0. 不启动 默认1(在多线程情况下可以看出效果)
//	void Reset();
//	template<class _Ux>
//	void Reset(_Ux* _Px)//把共享计数减一后 ，分配新的共享类内存
//	{
//		if (ref_count && 0 < ref_count->GetCount() && 0 != m_obj)
//		{
//			ref_count->ResetCount(0);
//
//			if (0 == ref_count->GetCount())/* 如果在共享指针计数减一为0的情况(属于没有在别的地方被使用) ，释放共享指针 和共享指针计数 */
//			{
//				m_alloc.deallocate(m_obj, sizeof(Pointer) * m_nSize);
//				delete ref_count;
//			}
//		}
//
//
//		ref_count = new Ref_count_base;
//
//		ref_count->ResetCount(1);
//		m_obj = m_alloc.allocate(*_Px);
//		m_nSize = *_Px;
//	}
//private:
//	alloc_type m_alloc;//内存分配
//	volatile int m_nCritical;//临界区
//	volatile int m_nCriticalRun;//临界区是否运行
//	int m_nSize;//共享类对象内存大小(个数)
//};
//template <typename Pointer>
//inline void Test_Pointer<Pointer>::SetCritical(int nRun)
//{
//	m_nCriticalRun = nRun;
//}
//template <typename Pointer>
//inline void Test_Pointer<Pointer>::Reset()/* 调用无参数Reset 把共享指针计数减一 并且把共享指针计数与共享指针赋值为0 */
//{
//	if (ref_count && 0 < ref_count->GetCount() && 0 != m_obj)
//	{
//		ref_count->ResetCount(0);
//
//		if (0 == ref_count->GetCount())/* 如果在共享指针计数减一为0的情况(属于没有在别的地方被使用) ，释放共享指针 和共享指针计数 */
//		{
//			m_alloc.deallocate(m_obj, sizeof(Pointer) * m_nSize);
//			delete ref_count;
//		}
//		m_obj = 0;
//		ref_count = 0;/* 因为已经脱离了上一个共享指针，所以共享指针 和共享指针计数都指向空 */
//		m_nSize = 0;
//	}
//}

//template<typename T>
//class myShared_ptr {
//public:
//	explicit myShared_ptr(T* ptr = nullptr) : _ptr(ptr), _count(new int(1))
//	{
//	}
//
//	~myShared_ptr()
//	{
//		if (_ptr && --_count == 0) {
//			delete _ptr;
//			delete _count;
//			_ptr = nullptr;
//			_count = nullptr;
//			cout << "deleted in deconstructor" << endl;
//		}
//	}
//
//	//非const版本,此时所有对象共享int*所指计数，要改变other的计数
//	myShared_ptr(myShared_ptr<T>& other)
//	{
//		_ptr = other._ptr;
//		if (_ptr) {
//			_count = &(++ * other._count);
//		}
//	}
//
//	myShared_ptr(myShared_ptr<T>&& tmp)
//	{
//		_ptr = tmp._ptr;
//		if (_ptr) {
//			_conut = tmp._count;
//			tmp._ptr = nullptr;
//			tmp._count = nullptr;
//		}
//	}
//
//	myShared_ptr<T>& operator=(myShared_ptr<T>& other)
//	{
//		if (_ptr && --_count == 0) {
//			delete _ptr;
//			delete _count;
//			_ptr = nullptr;
//			_count = nullptr;
//			cout << "deleted in copy assignment operator" << endl;
//		}
//
//		_ptr = other._ptr;
//		if (_ptr) {
//			_count = &(++ * otehr._count);
//		}
//
//		return *this;
//	}
//
//	T* operator->() { return _ptr; }
//	T& operator*() { return *_ptr; }
//
//	int count() const { return *_count; }
//	T* get() const { return _ptr; }
//
//private:
//	T* _ptr;
//	int* _count;
//};



