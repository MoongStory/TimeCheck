#include "TimeCheck.h"

#include <Windows.h>
#include <atlstr.h>
#include <strsafe.h>

MOONG::TIME_CHECK::TimeCheck::TimeCheck(const CStringA delimiter, const CStringA description) :
	delimiter_(""),
	description_(""),
	start_(0),
	end_(0)
{
	if (delimiter.IsEmpty())
	{
		this->Set_delimiter("[MOONG_TIME_CHECK]");
	}
	else
	{
		this->Set_delimiter(delimiter);
	}

	start_ = time(NULL);

	struct tm current_time;
	localtime_s(&current_time, &start_);

	if (!description.IsEmpty())
	{
		this->Set_description(description);

		this->Print("시작 시간[%02d시 %02d분 %02d초] %s", current_time.tm_hour, current_time.tm_min, current_time.tm_sec, this->Get_description());
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

	if(this->Get_description().IsEmpty())
	{
		this->Print("종료 시간[%02d시 %02d분 %02d초] (%.3lf (Sec) 소요)", current_time.tm_hour, current_time.tm_min, current_time.tm_sec, (double)(this->end_ - this->start_));
	}
	else
	{
		this->Print("종료 시간[%02d시 %02d분 %02d초] %s (%.3lf (Sec) 소요)", current_time.tm_hour, current_time.tm_min, current_time.tm_sec, this->description_, (double)(this->end_ - this->start_));
	}
}



void MOONG::TIME_CHECK::TimeCheck::Print(const char* const format, ...) const
{
	va_list ap;
	char buf[kMaxBufSize] = { 0 };

	va_start(ap, format);
	StringCchVPrintfA(buf, kMaxBufSize, format, ap);
	va_end(ap);

	CStringA debug_string;
	debug_string.Format("%s %s", this->delimiter_.GetString(), buf);

	OutputDebugStringA(debug_string.GetString());
}

const CStringA MOONG::TIME_CHECK::TimeCheck::Get_delimiter() const
{
	return this->delimiter_;
}

void MOONG::TIME_CHECK::TimeCheck::Set_delimiter(const CStringA delimiter)
{
	this->delimiter_ = delimiter;
}

const CStringA MOONG::TIME_CHECK::TimeCheck::Get_description() const
{
	return this->description_;
}

void MOONG::TIME_CHECK::TimeCheck::Set_description(const CStringA description)
{
	this->description_ = description;
}
