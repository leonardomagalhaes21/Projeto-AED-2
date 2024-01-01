
#include "Position.h"

using namespace std;

Position::Position(double latitude, double longitude) : latitude(latitude), longitude(longitude) {}

/**
 * @brief Gets the latitude of the position
 *
 * @return latitude
 *
 * @complexity Time complexity: O(1)
 */
double Position::getLatitude() const {
    return latitude;
}

/**
 * @brief Gets the longitude of the position
 *
 * @return longitude
 *
 * @complexity Time complexity: O(1)
 */
double Position::getLongitude() const {
    return longitude;
}

/**
     * @brief Calculate the Haversine distance between two positions.
     *
     * @param other The other position.
     * @return The Haversine distance between the positions in kilometers.
     *
     * @info The Haversine distance is the great-circle distance between two points on the sphere.
     * The formula calculates the shortest distance over the earth's surface, giving an "as-the-crow-flies" distance
     * between the points.
     *
     * @complexity Time complexity: O(1)
     *
     * @see https://en.wikipedia.org/wiki/Haversine_formula
     */
double Position::haversineDistance(const Position& other) const {
    const double R = 6371.0;
    const double dLat = toRadians(other.latitude - latitude);
    const double dLon = toRadians(other.longitude - longitude);

    const double a = sin(dLat / 2) * sin(dLat / 2) +
                     cos(toRadians(latitude)) * cos(toRadians(other.latitude)) *
                     sin(dLon / 2) * sin(dLon / 2);

    const double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return R * c;
}

/**
 * @brief Converts degrees to radians
 *
 * @param degrees The degrees to be converted
 *
 * @return The radians
 *
 * @complexity Time complexity: O(1)
 */
double Position::toRadians(double degrees) {
    return degrees * (M_PI / 180.0);
}