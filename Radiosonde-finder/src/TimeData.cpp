#include "TimeData.h"

TimeData::TimeData() : m_hours {0}, m_minutes {0}, m_seconds {0}, m_milliseconds {0} {

}

TimeData::TimeData(const unsigned short hours, const unsigned short minutes, 
    const unsigned short seconds, const unsigned short milliseconds) 
    : m_hours {hours}, m_minutes {minutes}, m_seconds {seconds}, m_milliseconds {milliseconds} {

}

TimeData::TimeData(const TimeData & time_data) : m_hours {time_data.m_hours}, 
    m_minutes {time_data.m_hours}, m_seconds {time_data.m_seconds}, 
    m_milliseconds {time_data.m_milliseconds} {

    }
    
unsigned short TimeData::getHours(void) const {
    
    return m_hours;

}

unsigned short TimeData::getMinutes(void) const {
    
    return m_minutes;

}

unsigned short TimeData::getSeconds(void) const {
    
    return m_seconds;

}

unsigned short TimeData::getMilliseconds(void) const {
    
    return m_milliseconds;

}

void TimeData::setHours(const unsigned short hours) {

    m_hours = hours;

}

void TimeData::setMinutes(const unsigned short minutes) {

    m_minutes = minutes;

}

void TimeData::setSeconds(const unsigned short seconds) {

    m_seconds = seconds;

}

void TimeData::setMilliseconds(const unsigned short milliseconds) {

    m_milliseconds = milliseconds;

}