#include <iostream>
#include <atlstr.h>	// Sleep() 사용을 위해

#include "TimeCheck.h"

const char* const timeDelimiter = "[MOONG_DEBUG TIME_CHECK]";
const wchar_t* const wTimeDelimiter = L"[MOONG_DEBUG TIME_CHECK]";

int main()
{
	//MOONG::TIME_CHECK::TimeCheck intervalTestWithDesc(timeDelimiter, "IntervalCheckTest 함수 시간 체크");
	//MOONG::TIME_CHECK::TimeCheck intervalTestWithDesc(timeDelimiter, __func__);
	MOONG::TIME_CHECK::TimeCheck intervalTestWithDesc(timeDelimiter, __FUNCTION__);
	//MOONG::TIME_CHECK::TimeCheck intervalTestWithDesc(wTimeDelimiter, __func__);

	MOONG::TIME_CHECK::TimeCheck intervalTest(timeDelimiter);
	//MOONG::TIME_CHECK::TimeCheck intervalTest(wTimeDelimiter);

	Sleep(1000);

	return EXIT_SUCCESS;
}