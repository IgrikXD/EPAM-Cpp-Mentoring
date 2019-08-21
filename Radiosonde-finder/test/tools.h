#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>

#include "GpsData.h"
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"

//A function that parses a KML file. As a result of work, an object of type string is returned 
//containing a set of GPS coordinates, which subsequently must be processed using the getGpsData 
//function to obtain information about specific GPS points (latitude, longitude, altitude).
// Input arguments:
// const std::string src_filename - KML filename;
// Return value:
// std::string - a set of information about all GPS points on the route;
// Example: 23.5647,56.9878,852 23.5679,56.9846,950 ...;
std::string parseKmlFile(const std::string src_filename);

//A function that converts the stream of source coordinates into an array of specific GPS points
// Input/output arguments:
// std::vector<GpsData> & dst_gps_data - a reference to a vector storing a set of objects of the 
// GpsData type. After the getGpsData function is executed, this vector will store a set of 
// specific GPS point;
// Input arguments:
// const std::string & src_raw_coordinates - a constant reference to an object of type string 
// storing a raw set of GPS coordinates (the result of the parseKmlFile function);
// Return value:
// N/A;
void getGpsData(std::vector<GpsData> & dst_gps_data, const std::string & src_raw_coordinates);

#endif