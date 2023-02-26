#include <iostream>
#include <atlstr.h>	// Sleep() ����� ����

#include "TimeCheck.h"

const char* const timeDelimiter = "[MOONG_DEBUG TIME_CHECK]";
const wchar_t* const wTimeDelimiter = L"[MOONG_DEBUG TIME_CHECK]";

int main()
{
	//MOONG::TIME_CHECK::TimeCheck intervalTestWithDesc(timeDelimiter, "IntervalCheckTest �Լ� �ð� üũ");
	//MOONG::TIME_CHECK::TimeCheck intervalTestWithDesc(timeDelimiter, __func__);
	MOONG::TIME_CHECK::TimeCheck intervalTestWithDesc(timeDelimiter, __FUNCTION__);
	//MOONG::TIME_CHECK::TimeCheck intervalTestWithDesc(wTimeDelimiter, __func__);

	MOONG::TIME_CHECK::TimeCheck intervalTest(timeDelimiter);
	//MOONG::TIME_CHECK::TimeCheck intervalTest(wTimeDelimiter);

	Sleep(1000);

	return EXIT_SUCCESS;
}