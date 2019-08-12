#include "TelemetryData.h"

TelemetryData::TelemetryData() : m_gps_data {}, m_time_data {}, m_vertical_speed {0} {

} 

TelemetryData::TelemetryData(const GpsData gps_data, const TimeData time_data, 
    const double vertical_speed) 
    : m_gps_data {gps_data}, m_time_data {time_data}, m_vertical_speed {vertical_speed} {

} 

GpsData TelemetryData::getGpsData(void) const {

    return m_gps_data;

}

TimeData TelemetryData::getTimeData(void) const {

    return  m_time_data;

}

double TelemetryData::getVerticalSpeed(void) const {

    return m_vertical_speed;

}

void TelemetryData::setGpsData(const GpsData gps_data) {

    m_gps_data.setLatitude(gps_data.getLatitude());
    m_gps_data.setLongitude(gps_data.getLongitude());
    m_gps_data.setAltitude(gps_data.getAltitude());
    m_gps_data.setSpeed(gps_data.getSpeed());
    m_gps_data.setCourse(gps_data.getCourse());

}

void TelemetryData::setTimeData(const TimeData time_data) {

    m_time_data.setHours(time_data.getHours());
    m_time_data.setMinutes(time_data.getMinutes());
    m_time_data.setSeconds(time_data.getSeconds());
    m_time_data.setMilliseconds(time_data.getMilliseconds());

}