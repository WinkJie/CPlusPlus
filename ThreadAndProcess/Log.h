
#ifndef LOG_H  
#define LOG_H  

#include <fstream>  
#include <string>  
#include <sstream>  
#include <ctime>  
#include <Windows.h>
#include <io.h>
#include <iostream>
#include <direct.h>

#include <direct.h>
#include <stdio.h>

using namespace std;


/**
* �������log�ļ�����.
*/
class Log
{
public:
	Log();
	~Log();

	bool Open(string strFileName);
	void Close();

	bool CommonLogInit(string name); //��Ĭ�ϵ�log �ļ�  
	bool CommonLogInit(string name, string dir);

	void Enable();
	void Disable();
	bool FilePathExisit(string filepath);
	LPCWSTR s2ws(string& str);
	static string Getstr();
	static string GetstrStdio();
	

	string GetTimeStr();
	//string StrName;

	template <typename T> void LogOut(const T& value)
	{
		if (m_bEnabled)
		{
			m_tOLogFile << value;
		}
	}

	template <typename T> void LogOutLn(const T& value)
	{
		if (m_bEnabled)
		{
			m_tOLogFile << GetTimeStr() <<" :"<< value << endl;
		}
	}

	void LogOutLn()
	{
		if (m_bEnabled)
		{
			m_tOLogFile << endl;
		}
	}
	/*
	 *
	 *��������д
	 */
	template <typename T> Log& operator<<(const T& value)
	{
		if (m_bEnabled)
		{
			m_tOLogFile << GetTimeStr() << value;
			cout << GetTimeStr() << ":" << value << endl;
		}
		return (*this);
	}
	
	Log& operator<<(ostream& (*_Pfn)(ostream&))
	{
		if (m_bEnabled)
		{
			(*_Pfn)(m_tOLogFile);
		}
		return (*this);
	}

private:
	template<typename T> string ValueToStr(T value)
	{
		ostringstream ost;
		ost << value;
		return ost.str();
	}
private:
	ofstream m_tOLogFile;

	bool m_bEnabled;
};


#endif  



//https://www.mhyyy.com/play/53740-1-1.html
