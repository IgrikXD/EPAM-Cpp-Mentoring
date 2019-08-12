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
        GpsData(double latitude, double longitude, double altitude, double speed, double course);
        double getLatitude(void);
        double getLongitude(void);
        double getAltitude(void);
        double getSpeed(void);
        double getCourse(void);
        void setLatitude(double latitude);
        void setLongitude(double longitude);
        void setAltitude(double altitude);
        void setSpeed(double speed);
        void setCourse(double course);
};

#endif