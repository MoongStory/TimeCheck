#include "TimeCheck.h"

#include <Windows.h>
#include <strsafe.h>

#include "../../DebugView/DebugView/DebugView.h"

MOONG::TIME_CHECK::TimeCheck::TimeCheck(const std::string delimiter, const std::string description) :
	start_(0),
	end_(0)
{
	if (delimiter.empty())
	{
		MOONG::DebugView::setDelimiter("[MOONG_TIME_CHECK]");
	}
	else
	{
		MOONG::DebugView::setDelimiter(delimiter);
	}

	start_ = time(NULL);

	struct tm current_time;
	localtime_s(&current_time, &start_);

	if (!description.empty())
	{
		this->setDescription(description);

		MOONG::DebugView::Print("시작 시간[%02d시 %02d분 %02d초] %s", current_time.tm_hour, current_time.tm_min, current_time.tm_sec, this->getDescription().c_str());
	}
	else
	{
		MOONG::DebugView::Print("시작 시간[%02d시 %02d분 %02d초]", current_time.tm_hour, current_time.tm_min, current_time.tm_sec);
	}
}



MOONG::TIME_CHECK::TimeCheck::~TimeCheck()
{
	end_ = time(NULL);

	struct tm current_time;
	localtime_s(&current_time, &end_);

	if(this->getDescription().empty())
	{
		MOONG::DebugView::Print("종료 시간[%02d시 %02d분 %02d초] (%.3lf (Sec) 소요)", current_time.tm_hour, current_time.tm_min, current_time.tm_sec, (double)(this->end_ - this->start_));
	}
	else
	{
		MOONG::DebugView::Print("종료 시간[%02d시 %02d분 %02d초] %s (%.3lf (Sec) 소요)", current_time.tm_hour, current_time.tm_min, current_time.tm_sec, this->getDescription().c_str(), (double)(this->end_ - this->start_));
	}
}

const std::string MOONG::TIME_CHECK::TimeCheck::getDescription() const
{
	return this->description_;
}

void MOONG::TIME_CHECK::TimeCheck::setDescription(const std::string description)
{
	this->description_ = description;
}
