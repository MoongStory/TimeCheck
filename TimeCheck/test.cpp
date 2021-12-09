#include <iostream>
#include <atlstr.h>	// Sleep() 사용을 위해

#include "TimeCheck.h"

const char* const timeDelimiter = "[4444 TIME_CHECK]";
const char* const wTimeDelimiter = "[4444 TIME_CHECK]";

int main()
{
	//TIME_CHECK::TimeCheck intervalTestWithDesc(timeDelimiter, "IntervalCheckTest 함수 시간 체크");
	//TIME_CHECK::TimeCheck intervalTestWithDesc(timeDelimiter, __func__);
	MOONG::TIME_CHECK::TimeCheck intervalTestWithDesc(timeDelimiter, __FUNCTION__);
	//TIME_CHECK::TimeCheck intervalTestWithDesc(wTimeDelimiter, __func__);

	//TIME_CHECK::TimeCheck intervalTest(timeDelimiter);
	MOONG::TIME_CHECK::TimeCheck intervalTest(wTimeDelimiter);

	Sleep(3000);

	return EXIT_SUCCESS;
}