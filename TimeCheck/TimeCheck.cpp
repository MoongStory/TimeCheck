#include "TimeCheck.h"

#include <Windows.h>
#include <strsafe.h>

#include "../../DebugView/DebugView/DebugView.h"
#include "../../Time/Time/Time.h"

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

	if (!description.empty())
	{
		this->setDescription(description);

		MOONG::DebugView::Print("시작 시간[%s] %s", MOONG::Time::get_current_time("HOUR(format:02)시 MINUTE(format:02)분 SECOND(format:02)초").c_str(), this->getDescription().c_str());
	}
	else
	{
		MOONG::DebugView::Print("시작 시간[%s]", MOONG::Time::get_current_time("HOUR(format:02)시 MINUTE(format:02)분 SECOND(format:02)초").c_str());
	}
}



MOONG::TIME_CHECK::TimeCheck::~TimeCheck()
{
	end_ = time(NULL);

	if(this->getDescription().empty())
	{
		MOONG::DebugView::Print("종료 시간[%s] (%.3lf (Sec) 소요)", MOONG::Time::get_current_time("HOUR(format:02)시 MINUTE(format:02)분 SECOND(format:02)초").c_str(), (double)(this->end_ - this->start_));
	}
	else
	{
		MOONG::DebugView::Print("종료 시간[%s] %s (%.3lf (Sec) 소요)", MOONG::Time::get_current_time("HOUR(format:02)시 MINUTE(format:02)분 SECOND(format:02)초").c_str(), this->getDescription().c_str(), (double)(this->end_ - this->start_));
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
