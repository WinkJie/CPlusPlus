#include "CopyConstructor.h"

CopyConstructor::CopyConstructor()
{
	pointer = new int;
	*pointer = 6;
	this->number = 5;
	cout << "default constructor is " << endl;
}

CopyConstructor::CopyConstructor(const CopyConstructor& obj)
{
	this->number = obj.number;
	this->pointer = obj.pointer;
	cout << "copy constructor is " << endl;
	//delete this->pointer;
	//delete obj.pointer;
}

CopyConstructor::CopyConstructor(int p)
{
	pointer = new int;
	*pointer = p;
	this->number = 5;
	cout << "default constructor is " << endl;
}

CopyConstructor::~CopyConstructor()
{
	/*if (pointer != nullptr)
	{
		delete pointer;
		pointer = nullptr;
	}*/
}

CopyConstructor& CopyConstructor::operator=(const CopyConstructor& obj)
{
	// TODO: 在此处插入 return 语句
	if (this != &obj)
	{
		delete pointer;
		pointer = new int;
		*pointer = *obj.pointer;
	}
	return *this;
}

void CopyConstructor::printop()
{
	cout << "Address:" << pointer << "   value :" << *pointer << endl;
}

int CopyConstructor::GetNumber()
{
	return this->number;
}

int CopyConstructor::InlineTest()
{
	//int x = *pointer;
	return *pointer;
}

void CopyConstructor::fun() noexcept
{
}
