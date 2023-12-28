
#ifndef PROJETO2_FLIGHTMANAGEMENTSYSTEM_H
#define PROJETO2_FLIGHTMANAGEMENTSYSTEM_H


#include <string>
#include <vector>
#include <unordered_map>
#include <map>

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
    void numberOfFlightsPerCity() const;
    void numberOfFlightsPerAirline() const;
    int getNumberOfCountriesFromAirport(const std::string& airportCode) const;
    int getNumberOfCountriesFromCity(const std::string& city, const std::string &country) const;
    void numberOfReachableDestinationsFromAirport(const std::string &airportCode) const;
    int getNumberOfReachableDestinationsFromAirportWithStops(const std::string &airportCode, int maxStops) const;
    void getMaxTripWithStops();
    int calcStopsBFS(Vertex *source, vector<std::pair<std::string, std::string>> &aux);
    void getTopAirportWithMostTraffic(int k) const;
    unordered_set<string> getEssentialAirports() const;

    
    std::vector<Route> findBestFlightOption(const std::string& source, const std::string& destination) const;
    void findBestFlightOptionByAirportName(const std::string &source, const std::string &destination) const;
    void findBestFlightOptionByCity(const std::string &sourceCity, const std::string &sourceCountry, const std::string &destinationCity, const std::string &destinationCountry) const;
    void findBestFlightOptionByCoordinates(double latitude, double longitude, const std::string &destination) const;
    std::vector<Route> findBestFlightOptionWithGivenAirlines(const std::string& source, const std::string& destination,const std::vector<std::string> &selectedAirlines) const;

private:
    std::unordered_map<std::string, Airline> airlines;      ///< Map of airlines

    std::unordered_map<std::string, Airport> airports;      ///< Map of airports

    Graph flights = Graph();                                ///< Graph of flights
};
#endif

//PROJETO2_FLIGHTMANAGEMENTSYSTEM_H
