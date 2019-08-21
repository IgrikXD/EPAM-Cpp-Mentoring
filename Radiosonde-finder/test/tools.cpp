#include "tools.h"

std::string parseKmlFile(const std::string src_filename) {

    try {
        //KML file containing the necessary telemetry data (lattitude, longitude, altitude)
        rapidxml::file<> kml_file(src_filename.c_str());
        //KML file content prepared for RapidXML parser operation
        rapidxml::xml_document<> kml_data;

        kml_data.parse<0>(kml_file.data());

        //Declaring a pointer to manipulate with nodes, when created, points to the root node <kml ...>
        rapidxml::xml_node<> * target_node {kml_data.first_node()};
        //Search for the required node
        target_node = target_node -> 
                        first_node("Document") -> // <Document>
                        first_node("Placemark");  // <Placemark id="...">
        //Declaring a pointer to manipulate <Placemark> node attributes
        rapidxml::xml_attribute<> * attr {target_node -> first_attribute()};
        //Checking that the "id" attribute of the <Placemark> node is set to "linestring" (the node that
        //stores the complete radiosonde route record)
        if (std::string_view(attr -> value()) == "linestring") {

            target_node = target_node -> 
                            first_node("LineString") -> // <LineString>
                            first_node("coordinates");  // <coordinates>
        
        }

        return target_node -> value();
        
    }
    catch (const std::runtime_error & e) {

        std::cerr << "Error! Reason: " << e.what() << std::endl;
        
        return "";

    }

}

void getGpsData(std::vector<GpsData> & dst_gps_data, const std::string & src_raw_coordinates) {
    //Constant defining a symbol that divides blocks of GPS coordinates
    constexpr std::string_view delimiter {" "};
    //Vector storing a set of points of the route path of the radiosonde
    std::vector<std::string> gps_points;
    
    try {
        //A function which dividing the coordinate stream into separate GPS points
        boost::split(gps_points, src_raw_coordinates, boost::is_any_of(delimiter));

        for (std::string x : gps_points) {
            //GpsData variable for storing info about one point
            GpsData gps_point;
            //Current offset of GPS point string (used for parsing)
            std::string::size_type offset {0};

            gps_point.setLatitude(std::stod(x, &offset));
            x.erase(0, offset + 1);
            gps_point.setLongitude(std::stod(x, &offset));
            x.erase(0, offset + 1);
            gps_point.setAltitude(std::stod(x));

            dst_gps_data.push_back(gps_point);

        }
    }
    catch (const std::exception & e) {

        std::cerr << "Error! Reason: " << e.what() << std::endl;

    }

}