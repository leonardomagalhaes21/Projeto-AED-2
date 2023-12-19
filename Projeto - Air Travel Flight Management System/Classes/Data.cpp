//
// Created by tiago on 18-12-2023.
//

#include "Data.h"
using namespace std;
/*
vector<vector<string>> Data::readCSV(const std::string& filename) {
    std::vector<std::vector<std::string>> data;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << std::endl;
        return data;
    }

    string line;
    while (getline(file, line)) {
        vector<std::string> row;
        stringstream ss(line);
        string value;

        while (std::getline(ss, value, ',')) {
            row.push_back(value);
        }

        data.push_back(row);
    }

    file.close();
    return data;
}
*/
void Data::readAirlines(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo de Airlines." << std::endl;
        return airlines;
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

        airlines.push_back(Airline{code, name, callsign, country});
    }

    file.close();
}

void Data::readAirports(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo de Airports." << std::endl;
        return airports;
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

        airports.push_back(Airport{code, name, city, country, latitude, longitude});
    }

    file.close();
}

void Data::readFlights(const std::string& filename) {
    std::vector<Flight> flights;
    std::ifstream file(filename);

    if (!file.is_open()) {

        std::cerr << "Erro ao abrir o arquivo de Flights." << std::endl;
        return flights;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string source, target, airline;

        std::getline(ss, source, ',');
        std::getline(ss, target, ',');
        std::getline(ss, airline, ',');

        flights.push_back(Flight{source, target, airline});
    }

    file.close();
}

//
void Data::createFlightsGraph(const std::string& filename){
    std::ifstream file(filename);

    flights = Graph(airports.size(), airports, true);

    string source, target, airline, aLine;
    getline(filename, aLine);
    while (getline(in, aLine){
        istringstream inn(aLine);
        getline(inn, source, ',');
        getline(inn, target, ',');
        getline(inn, airline, ',');
        Coordinate c1 = airports.find(Airport(source, "", "", "", 0, 0))->getCoordinate();
        Coordinate c2 = airports.find(Airport(target, "", "", "", 0, 0))->getCoordinate();
        flights.addEdge(source, target, airline, c1.distance(c2));
    }
}
//

Graph Data::getFlightsGraph() const{
    return flights;
}
std::vector<Airport> Data::getAirports() const {
    return airports;
}

std::vector<Airline> Data::getAirlines() const{
    return airlines;
};

Airline* Data::getAirline(string code) const{
    for(auto i=airlines.begin();i!=airlines.end();i++){
        if(i->getCode()=code){
            return i;
        }
}

Airport* Data::getAirport(string code) const{
    for(auto i = airports.begin(); i != airports.end(); i++){
        if(i->getCode() == code){
            return i;
        }
    }
}
