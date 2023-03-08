/*******************************************************************************
MIT License

Copyright (c) 2023 Moong

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*******************************************************************************/

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
			const std::string get_description() const;
			void set_description(const std::string description);

		private:
			std::string description_;
			SYSTEMTIME start_, end_;
		};
	}
}

#endif _TIME_CHECK_H_