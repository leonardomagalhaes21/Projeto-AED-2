
#include <unordered_map>
#include "Data.h"
#include <fstream>

using namespace std;

/**
 * @brief Constructor for the Data class.
 *
 * This constructor initializes the Data object by reading information from CSV files and creating the flights graph.
 *
 * @complexity Time Complexity: O(N + M), where N is the number of airlines, and M is the number of airports.
 */
Data::Data() : flights(airports) {
    readAirlines("../dataset/airlines.csv");
    readAirports("../dataset/airports.csv");
    createFlightsGraph("../dataset/flights.csv");
}

/**
 * @brief Read airline information from a CSV file.
 *
 * @param filename The path to the CSV file containing airline information.
 *
 * @info This method reads airline information from a CSV file and populates the airlines unordered_map.
 *
 * @complexity Time Complexity: O(N), where N is the number of airlines in the file.
 */
void Data::readAirlines(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo de Airlines." << endl;
        return;
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        istringstream ss(line);
        string code, name, callsign, country;
        getline(ss, code, ',');
        getline(ss, name, ',');
        getline(ss, callsign, ',');
        getline(ss, country, ',');

        airlines.insert({code ,Airline{code, name, callsign, country}});
    }

    file.close();
}

/**
 * @brief Read airport information from a CSV file.
 *
 * @param filename The path to the CSV file containing airport information.
 *
 * @info This method reads airport information from a CSV file and populates the airports unordered_map.
 *
 * @complexity Time Complexity: O(M), where M is the number of airports in the file.
 */
void Data::readAirports(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo de Airports." << endl;
        return;
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        istringstream ss(line);
        string code, name, city, country;
        double latitude, longitude;

        getline(ss, code, ',');
        getline(ss, name, ',');
        getline(ss, city, ',');
        getline(ss, country, ',');
        ss >> latitude; ss.ignore();
        ss >> longitude; ss.ignore();

        airports.insert({code, Airport{code, name, city, country, latitude, longitude}});
    }

    file.close();
}

/**
 * @brief Create the flights graph based on flight information from a CSV file.
 *
 * @param filename The path to the CSV file containing flight information.
 *
 * @info This method creates the flights graph based on flight information from a CSV file.
 *
 * @complexity Time Complexity: O(N), where N is the number of flights in the file.
 */
void Data::createFlightsGraph(const string& filename){
    ifstream file(filename);

    flights = Graph(airports);

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

/**
 * @brief Get the flights graph.
 *
 * @return The flights graph.
 *
 * @complexity Time Complexity: O(1)
 */
Graph Data::getFlightsGraph() {
    return flights;
}

/**
 * @brief Get the airports unordered_map.
 *
 * @return The unordered_map containing airport information.
 *
 * @complexity Time Complexity: O(1)
 */
unordered_map<string, Airport> Data::getAirports() {
    return airports;
}

/**
 * @brief Get the airlines unordered_map.
 *
 * @return The unordered_map containing airline information.
 *
 * @complexity Time Complexity: O(1)
 */
unordered_map<string, Airline> Data::getAirlines(){
    return airlines;
};

/**
 * @brief Get a pointer to an airline based on its code.
 *
 * @param code The code of the airline.
 *
 * @return A pointer to the Airline object if found, otherwise nullptr.
 *
 * Time Complexity: O(1)
 */
const Airline * Data::getAirline(string code) const {
    auto it = airlines.find(code);
    if (it != airlines.end()) {
        return &(it->second);
    }
    return nullptr;
}

/**
 * @brief Get a pointer to an airport based on its code.
 *
 * @param code The code of the airport.
 *
 * @return A pointer to the Airport object if found, otherwise nullptr.
 *
 * Time Complexity: O(1)
 */
const Airport * Data::getAirport(string code) const {
    auto it = airports.find(code);
    if (it != airports.end()) {
        return &(it->second);
    }
    return nullptr;
}

