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
	CString str; //��ȡϵͳʱ��
	CTime tm;
	tm = CTime::GetCurrentTime();
	str = tm.Format("%Y-%m-%d-%X");
	string s = str.GetBuffer(0);
	return s;
}
