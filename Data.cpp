//
// Created by tiago on 18-12-2023.
//

#include <unordered_map>
#include "Data.h"
#include <fstream>

using namespace std;

void Data::readAirlines(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo de Airlines." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string code, name, callsign, country;
        std::getline(ss, code, ',');
        std::getline(ss, name, ',');
        std::getline(ss, callsign, ',');
        std::getline(ss, country, ',');

        airlines.insert({code ,Airline{code, name, callsign, country}});
    }

    file.close();
}

void Data::readAirports(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo de Airports." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string code, name, city, country;
        double latitude, longitude;

        std::getline(ss, code, ',');
        std::getline(ss, name, ',');
        std::getline(ss, city, ',');
        std::getline(ss, country, ',');
        ss >> latitude; ss.ignore();
        ss >> longitude; ss.ignore();

        airports.insert({code, Airport{code, name, city, country, latitude, longitude}});
    }

    file.close();
}

void Data::createFlightsGraph(const std::string& filename){
    std::ifstream file(filename);

    flights = Graph(airports.size(), airports, true);

    string source, target, airline, aLine;
    getline(file, aLine);
    while (getline(file, aLine)){
        istringstream inn(aLine);
        getline(inn, source, ',');
        getline(inn, target, ',');
        getline(inn, airline, ',');
        Position p1 = airports.find(source)->second.getPosition();
        Position p2 = airports.find(target)->second.getPosition();
        flights.addEdge(source, target, airline, p1.haversineDistance(p2));
        flights.findVertex(source)->setIndegree(flights.findVertex(source)->getIndegree()+1);
        flights.findVertex(target)->setOutdegree(flights.findVertex(target)->getOutdegree()+1);

    }

}


Graph Data::getFlightsGraph() {
    return flights;
}
unordered_map<string, Airport> Data::getAirports() {
    return airports;
}

unordered_map<string, Airline> Data::getAirlines(){
    return airlines;
};

Airline* Data::getAirline(string code) const {
    auto it = airlines.find(code);
    if (it != airlines.end()) {
        return &(it->second);
    }
    return nullptr;
}

Airport* Data::getAirport(string code) const {
    auto it = airports.find(code);
    if (it != airports.end()) {
        return &(it->second);
    }
    return nullptr;
}
