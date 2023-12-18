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
public:
    static std::vector<std::vector<std::string>> readCSV(const std::string& filename);

    static std::vector<Airline> readAirlines(const std::string &filename);

    static std::vector<Airport> readAirports(const std::string &filename);

    static std::vector<Flight> readFlights(const std::string &filename);
};


#endif //PROJETO2_DATA_H
