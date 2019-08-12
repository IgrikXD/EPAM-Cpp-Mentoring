#include "GpsData.h"

GpsData::GpsData() : m_latitude {0}, m_longitude {0}, m_altitude {0}, m_speed {0}, m_course {0} {

}

GpsData::GpsData(double latitude, double longitude, double altitude, double speed, double course)
    : m_latitude {latitude}, m_longitude {longitude}, m_altitude {altitude}, m_speed {speed},
    m_course {course} {

}

double GpsData::getLatitude(void) {

    return m_latitude;

}

double GpsData::getLongitude(void) {

    return m_longitude;

}

double GpsData::getAltitude(void) {

    return m_altitude;

}

double GpsData::getSpeed(void) {

    return m_speed;

}

double GpsData::getCourse(void) {

    return m_course;

}

void GpsData::setLatitude(double latitude) {

    m_latitude = latitude;

}

void GpsData::setLongitude(double longitude) {

    m_longitude = longitude;

}

void GpsData::setAltitude(double altitude) {

    m_altitude = altitude;

}

void GpsData::setSpeed(double speed) {

    m_speed = speed;

}

void GpsData::setCourse(double course) {

    m_course = course;

}