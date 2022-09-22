// https://github.com/MoongStory/TimeCheck

// TODO: char, wchar_t �ڷ��� string, wstring���� ����.
// TODO: getter, setter �߰�.

#if _MSC_VER > 1000
	#pragma once
#endif

#ifndef _TIME_CHECK_H_
#define _TIME_CHECK_H_

#include <ctime>
#include <iostream>

namespace MOONG
{
	namespace TIME_CHECK
	{
		const unsigned int kMaxBufSize = 1024;

		class TimeCheck
		{
		public:	/* ������ & �Ҹ��� */
			TimeCheck(const std::string delimiter, const std::string description = "");
			~TimeCheck();

		private:
			void Print(const char* const format, ...) const;

			const std::string getDelimiter() const;
			void setDelimiter(const std::string delimiter);

			const std::string getDescription() const;
			void setDescription(const std::string description);

		private:
			std::string delimiter_;
			std::string description_;
			time_t start_, end_;
		};
	}
}

#endif _TIME_CHECK_H_