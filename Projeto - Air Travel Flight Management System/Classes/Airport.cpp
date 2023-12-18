//
// Created by tiago on 18-12-2023.
//

#include "Airport.h"

using namespace std;
Airport::Airport(const string& code, const string& name, const string& city, const string& country,
        double latitude, double longitude)
        : code(code), name(name), city(city), country(country), position(latitude, longitude) {}

string Airport::getCode() const {
    return code;
}

string Airport::getName() const {
    return name;
}

string Airport::getCity() const {
    return city;
}

string Airport::getCountry() const {
    return country;
}

Position Airport::getPosition() const {
    return position;
}