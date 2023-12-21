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
#include "Graph.h"

class Data {
private:
//    typedef unordered_set<Airport, airportHash, airportHash> airportHTable;
//    typedef unordered_set<Airline, airlineHash, airlineHash> airlineHTable;

    static std::unordered_map<std::string, Airline> airlines;

    static std::unordered_map<std::string, Airport> airports;

    static Graph flights;

public:


    static void readAirlines(const std::string &filename);

    static void readAirports(const std::string &filename);


    static void createFlightsGraph(const std::string& filename);

    Airline* getAirline(string code) const;

    Airport* getAirport(string code) const;

    static unordered_map<string, Airport> getAirports();

    static std::unordered_map<std::string, Airline> getAirlines();

    static Graph getFlightsGraph();
};


#endif //PROJETO2_DATA_H
