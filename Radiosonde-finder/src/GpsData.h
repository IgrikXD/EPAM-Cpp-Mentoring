#ifndef GPSDATA_H
#define GPSDATA_H

class GpsData {
    private:
        double m_latitude;
        double m_longitude;
        double m_altitude;
        double m_speed;
        double m_course;
    public:
        GpsData();
        GpsData(const double latitude, const double longitude, const double altitude, 
            const double speed, const double course);
        GpsData(const GpsData & gps_data);
        double getLatitude(void) const;
        double getLongitude(void) const;
        double getAltitude(void) const;
        double getSpeed(void) const;
        double getCourse(void) const;
        void setLatitude(const double latitude);
        void setLongitude(const double longitude);
        void setAltitude(const double altitude);
        void setSpeed(const double speed);
        void setCourse(const double course);
};

#endif