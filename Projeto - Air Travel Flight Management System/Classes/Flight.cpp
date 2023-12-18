//
// Created by tiago on 18-12-2023.
//

#include "Flight.h"

using namespace std;

Flight::Flight(const std::string& source, const std::string& target, const std::string& airline)
        : source(source), target(target), airline(airline) {}

string Flight::getSource() const {
    return source;
}

string Flight::getTarget() const {
    return target;
}

string Flight::getAirline() const {
    return airline;
}