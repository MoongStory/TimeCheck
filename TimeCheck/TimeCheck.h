// https://github.com/MoongStory/TimeCheck

#if _MSC_VER > 1000
	#pragma once
#endif

#ifndef _TIME_CHECK_H_
#define _TIME_CHECK_H_

#include <wtypes.h>
#include <iostream>

namespace MOONG
{
	namespace TIME_CHECK
	{
		const unsigned int kMaxBufSize = 1024;

		class TimeCheck
		{
		public:	/* 持失切 & 社瑚切 */
			TimeCheck(const std::string delimiter, const std::string description = "");
			~TimeCheck();

		private:
			const std::string getDescription() const;
			void setDescription(const std::string description);

		private:
			std::string description_;
			SYSTEMTIME start_, end_;
		};
	}
}

#endif _TIME_CHECK_H_