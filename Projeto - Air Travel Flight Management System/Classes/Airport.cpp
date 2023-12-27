
#include "Airport.h"

using namespace std;
/**
 * @brief Constructor for the Airport class.
 *
 * @param code The code of the airport.
 * @param name The name of the airport.
 * @param city The city where the airport is located.
 * @param country The country where the airport is located.
 * @param latitude The latitude of the airport's geographic position.
 * @param longitude The longitude of the airport's geographic position.
 */
Airport::Airport(const string& code, const string& name, const string& city, const string& country,
        double latitude, double longitude)
        : code(code), name(name), city(city), country(country), position(latitude, longitude) {}
/**
 * @brief Gets the code of the airport.
 *
 * @return The code of the airport.
 *
 * @complexity Time Complexity: O(1)
 */
string Airport::getCode() const {
    return code;
}

/**
 * @brief Gets the name of the airport.
 *
 * @return The name of the airport.
 *
 * @complexity Time Complexity: O(1)
 */
string Airport::getName() const {
    return name;
}

/**
 * @brief Gets the city where the airport is located.
 *
 * @return The city where the airport is located.
 *
 * @complexity Time Complexity: O(1)
 */
string Airport::getCity() const {
    return city;
}

/**
 * @brief Gets the country where the airport is located.
 *
 * @return The country where the airport is located.
 *
 * @complexity Time Complexity: O(1)
 */
string Airport::getCountry() const {
    return country;
}

/**
 * @brief Gets the geographic position of the airport.
 *
 * @return The geographic position of the airport.
 *
 * @complexity Time Complexity: O(1)
 */
Position Airport::getPosition() const {
    return position;
}