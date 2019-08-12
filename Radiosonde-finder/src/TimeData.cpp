#include "TimeData.h"

TimeData::TimeData() : m_hours {0}, m_minutes {0}, m_seconds {0}, m_milliseconds {0} {

}

TimeData::TimeData(unsigned short hours, unsigned short minutes, unsigned short seconds, 
    unsigned short milliseconds) 
    : m_hours {hours}, m_minutes {minutes}, m_seconds {seconds}, m_milliseconds {milliseconds} {

}

unsigned short TimeData::getHours(void) {
    
    return m_hours;

}

unsigned short TimeData::getMinutes(void) {
    
    return m_minutes;

}

unsigned short TimeData::getSeconds(void) {
    
    return m_seconds;

}

unsigned short TimeData::getMilliseconds(void) {
    
    return m_milliseconds;

}

void TimeData::setHours(unsigned short hours) {

    m_hours = hours;

}

void TimeData::setMinutes(unsigned short minutes) {

    m_minutes = minutes;

}

void TimeData::setSeconds(unsigned short seconds) {

    m_seconds = seconds;

}

void TimeData::setMilliseconds(unsigned short milliseconds) {

    m_milliseconds = milliseconds;

}