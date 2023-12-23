//
// Created by tiago on 18-12-2023.
//

#include "Position.h"

using namespace std;

Position::Position(double latitude, double longitude) : latitude(latitude), longitude(longitude) {}

double Position::getLatitude() const {
    return latitude;
}

double Position::getLongitude() const {
    return longitude;
}


double Position::haversineDistance(const Position& other) const {
    const double R = 6371.0; // Raio da Terra em quilômetros
    const double dLat = toRadians(other.latitude - latitude);
    const double dLon = toRadians(other.longitude - longitude);

    const double a = std::sin(dLat / 2) * std::sin(dLat / 2) +
                     std::cos(toRadians(latitude)) * std::cos(toRadians(other.latitude)) *
                     std::sin(dLon / 2) * std::sin(dLon / 2);

    const double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));

    return R * c;
}
double Position::toRadians(double degrees) {
    return degrees * (M_PI / 180.0);
}