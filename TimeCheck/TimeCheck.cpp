#include "TimeCheck.h"

#include <Windows.h>
#include <atlstr.h>
#include <strsafe.h>

MOONG::TIME_CHECK::TimeCheck::TimeCheck(CStringA delimiter, CStringA description) :
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

		this->Print("���� �ð�[%02d�� %02d�� %02d��] %s", current_time.tm_hour, current_time.tm_min, current_time.tm_sec, this->Get_description());
	}
	else
	{
		this->Print("���� �ð�[%02d�� %02d�� %02d��]", current_time.tm_hour, current_time.tm_min, current_time.tm_sec);
	}
}



MOONG::TIME_CHECK::TimeCheck::~TimeCheck()
{
	end_ = time(NULL);

	struct tm current_time;
	localtime_s(&current_time, &end_);

	if(this->Get_description().IsEmpty())
	{
		this->Print("���� �ð�[%02d�� %02d�� %02d��] (%.3lf (Sec) �ҿ�)", current_time.tm_hour, current_time.tm_min, current_time.tm_sec, (double)(this->end_ - this->start_));
	}
	else
	{
		this->Print("���� �ð�[%02d�� %02d�� %02d��] %s (%.3lf (Sec) �ҿ�)", current_time.tm_hour, current_time.tm_min, current_time.tm_sec, this->description_, (double)(this->end_ - this->start_));
	}
}



void MOONG::TIME_CHECK::TimeCheck::Print(const char* const format, ...)
{
	va_list ap;
	char buf[kMaxBufSize] = { 0 };

	va_start(ap, format);
	StringCchVPrintfA(buf, kMaxBufSize, format, ap);
	va_end(ap);

	CStringA debug_string;
	debug_string.Format("%s %s", this->delimiter_, buf);

	OutputDebugStringA(debug_string.GetBuffer());
}

CStringA MOONG::TIME_CHECK::TimeCheck::Get_delimiter()
{
	return this->delimiter_;
}

void MOONG::TIME_CHECK::TimeCheck::Set_delimiter(CStringA delimiter)
{
	this->delimiter_ = delimiter;
}

CStringA MOONG::TIME_CHECK::TimeCheck::Get_description()
{
	return this->description_;
}

void MOONG::TIME_CHECK::TimeCheck::Set_description(CStringA description)
{
	this->description_ = description;
}
