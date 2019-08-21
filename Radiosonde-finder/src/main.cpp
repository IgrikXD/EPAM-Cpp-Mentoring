#include <iostream>
#include <vector>
#include <string>

#include "GpsData.h"
#include "TimeData.h"
#include "TelemetryData.h"
#include "tools.h"

int main(int argc, char * argv[]) {

    std::string raw_coordinates {parseKmlFile("R2141624.kml")};
    std::vector<GpsData> gps_data;

    getGpsData(gps_data, raw_coordinates);

    /* 
    for (GpsData x : gps_data) {

        std::cout << x.getLatitude() << " " 
                << x.getLongitude() << " " 
                << x.getAltitude() << std::endl;

    }
    */

    return 0;

}