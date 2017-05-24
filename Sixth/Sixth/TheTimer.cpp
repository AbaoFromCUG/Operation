#include "stdafx.h"
#include "TheTimer.h"


TheTimer::TheTimer()
{
}


TheTimer::~TheTimer()
{
}

string TheTimer::getTime()
{
	CString str; //获取系统时间
	CTime tm;
	tm = CTime::GetCurrentTime();
	str = tm.Format("%Y-%m-%d-%X");
	string s = str.GetBuffer(0);
	return s;
}
