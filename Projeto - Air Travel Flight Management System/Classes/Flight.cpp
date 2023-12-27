

#include "Flight.h"

using namespace std;

/**
 * @brief Constructor for the Flight class.
 *
 * @param source The code of the source airport.
 * @param target The code of the target airport.
 * @param airline The code of the operating airline.
 */
Flight::Flight(const string& source, const string& target, const string& airline)
        : source(source), target(target), airline(airline) {}


/**
 * @brief Get the code of the source airport.
 *
 * @return The code of the source airport.
 *
 * @complexity Time Complexity: O(1)
 */
string Flight::getSource() const {
    return source;
}

/**
 * @brief Get the code of the target airport.
 *
 * @return The code of the target airport.
 *
 * @complexity Time Complexity: O(1)
 */
string Flight::getTarget() const {
    return target;
}

/**
 * @brief Get the code of the operating airline.
 *
 * @return The code of the operating airline.
 *
 * @complexity Time Complexity: O(1)
 */
string Flight::getAirline() const {
    return airline;
}