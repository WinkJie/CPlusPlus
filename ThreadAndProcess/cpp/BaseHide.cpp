#include "BaseHide.h"

void BaseHide::OverWrite(int x)
{
	cout << "�����еĺ���:" << x << endl;
}

void BaseHide::Over(float x)
{
	cout << "�����еĺ���:" << x << endl;
}

void BaseHide::overridetest()
{
	cout << "���ຯ����" << "  " << endl;
	//system("time");
}

void BaseHide::m_ops()
{
	cout << m_op << endl;
}

void BaseHide::func()
{
	printf("%s \n", "func BaseHide:");
}

void BaseHide::func1()
{
	printf("%s \n", "func1 BaseHide:");

}

void BaseHide::foo()
{
	printf("%s \n", "foo BaseHide:");

}

void SonBaseHide::OverWrite(int x)
{
	cout << "�����еĺ���:" << x << endl;

}

void SonBaseHide::Over()
{
	cout << "�����еĺ���:" << 89 << endl;

}

void SonBaseHide::overridetest()
{
	cout << "�����ຯ����" << "  " << endl;
	//system("time");
}

void SonBaseHide::SonSize()
{
	cout << "�����еĳ�Ա����Ϊ��" << 56 << endl;
}

void SonBaseHide::func()
{
	printf("%s \n", "func SonBaseHide:");

}

void SonBaseHide::func1()
{
	printf("%s \n", "func1 SonBaseHide:");

}

void SonBaseHide::foo()
{
	printf("%s \n", "foo SonBaseHide:");

}
