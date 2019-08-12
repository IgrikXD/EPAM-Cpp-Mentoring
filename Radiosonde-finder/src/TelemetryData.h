#ifndef TELEMETRYDATA_H
#define TELEMETRYDATA_H

#include "Gps/GpsData.h"
#include "Time/TimeData.h"

class TelemetryData {
    private:
        GpsData m_gps_data;
        TimeData m_time_data;
        double m_vertical_speed;
    public:
        TelemetryData();
        TelemetryData(const GpsData gps_data, const TimeData time_data, const double vertical_speed);
        GpsData getGpsData(void) const;
        TimeData getTimeData(void) const;
        double getVerticalSpeed(void) const;
        void setGpsData(const GpsData gps_data);
        void setTimeData(const TimeData time_data);
        void setVerticalSpeed(const double vertical_speed);
};

#endif