#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
/*�ڶ�����*/
//#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility> //����pair

using namespace std;
/*����ָ����*/

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
 *����shared_ptrָ��ļ�����ܣ�
 *  1.����ָ���ڿ��������п������е�ָ����������ַ�ﵽ��������(�򵥵�˵����һ��������ַ�ɶ��ָ��ͬʱָ����ʹ��)��
 *  2.����ָ���ڲ�ͨ��������ʽ����¼�������������ڴ�Ĵ���(��������ָ�����ʱ����Ϊ1��ÿ������һ��(��ֵ������¶���)������1)��ÿ�ͷ�һ������ָ����������1����ָ�����Ϊ0ʱ�ͷŹ������������ڴ棻
 *  3.shared_ptr�๲��ָ���ڴ漰��������ڴ���û��ͨ���ֶ��ͷŵ�����£�����ͨ�������������������ڴ��ͷŹ�����
 */
//template<typename _Tp>
//class new_allocator//������ģ�������е��ڴ�����࣬��֤���������Ƭ���ٵ�ͬʱ�����������Ч��
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
//class Ref_count_base/* ָ��������� */
//{
//public:
//	Ref_count_base() :m_ncount(0)
//	{
//
//	}
//	long GetCount()//��ȡ��ǰ����
//	{
//		return m_ncount;
//	}
//	int ResetCount(int nAdd)//���õ�ǰ���� 1. ��������1 ��0. ��������1
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
//	long m_ncount;//��������
//};
//
//
//template <typename _Ty>
//class Point_Base/* ��������ָ����������ݶ���Ľ�ϲ��Ҷ��ǲ��ö�̬����ķ�ʽ(ͨ��ʹ�õ�ַ)�ﵽ���ݹ���  */
//{
//public:
//	Point_Base()
//	{
//		ref_count = 0;
//	}
//	typedef _Ty* pointer;
//	typedef _Ty& reference;
//protected:
//	pointer m_obj;//������ָ�����
//	Ref_count_base* ref_count;//������ָ�����
//};
//
//
//
//
//template <typename Pointer>
//class Test_Pointer : public Point_Base<Pointer>//ģ��ָ�������
//{
//	typedef Test_Pointer<Pointer> test_pointer;
//	typedef Pointer* pointer;
//	typedef Pointer& reference;
//	typedef allocator<Pointer> alloc_type;
//public:
//
//	virtual ~Test_Pointer()//ÿ�����˳�ǰ��ִ��һ����������
//	{
//		if (!ref_count)/* �Ѿ��ͷŵ������ֱ�ӷ��� */
//		{
//			return;
//		}
//		int ncount = ref_count->ResetCount(0);
//		if (0 == ncount && 0 != m_obj)//�������Ϊ0���ҹ�����ָ�뻹û���ͷţ���ô�������ָ��û������ͼ���ָ��һ���ͷŵ�
//		{
//			m_alloc.deallocate(m_obj, sizeof(Pointer) * m_nSize);
//			delete ref_count;
//		}
//	}
//	Test_Pointer() :m_nCritical(0), m_nCriticalRun(1), m_nSize(1)//�޲������캯�� ����һ���������ڴ�
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
//	explicit Test_Pointer(_Ux* _Px) :m_nCritical(0), m_nCriticalRun(1)//�в������캯�� ����������������з����ڴ�
//	{
//		if (0 == ref_count)
//		{
//			ref_count = new Ref_count_base;
//		}
//		ref_count->ResetCount(1);
//		m_obj = m_alloc.allocate(*_Px);
//		m_nSize = *_Px;
//	}
//	pointer operator->() /* ������ʱ�ٽ������ڶ���߳��б�֤����ָ������ͬ�������ڵ���������������Ҫ���߳��������������ٽ�����ͬ���� */
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
//	Test_Pointer(test_pointer& _Other)//���ƹ��캯��
//	{
//		*this = _Other;
//		ref_count->ResetCount(1);
//	}
//	void SetCritical(int nRun);//���ù������Ա���ݱ����ٽ��� 1. ���� 0. ������ Ĭ��1(�ڶ��߳�����¿��Կ���Ч��)
//	void Reset();
//	template<class _Ux>
//	void Reset(_Ux* _Px)//�ѹ��������һ�� �������µĹ������ڴ�
//	{
//		if (ref_count && 0 < ref_count->GetCount() && 0 != m_obj)
//		{
//			ref_count->ResetCount(0);
//
//			if (0 == ref_count->GetCount())/* ����ڹ���ָ�������һΪ0�����(����û���ڱ�ĵط���ʹ��) ���ͷŹ���ָ�� �͹���ָ����� */
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
//	alloc_type m_alloc;//�ڴ����
//	volatile int m_nCritical;//�ٽ���
//	volatile int m_nCriticalRun;//�ٽ����Ƿ�����
//	int m_nSize;//����������ڴ��С(����)
//};
//template <typename Pointer>
//inline void Test_Pointer<Pointer>::SetCritical(int nRun)
//{
//	m_nCriticalRun = nRun;
//}
//template <typename Pointer>
//inline void Test_Pointer<Pointer>::Reset()/* �����޲���Reset �ѹ���ָ�������һ ���Ұѹ���ָ������빲��ָ�븳ֵΪ0 */
//{
//	if (ref_count && 0 < ref_count->GetCount() && 0 != m_obj)
//	{
//		ref_count->ResetCount(0);
//
//		if (0 == ref_count->GetCount())/* ����ڹ���ָ�������һΪ0�����(����û���ڱ�ĵط���ʹ��) ���ͷŹ���ָ�� �͹���ָ����� */
//		{
//			m_alloc.deallocate(m_obj, sizeof(Pointer) * m_nSize);
//			delete ref_count;
//		}
//		m_obj = 0;
//		ref_count = 0;/* ��Ϊ�Ѿ���������һ������ָ�룬���Թ���ָ�� �͹���ָ�������ָ��� */
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
//	//��const�汾,��ʱ���ж�����int*��ָ������Ҫ�ı�other�ļ���
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



