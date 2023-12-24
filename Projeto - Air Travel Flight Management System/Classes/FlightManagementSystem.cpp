//
// Created by tiago on 18-12-2023.
//

#include <set>
#include "FlightManagementSystem.h"


using namespace std;

FlightManagementSystem::FlightManagementSystem(Data d) {
    airports = d.getAirports();
    airlines = d.getAirlines();
    flights = d.getFlightsGraph();
}

// ver o que fazer com estes 3 metodos
void FlightManagementSystem::loadAirports(Data data) {
    airports = data.getAirports();
}

void FlightManagementSystem::loadAirlines(Data data) {
    airlines = data.getAirlines();
}

void FlightManagementSystem::loadFlights(Data data) {
    flights = data.getFlightsGraph();
}

int FlightManagementSystem::getGlobalNumberOfAirports() const {
    return (int) airports.size();
}

int FlightManagementSystem::getGlobalNumberOfFlights() const {
    int count = 0;
    for (auto vertex : flights.getVertexSet()) {
        count += (int) vertex->getAdj().size();
    }
    return count;
}

int FlightManagementSystem::getNumberOfFlightsFromAirport(const string& airportCode) const {
    auto vertex = flights.findVertex(airportCode);

    return (int) vertex->getAdj().size();
}

// por implementar//
vector<Flight> FlightManagementSystem::findBestFlightOption(const string& source, const string& destination) const {
    return vector<Flight>();
}

int FlightManagementSystem::getNumberOfAirlinesFromAirport(const string &airportCode) const {
    auto vertex = flights.findVertex(airportCode);
    set<string> codes;
    for (auto edge : vertex->getAdj()) {
        codes.insert(edge.getAirline());
    }

    return (int) codes.size();
}

int FlightManagementSystem::getNumberOfFlightsPerCity(const string &city) const {
    int count = 0;
    for(auto vertex : flights.getVertexSet()) {
        if (airports.find(vertex->getInfo())->second.getCity() == city) {
            count += (int) vertex->getAdj().size();
        }
    }
    return count;
}

int FlightManagementSystem::getNumberOfFlightsPerAirline(const std::string &airline) const {
    int count = 0;
    for(auto vertex : flights.getVertexSet()) {
        for (auto edge : vertex->getAdj()) {
            if (edge.getAirline() == airline) {
                count++;
            }
        }
    }
    return count;
}

int FlightManagementSystem::getNumberOfCountriesFromAirport(const string &airportCode) const {
    auto vertex = flights.findVertex(airportCode);
    set<string> countries;
    for (const auto& edge : vertex->getAdj()) {
        countries.insert(airports.find(edge.getDest()->getInfo())->second.getCountry());
    }
    return (int) countries.size();
}

int FlightManagementSystem::getNumberOfCountriesFromCity(const string &city) const {
    set<string> countries;
    for(auto vertex : flights.getVertexSet()) {
        if (airports.find(vertex->getInfo())->second.getCity() == city) {
            for (const auto& edge : vertex->getAdj()) {
                countries.insert(airports.find(edge.getDest()->getInfo())->second.getCountry());
            }
        }
    }
    return (int) countries.size();
}


int FlightManagementSystem::getNumberOfDestinationsFromAirport(const string &airportCode) const {
    auto vertex = flights.findVertex(airportCode);
    set<string> destinations;
    for (const auto& edge : vertex->getAdj()) {
        destinations.insert(edge.getDest()->getInfo());
    }
    return (int) destinations.size();
}

int FlightManagementSystem::getNumberOfCitiesFromAirport(const string &airportCode) const {
    auto vertex = flights.findVertex(airportCode);
    set<string> cities;
    for (const auto& edge : vertex->getAdj()) {
        cities.insert(airports.find(edge.getDest()->getInfo())->second.getCity());
    }
    return (int) cities.size();
}


int FlightManagementSystem::getNumberOfReachableDestinationsFromAirport(const string &airportCode, int maxStops) const {
    vector<string> destinations = flights.nodesAtDistanceBFS(airportCode, maxStops+1);

    return (int) destinations.size();
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

    std::vector<Flight>
    FlightManagementSystem::findBestFlightOptionByCoordinates(double latitude, double longitude) const {
        return std::vector<Flight>();
    }

