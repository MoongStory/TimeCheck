#include "TimeCheck.h"

#include <Windows.h>
#include <strsafe.h>

MOONG::TIME_CHECK::TimeCheck::TimeCheck(const std::string delimiter, const std::string description) :
	delimiter_(""),
	description_(""),
	start_(0),
	end_(0)
{
	if (delimiter.empty())
	{
		this->setDelimiter("[MOONG_TIME_CHECK]");
	}
	else
	{
		this->setDelimiter(delimiter);
	}

	start_ = time(NULL);

	struct tm current_time;
	localtime_s(&current_time, &start_);

	if (!description.empty())
	{
		this->setDescription(description);

		this->Print("시작 시간[%02d시 %02d분 %02d초] %s", current_time.tm_hour, current_time.tm_min, current_time.tm_sec, this->getDescription().c_str());
	}
	else
	{
		this->Print("시작 시간[%02d시 %02d분 %02d초]", current_time.tm_hour, current_time.tm_min, current_time.tm_sec);
	}
}



MOONG::TIME_CHECK::TimeCheck::~TimeCheck()
{
	end_ = time(NULL);

	struct tm current_time;
	localtime_s(&current_time, &end_);

	if(this->getDescription().empty())
	{
		this->Print("종료 시간[%02d시 %02d분 %02d초] (%.3lf (Sec) 소요)", current_time.tm_hour, current_time.tm_min, current_time.tm_sec, (double)(this->end_ - this->start_));
	}
	else
	{
		this->Print("종료 시간[%02d시 %02d분 %02d초] %s (%.3lf (Sec) 소요)", current_time.tm_hour, current_time.tm_min, current_time.tm_sec, this->getDescription().c_str(), (double)(this->end_ - this->start_));
	}
}



void MOONG::TIME_CHECK::TimeCheck::Print(const char* const format, ...) const
{
	va_list ap;
	char buf[kMaxBufSize] = { 0 };

	va_start(ap, format);
	StringCchVPrintfA(buf, kMaxBufSize, format, ap);
	va_end(ap);

	std::string debug_string(this->delimiter_);
	debug_string += " ";
	debug_string += buf;

	OutputDebugStringA(debug_string.c_str());
}

const std::string MOONG::TIME_CHECK::TimeCheck::getDelimiter() const
{
	return this->delimiter_;
}

void MOONG::TIME_CHECK::TimeCheck::setDelimiter(const std::string delimiter)
{
	this->delimiter_ = delimiter;
}

const std::string MOONG::TIME_CHECK::TimeCheck::getDescription() const
{
	return this->description_;
}

void MOONG::TIME_CHECK::TimeCheck::setDescription(const std::string description)
{
	this->description_ = description;
}
