#include "TimeCheck.h"

#include <Windows.h>

#include "../../DebugView/DebugView/DebugView.h"
#include "../../Time/Time/Time.h"

MOONG::TIME_CHECK::TimeCheck::TimeCheck(const std::string delimiter, const std::string description) :
	start_({ 0 }),
	end_({ 0 })
{
	if (delimiter.empty())
	{
		MOONG::DebugView::setDelimiter("[MOONG_TIME_CHECK]");
	}
	else
	{
		MOONG::DebugView::setDelimiter(delimiter);
	}

	GetLocalTime(&start_);

	if (!description.empty())
	{
		this->setDescription(description);

		MOONG::DebugView::Print("���� �ð�[%s] %s", MOONG::Time::make_date_format(MOONG::Time::get_current_time(), "HOUR�� MINUTE�� SECOND(hour_format:%02d)(minute_format:%02d)(second_format:%02d)��").c_str(), this->getDescription().c_str());
	}
	else
	{
		MOONG::DebugView::Print("���� �ð�[%s]", MOONG::Time::make_date_format(MOONG::Time::get_current_time(), "HOUR�� MINUTE�� SECOND(hour_format:%02d)(minute_format:%02d)(second_format:%02d)��").c_str());
	}
}



MOONG::TIME_CHECK::TimeCheck::~TimeCheck()
{
	GetLocalTime(&end_);

	if(this->getDescription().empty())
	{
		MOONG::DebugView::Print("���� �ð�[%s] (%s �ҿ�)",
			MOONG::Time::make_date_format(MOONG::Time::get_current_time(), "HOUR�� MINUTE�� SECOND(hour_format:%02d)(minute_format:%02d)(second_format:%02d)��").c_str(),
			MOONG::Time::make_time_taken_format(MOONG::Time::calculate_difference_between_times(start_, end_)).c_str()
		);
	}
	else
	{
		MOONG::DebugView::Print("���� �ð�[%s] %s (%s �ҿ�)",
			MOONG::Time::make_date_format(MOONG::Time::get_current_time(), "HOUR(format:02)�� MINUTE(format:02)�� SECOND(format:02)��").c_str(),
			this->getDescription().c_str(),
			MOONG::Time::make_time_taken_format(MOONG::Time::calculate_difference_between_times(start_, end_)).c_str()
		);
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
