
#ifndef PROJETO2_POSITION_H
#define PROJETO2_POSITION_H


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>


class Position {
public:
    Position(double latitude, double longitude);
    double getLatitude() const;
    double getLongitude() const;
    double haversineDistance(const Position& other) const ;

private:
    double latitude;        ///< latitude in degrees
    double longitude;       ///< longitude in degrees
    static double toRadians(double degrees);    ///< converts degrees to radians
};



#endif //PROJETO2_POSITION_H
