//
// Created by tiago on 18-12-2023.
//

#include "Data.h"
using namespace std;

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

std::vector<Airline> Data::readAirlines(const std::string& filename) {
    // Implemente a leitura do arquivo CSV para Airlines
}

std::vector<Airport> Data::readAirports(const std::string& filename) {
    // Implemente a leitura do arquivo CSV para Airports
}

std::vector<Flight> Data::readFlights(const std::string& filename) {
    // Implemente a leitura do arquivo CSV para Flights
}