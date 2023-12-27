
#include "Airline.h"
using namespace std;
/**
 * @brief Constructor for the Airline class.
 *
 * @param code The code of the airline.
 * @param name The name of the airline.
 * @param callsign The callsign of the airline.
 * @param country The country of the airline.
 */
Airline::Airline(const string& code, const string& name, const string& callsign, const string& country)
        : code(code), name(name), callsign(callsign), country(country) {}

/**
 * @brief Get the code of the airline.
 *
 * @return The code of the airline.
 *
 * @info This method provides access to the airline code.
 *
 * @complexity Time Complexity: O(1)
 */
string Airline::getCode() const {
    return code;
}
/**
 * @brief Get the name of the airline.
 *
 * @return The name of the airline.
 *
 * @info This method provides access to the airline name.
 *
 * @complexity Time Complexity: O(1)
 */
string Airline::getName() const {
    return name;
}

/**
 * @brief Get the callsign of the airline.
 *
 * @return The callsign of the airline.
 *
 * @info This method provides access to the airline callsign.
 *
 * @complexity Time Complexity: O(1)
 */
string Airline::getCallsign() const {
    return callsign;
}
/**
 * @brief Get the country of the airline.
 *
 * @return The country of the airline.
 *
 * @info This method provides access to the airline country.
 *
 * @complexity Time Complexity: O(1)
 */
string Airline::getCountry() const {
    return country;
}