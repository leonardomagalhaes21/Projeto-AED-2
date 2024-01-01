
#ifndef PROJETO2_DATA_H
#define PROJETO2_DATA_H


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include "Airline.h"
#include "Airport.h"
#include "Flight.h"
#include "Graph.h"

class Data {
private:

    std::unordered_map<std::string, Airline> airlines;

    std::unordered_map<std::string, Airport> airports;

    Graph flights;

public:

    Data();

    void readAirlines(const std::string &filename);

    void readAirports(const std::string &filename);


    void createFlightsGraph(const std::string& filename);

    const Airline * getAirline(string code) const;

    const Airport * getAirport(string code) const;

    unordered_map<string, Airport> getAirports();

    std::unordered_map<std::string, Airline> getAirlines();

    Graph getFlightsGraph();

};


#endif //PROJETO2_DATA_H
