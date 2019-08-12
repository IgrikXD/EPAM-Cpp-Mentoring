#ifndef TIMEDATA_H
#define TIMEDATA_H

class TimeData {
    private:
        unsigned short m_hours;
        unsigned short m_minutes;
        unsigned short m_seconds;
        unsigned short m_milliseconds;
    public:
        TimeData();
        TimeData(unsigned short hours, unsigned short minutes, unsigned short seconds, 
            unsigned short milliseconds);
        unsigned short getHours(void);
        unsigned short getMinutes(void);
        unsigned short getSeconds(void);
        unsigned short getMilliseconds(void);
        void setHours(unsigned short hours);
        void setMinutes(unsigned short minutes);
        void setSeconds(unsigned short seconds);
        void setMilliseconds(unsigned short milliseconds);
};

#endif