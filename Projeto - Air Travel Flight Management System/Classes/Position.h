//
// Created by tiago on 18-12-2023.
//

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
    double latitude;
    double longitude;
    static double toRadians(double degrees);
};



#endif //PROJETO2_POSITION_H
