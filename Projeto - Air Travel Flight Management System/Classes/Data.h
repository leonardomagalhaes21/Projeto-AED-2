//
// Created by tiago on 18-12-2023.
//

#ifndef PROJETO2_DATA_H
#define PROJETO2_DATA_H


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Data.h"
#include "Airline.h"
#include "Airport.h"
#include "Flight.h"
class Data {
private:

    std::vector<Airline> airlines;

    std::vector<Airport> airports;

    Graph flights;

public:
    static std::vector<std::vector<std::string>> readCSV(const std::string& filename);

    static void readAirlines(const std::string &filename);

    static void readAirports(const std::string &filename);

    static void readFlights(const std::string &filename);

    Airline* getAirline(string code) const;

    Airport* getAirport(string code) const;

    std::vector<Airport> getAirports() const;

    std::vector<Airline> getAirlines() const;
};


#endif //PROJETO2_DATA_H
