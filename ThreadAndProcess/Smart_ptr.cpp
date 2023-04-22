#include "Smart_ptr.h"

Smart_ptr::Smart_ptr(string nameTmp)
{
	name = nameTmp;
	cout << "Node constructor, name=" << name.c_str() << endl;

}

Smart_ptr::~Smart_ptr()
{
	cout << "Node destructor, name=" << name.c_str() << endl;
}

void Smart_ptr::LeakTest()
{
	// �����ڴ�� M_N1
	auto n1 = make_shared<Smart_ptr>("n1");
	// �����ڴ�� M_N2
	auto n2 = make_shared<Smart_ptr>("n2");
	cout << "n1.ref=" << n1.use_count() << ", n2.ref=" << n2.use_count() << endl;
	
	n1->next = n2;
	cout << "n1.ref=" << n1.use_count() << ", n2.ref=" << n2.use_count() << endl;
	
	n2->next = n1;
	// M_N1.ref==2, M_N2.ref==2;
	cout << "n1.ref=" << n1.use_count() << ", n2.ref=" << n2.use_count() << endl;
	// 1. n1������, ��M_N1���ڴ����ü�����Ϊ1, ����n2->next����
	// 2. n2����, ��M_N2���ڴ����ü�����Ϊ1, ����n1->next����
	// 3. �����ڴ�й¶
	
	/// �������
	/// Node constructor, name=n1
	/// Node constructor, name = n2
	/// n1.ref = 1, n2.ref = 1
	/// n1.ref = 1, n2.ref = 2
	/// n1.ref = 2, n2.ref = 2
}

void Smart_ptr::NormalTestN1()
{
	// �����ڴ�� M_N1
	auto n1 = make_shared<Smart_ptr>("n1");
	// �����ڴ�� M_N2
	auto n2 = make_shared<Smart_ptr>("n2");
	cout << "n1.ref=" << n1.use_count() << ", n2.ref=" << n2.use_count() << endl;
	
	n1->next = n2;
	// M_N1.ref==1, M_N2.ref==2;
	cout << "n1.ref=" << n1.use_count() << ", n2.ref=" << n2.use_count() << endl;
	// 1. n1������, ��M_N1���ڴ����ü�����Ϊ0, �ڴ��M_N1��Ҫ����, ���ʱ���ߵ���n1����������, n1����ʱn1->nextҲ������, ��ʱn1->next(���ڴ��M_N2)���ü�����Ϊ1
	// 2. n2����, ��M_N2���ڴ����ü�����Ϊ0, �ڴ��M_N2��Ҫ����
	// 3. ���ڴ�й¶
	
	/// �������
	/// Node constructor, name=n1
	/// Node constructor, name = n2
	/// n1.ref = 1, n2.ref = 1
	/// n1.ref = 1, n2.ref = 2
	/// Node destructor, name = n1
	/// Node destructor, name = n2
}

void Smart_ptr::NormalTestN2()
{
	// �����ڴ�� M_N1
	auto n1 = make_shared<Smart_ptr>("n1");
	// �����ڴ�� M_N2
	    auto n2 = make_shared<Smart_ptr>("n2");
	cout << "n1.ref=" << n1.use_count() << ", n2.ref=" << n2.use_count() << endl;
	
	n2->next = n1;
	// M_N1.ref==1, M_N2.ref==2;
	cout << "n1.ref=" << n1.use_count() << ", n2.ref=" << n2.use_count() << endl;
	// 1. n1������, ��M_N1���ڴ����ü�����Ϊ1
	// 2. n2����, ��M_N2���ڴ����ü�����Ϊ0, �ڴ��M_N2��Ҫ����, ���ʱ���ߵ���n2����������, n2����ʱn2->nextҲ������, ��ʱn2->next(���ڴ��M_N1)���ü�����Ϊ0
	// 3. ��ʱM_N1������, �ߵ�M_N1����������
	// 4. ���ڴ�й¶
	
	/// �������
	/// Node constructor, name=n1
	/// Node constructor, name = n2
	/// n1.ref = 1, n2.ref = 1
	/// n1.ref = 2, n2.ref = 1
	/// Node destructor, name = n2
	 /// Node destructor, name = n1
}
