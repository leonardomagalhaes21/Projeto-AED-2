
#ifndef PROJETO2_AIRPORT_H
#define PROJETO2_AIRPORT_H


#include <string>
#include <vector>
#include "Position.h"

class Airport {
public:
    Airport(const std::string& code, const std::string& name, const std::string& city, const std::string& country,
            double latitude, double longitude);

    std::string getCode() const;
    std::string getName() const;
    std::string getCity() const;
    std::string getCountry() const;
    Position getPosition() const;

private:
    std::string code;       ///< The code of the airport.
    std::string name;       ///< The name of the airport.
    std::string city;       ///< The city where the airport is located.
    std::string country;    ///< The country where the airport is located.
    Position position;      ///< The geographic position of the airport.


};

#endif //PROJETO2_AIRPORT_H
