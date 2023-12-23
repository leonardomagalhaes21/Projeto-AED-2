//
// Created by tiago on 18-12-2023.
//
using namespace std;


#include "Airline.h"

Airline::Airline(const string& code, const string& name, const string& callsign, const string& country)
        : code(code), name(name), callsign(callsign), country(country) {}

string Airline::getCode() const {
    return code;
}

string Airline::getName() const {
    return name;
}

string Airline::getCallsign() const {
    return callsign;
}

string Airline::getCountry() const {
    return country;
}