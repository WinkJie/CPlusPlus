#pragma warning(disable:4996)
#include "Log.h"

Log::Log()
	:m_bEnabled(true)
{
}

Log::~Log()
{
}

bool Log::Open(string sFileName)
{
	m_tOLogFile.open(sFileName.c_str(), ios_base::out | ios_base::app);

	if (!m_tOLogFile)
	{
		return false;
	}

	return true;
}

void Log::Close()
{
	if (m_tOLogFile.is_open())
	{
		m_tOLogFile.close();
	}
}

bool Log::CommonLogInit(string name)
{
	time_t tNowTime;
	time(&tNowTime);
	tm* tLocalTime = localtime(&tNowTime);
	//得到日期的字符串  
	string sDateStr = ValueToStr(tLocalTime->tm_year + 1900) + "-" +
		ValueToStr(tLocalTime->tm_mon + 1) + "-" +
		ValueToStr(tLocalTime->tm_mday);
	string StrName;
	StrName = Getstr() + "\\Log";
	if (!FilePathExisit(StrName.c_str()))
	{
		//bool flag = CreateDirectoryW(s2ws(StrName), NULL);
		mkdir(StrName.c_str());
	}

	return Open(StrName + "\\"+ name + sDateStr + ".txt");
	
}
bool Log::CommonLogInit(string name, string dir)
{
	time_t tNowTime;
	time(&tNowTime);
	tm* tLocalTime = localtime(&tNowTime);
	//得到日期的字符串  
	string sDateStr = ValueToStr(tLocalTime->tm_year + 1900) + "-" +
		ValueToStr(tLocalTime->tm_mon + 1) + "-" +
		ValueToStr(tLocalTime->tm_mday) + "-" +
		ValueToStr(tLocalTime->tm_hour) + "-" +
		ValueToStr(tLocalTime->tm_min) + "-" +
		ValueToStr(tLocalTime->tm_sec);

	string StrName;
	StrName = Getstr() + "\\" + dir;
	if (!FilePathExisit(StrName.c_str()))
	{
		//bool flag = CreateDirectoryW(s2ws(StrName), NULL);
		mkdir(StrName.c_str());
	}

	return Open(StrName + "\\" + sDateStr + "_" + name  + ".txt");
}
string StringToUtf(string strValue)
{
	int nwLen = MultiByteToWideChar(CP_UTF8, 0, strValue.c_str(), -1, NULL, 0);
	wchar_t* pwBuf = new wchar_t[nwLen + 1];//加上末尾'\0'
	memset(pwBuf, 0, nwLen * 2 + 2);
	MultiByteToWideChar(CP_UTF8, 0, strValue.c_str(), strValue.length(), pwBuf, nwLen);
	int nLen = WideCharToMultiByte(CP_ACP, 0, pwBuf, -1, NULL, NULL, NULL, NULL);
	char* pBuf = new char[nLen + 1];
	memset(pBuf, 0, nLen + 1);
	WideCharToMultiByte(CP_ACP, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);
	std::string retStr = pBuf;
	delete[]pBuf;
	delete[]pwBuf;
	return retStr;
}

void Log::Enable()
{
	m_bEnabled = true;
}

void Log::Disable()
{
	m_bEnabled = false;
}

bool Log::FilePathExisit(string filepath)
{
	if (_access(filepath.c_str(), 0) == -1)
		return false;
	else
		return true;	
}

LPCWSTR Log::s2ws(string& str)
{
	size_t origsize = str.length() + 1;
	const size_t newsize = 100;
	size_t convertedChars = 0;
	wchar_t* wcstring = (wchar_t*)malloc(sizeof(wchar_t) * (str.length() - 1));// 自行释放
	mbstowcs_s(&convertedChars, wcstring, origsize, str.c_str(), _TRUNCATE);	
	std::wstring wstrResult(wcstring);
	free(wcstring);
	return wstrResult.c_str();
}

string Log::Getstr()
{
	char szOldPath[512] = { 0 };
	GetCurrentDirectoryA(512, szOldPath);
	return szOldPath;
}

string Log::GetstrStdio()
{
	char buffer[MAX_PATH];
	getcwd(buffer, MAX_PATH);
	string str = buffer;
	return str;
}

//得到当前时间的字符串  
string Log::GetTimeStr()
{
	time_t tNowTime;
	time(&tNowTime);

	tm* tLocalTime = localtime(&tNowTime);

	//"2011-07-18 23:03:01 ";  
	string strFormat = "%Y-%m-%d %H:%M:%S ";

	char strDateTime[30] = { '\0' };
	strftime(strDateTime, 30, strFormat.c_str(), tLocalTime);

	string strRes = strDateTime;
	strRes = strRes + ":  ";

	return strRes;
}