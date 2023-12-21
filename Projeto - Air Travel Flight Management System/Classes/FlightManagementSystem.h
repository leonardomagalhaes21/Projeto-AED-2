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

class FlightManagementSystem {
public:

    void loadAirports();
    void loadAirlines();
    void loadFlights();


    int getGlobalNumberOfAirports() const;
    int getGlobalNumberOfFlights() const;
    int getNumberOfFlightsFromAirport(const std::string& airportCode) const;
    int getNumberOfAirlinesFromAirport(const std::string& airportCode) const;
    int getNumberOfFlightsPerCityOrAirline(const std::string& cityOrAirline) const;
    int getNumberOfCountriesFromAirport(const std::string& airportCode) const;
    int getNumberOfDestinationsFromAirport(const std::string& airportCode) const;
    int getNumberOfReachableDestinationsFromAirport(const std::string& airportCode, int maxStops) const;
    std::vector<std::pair<std::string, std::string>> getMaxTripWithStops() const;
    std::string getTopAirportWithMostTraffic() const;
    std::vector<std::string> getEssentialAirports() const;

    
    std::vector<Flight> findBestFlightOption(const std::string& source, const std::string& destination) const;
    std::vector<Flight> findBestFlightOptionByCity(const std::string& sourceCity, const std::string& destinationCity) const;
    std::vector<Flight> findBestFlightOptionByCoordinates(double latitude, double longitude) const;

private:
    std::unordered_map<std::string, Airline> airlines;

    std::unordered_map<std::string, Airport> airports;

    Graph flights;
};
#endif

//PROJETO2_FLIGHTMANAGEMENTSYSTEM_H
