// https://github.com/MoongStory/TimeCheck

// TODO: char, wchar_t 자료형 CString으로 변경.

#if _MSC_VER > 1000
	#pragma once
#endif

#ifndef _TIME_CHECK_H_
#define _TIME_CHECK_H_

#include <ctime>
namespace MOONG
{
	namespace TIME_CHECK
	{
		const unsigned int kMaxBufSize = 1024;

		class TimeCheck
		{
		public:	/* 생성자 & 소멸자 */
			TimeCheck(const char* const delimiter, const char* const description = "");
			TimeCheck(const wchar_t* const delimiter, const wchar_t* const description = L"");
			~TimeCheck();

		private:
			void Print(const char* const format, ...);

		private:
			char* delimiter_;
			char* description_;
			time_t start_, end_;
		};
	}
}

#endif _TIME_CHECK_H_