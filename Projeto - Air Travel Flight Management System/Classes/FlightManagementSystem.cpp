//
// Created by tiago on 18-12-2023.
//

#include <set>
#include "FlightManagementSystem.h"


using namespace std;

void FlightManagementSystem::loadAirports() {
    airports = Data::getAirports();
}

void FlightManagementSystem::loadAirlines() {
    airlines = Data::getAirlines();
}

void FlightManagementSystem::loadFlights() {
    flights = Data::getFlightsGraph();
}

int FlightManagementSystem::getGlobalNumberOfAirports() const {
    return airports.size();
}

int FlightManagementSystem::getGlobalNumberOfFlights() const {
    return flights.getVertexSet().size();
}





int FlightManagementSystem::getNumberOfFlightsFromAirport(const string& airportCode) const {
    int count = 0;
    for (auto flight : flights.getVertexSet()) {
        if (flight->getInfo() == airportCode) {
            count++;
        }
    }
    return count;
}

// por implementar//
vector<Flight> FlightManagementSystem::findBestFlightOption(const string& source, const string& destination) const {

}

int FlightManagementSystem::getNumberOfAirlinesFromAirport(const string &airportCode) const {
    auto it = flights.findVertex(airportCode);
    set<string> codes;
    for (const auto *i: flights.getVertexSet()) {
        for (const auto &e: i->getAdj()) {
            codes.insert(e.getDest()->getInfo());
        }
        return codes.size();
    }
}

int FlightManagementSystem::getNumberOfFlightsPerCityOrAirline(const string &cityOrAirline) const {

}

    int FlightManagementSystem::getNumberOfCountriesFromAirport(const string &airportCode) const {
        auto it = flights.findVertex(airportCode);
        set<string> countries;

        for (const auto *i: flights.getVertexSet()) {

            for (const auto& e : i->getAdj())
                countries.insert(e.getDest()->getInfo());
        }
        return countries.size();
    }

    int FlightManagementSystem::getNumberOfDestinationsFromAirport(const string &airportCode) const {
        return 0;
    }

    int
    FlightManagementSystem::getNumberOfReachableDestinationsFromAirport(const string &airportCode, int maxStops) const {
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

    std::vector<Flight>
    FlightManagementSystem::findBestFlightOptionByCoordinates(double latitude, double longitude) const {
        return std::vector<Flight>();
    }
