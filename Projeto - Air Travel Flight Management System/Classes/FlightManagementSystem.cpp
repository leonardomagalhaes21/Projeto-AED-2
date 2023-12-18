//
// Created by tiago on 18-12-2023.
//

#include "FlightManagementSystem.h"


using namespace std;

void FlightManagementSystem::loadAirports(const string& airportsFile) {
    airports = Data::readAirports(airportsFile);
}

void FlightManagementSystem::loadAirlines(const string& airlinesFile) {
    airlines = Data::readAirlines(airlinesFile);
}

void FlightManagementSystem::loadFlights(const string& flightsFile) {
    flights = Data::readFlights(flightsFile);
}

int FlightManagementSystem::getGlobalNumberOfAirports() const {
    return airports.size();
}

int FlightManagementSystem::getGlobalNumberOfFlights() const {
    return flights.size();
}

// por implementar//


int FlightManagementSystem::getNumberOfFlightsFromAirport(const string& airportCode) const {
    int count = 0;
    for (const Flight& flight : flights) {
        if (flight.getSource() == airportCode) {
            count++;
        }
    }
    return count;
}


vector<Flight> FlightManagementSystem::findBestFlightOption(const string& source, const string& destination) const {

}

int FlightManagementSystem::getNumberOfAirlinesFromAirport(const string &airportCode) const {
    return 0;
}

int FlightManagementSystem::getNumberOfFlightsPerCityOrAirline(const string &cityOrAirline) const {
    return 0;
}

int FlightManagementSystem::getNumberOfCountriesFromAirport(const string &airportCode) const {
    return 0;
}

int FlightManagementSystem::getNumberOfDestinationsFromAirport(const string &airportCode) const {
    return 0;
}

int FlightManagementSystem::getNumberOfReachableDestinationsFromAirport(const string &airportCode,int maxStops) const {
    return 0;
}

std::vector<std::pair<std::string, std::string>> FlightManagementSystem::getMaxTripWithStops() const {
    return std::vector<std::pair<std::string, std::string>>();
}

std::string FlightManagementSystem::getTopAirportWithMostTraffic() const {
    return std::string();
}

std::vector<std::string> FlightManagementSystem::getEssentialAirports() const {
    return std::vector<std::string>();
}

std::vector<Flight>
FlightManagementSystem::findBestFlightOptionByCity(const string &sourceCity, const string &destinationCity) const {
    return std::vector<Flight>();
}

std::vector<Flight> FlightManagementSystem::findBestFlightOptionByCoordinates(double latitude, double longitude) const {
    return std::vector<Flight>();
}
