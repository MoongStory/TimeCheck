// https://github.com/MoongStory/TimeCheck

// TODO: char, wchar_t �ڷ��� CString���� ����.
// TODO: getter, setter �߰�.

#if _MSC_VER > 1000
	#pragma once
#endif

#ifndef _TIME_CHECK_H_
#define _TIME_CHECK_H_

#include <ctime>
#include <atlstr.h>

namespace MOONG
{
	namespace TIME_CHECK
	{
		const unsigned int kMaxBufSize = 1024;

		class TimeCheck
		{
		public:	/* ������ & �Ҹ��� */
			TimeCheck(CStringA delimiter, CStringA description = "");
			~TimeCheck();

		private:
			void Print(const char* const format, ...) const;

			CStringA Get_delimiter() const;
			void Set_delimiter(CStringA delimiter);

			CStringA Get_description() const;
			void Set_description(CStringA description);

		private:
			CStringA delimiter_;
			CStringA description_;
			time_t start_, end_;
		};
	}
}

#endif _TIME_CHECK_H_