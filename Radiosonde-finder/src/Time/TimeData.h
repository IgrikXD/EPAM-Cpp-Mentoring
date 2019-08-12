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
        TimeData(const unsigned short hours, const unsigned short minutes, const unsigned short seconds, 
            const unsigned short milliseconds);
        TimeData(const TimeData & time_data);
        unsigned short getHours(void) const;
        unsigned short getMinutes(void) const;
        unsigned short getSeconds(void) const;
        unsigned short getMilliseconds(void) const;
        void setHours(const unsigned short hours);
        void setMinutes(const unsigned short minutes);
        void setSeconds(const unsigned short seconds);
        void setMilliseconds(const unsigned short milliseconds);
};

#endif