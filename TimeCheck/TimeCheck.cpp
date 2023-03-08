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
		MOONG::DebugView::set_delimiter("[MOONG_TIME_CHECK]");
	}
	else
	{
		MOONG::DebugView::set_delimiter(delimiter);
	}

	GetLocalTime(&start_);

	if (!description.empty())
	{
		this->set_description(description);

		MOONG::DebugView::print("시작 시간[%s] %s", MOONG::Time::make_date_format(MOONG::Time::get_current_time(), "HOUR시 MINUTE분 SECOND(hour_format:%02d)(minute_format:%02d)(second_format:%02d)초").c_str(), this->get_description().c_str());
	}
	else
	{
		MOONG::DebugView::print("시작 시간[%s]", MOONG::Time::make_date_format(MOONG::Time::get_current_time(), "HOUR시 MINUTE분 SECOND(hour_format:%02d)(minute_format:%02d)(second_format:%02d)초").c_str());
	}
}



MOONG::TIME_CHECK::TimeCheck::~TimeCheck()
{
	GetLocalTime(&end_);

	if(this->get_description().empty())
	{
		MOONG::DebugView::print("종료 시간[%s] (%s 소요)",
			MOONG::Time::make_date_format(MOONG::Time::get_current_time(), "HOUR시 MINUTE분 SECOND(hour_format:%02d)(minute_format:%02d)(second_format:%02d)초").c_str(),
			MOONG::Time::make_time_taken_format(MOONG::Time::calculate_difference_between_times(start_, end_)).c_str()
		);
	}
	else
	{
		MOONG::DebugView::print("종료 시간[%s] %s (%s 소요)",
			MOONG::Time::make_date_format(MOONG::Time::get_current_time(), "HOUR(format:02)시 MINUTE(format:02)분 SECOND(format:02)초").c_str(),
			this->get_description().c_str(),
			MOONG::Time::make_time_taken_format(MOONG::Time::calculate_difference_between_times(start_, end_)).c_str()
		);
	}
}

const std::string MOONG::TIME_CHECK::TimeCheck::get_description() const
{
	return this->description_;
}

void MOONG::TIME_CHECK::TimeCheck::set_description(const std::string description)
{
	this->description_ = description;
}
