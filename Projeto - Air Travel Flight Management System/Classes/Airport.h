//
// Created by tiago on 18-12-2023.
//

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
    std::string code;
    std::string name;
    std::string city;
    std::string country;
    Position position;


};

#endif //PROJETO2_AIRPORT_H
