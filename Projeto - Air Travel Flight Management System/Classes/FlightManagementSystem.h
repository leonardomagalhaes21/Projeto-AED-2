//
// Created by tiago on 18-12-2023.
//

#ifndef PROJETO2_FLIGHTMANAGEMENTSYSTEM_H
#define PROJETO2_FLIGHTMANAGEMENTSYSTEM_H


#include <string>
#include <vector>
#include <unordered_map>

#include "Data.h"
#include "Graph.h"

struct Route {
    std::string source;
    std::string target;
    std::vector<std::string> airlines;
};

class FlightManagementSystem {
public:
    FlightManagementSystem(Data d);

    void loadAirports(Data data);
    void loadAirlines(Data data);
    void loadFlights(Data data);


    int getGlobalNumberOfAirports() const;
    int getGlobalNumberOfFlights() const;
    int getNumberOfFlightsFromAirport(const std::string& airportCode) const;
    int getNumberOfAirlinesFromAirport(const std::string& airportCode) const;
    int getNumberOfFlightsPerCity(const std::string& city) const;
    int getNumberOfFlightsPerAirline(const std::string& airline) const;
    int getNumberOfCountriesFromAirport(const std::string& airportCode) const;
    int getNumberOfCountriesFromCity(const std::string& city) const;
    int getNumberOfDestinationsFromAirport(const std::string& airportCode) const;
    int getNumberOfCitiesFromAirport(const std::string &airportCode) const;
    int getNumberOfReachableDestinationsFromAirport(const std::string& airportCode, int maxStops) const;
    std::vector<std::pair<std::string, std::string>> getMaxTripWithStops() const;
    std::string getTopAirportWithMostTraffic(int k) const;
    unordered_set<string> getEssentialAirports() const;

    
    std::vector<Route> findBestFlightOption(const std::string& source, const std::string& destination) const;
    void findBestFlightOptionByCity(const std::string& sourceCity, const std::string& destinationCity) const;
    void findBestFlightOptionByCoordinates(double latitude, double longitude, const std::string &destination) const;

private:
    std::unordered_map<std::string, Airline> airlines;

    std::unordered_map<std::string, Airport> airports;

    Graph flights = Graph();
};
#endif

//PROJETO2_FLIGHTMANAGEMENTSYSTEM_H
