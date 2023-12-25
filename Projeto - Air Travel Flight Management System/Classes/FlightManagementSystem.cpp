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

    return (int) destinations.size() - 1;
}

// acho que esta tá mal
std::vector<std::pair<std::string, std::string>> FlightManagementSystem::getMaxTripWithStops() const {
    int maxStops = 0;
    vector<pair<string,string>> res;
    flights.dfs(maxStops, res);
    cout << maxStops << endl;
    return res;
}

std::string FlightManagementSystem::getTopAirportWithMostTraffic(int k) const {
    for (auto vertex : flights.getVertexSet()){
        vertex->setOutdegree((int) vertex->getAdj().size());
        vertex->setIndegree(0);
    }
    for (auto vertex : flights.getVertexSet()){
        for (const auto& edge : vertex->getAdj()){
            edge.getDest()->setIndegree(edge.getDest()->getIndegree() + 1);
        }
    }
    vector<Vertex*> res = flights.getVertexSet();
    sort(res.begin(), res.end(), [](Vertex* a, Vertex* b) {
        return (a->getIndegree() + a->getOutdegree()) > (b->getIndegree() + b->getOutdegree()); // ordem inversa
    });

    if (k <= 0 || k > flights.getVertexSet().size()) return "";
    return res[k-1]->getInfo();
}

//devia retornar 308 (disseram no grupo wpp), retorna 310 aqui
std::unordered_set<std::string> FlightManagementSystem::getEssentialAirports() const {
    return flights.articulationPoints();
}

std::vector<Flight> FlightManagementSystem::findBestFlightOption(const string &source, const string &destination) const {
    auto path = flights.shortestPathBFS(source, destination);
    vector<Flight> res;
    for(int i = 0; i < path.size()-1; i++){
        Vertex* s = flights.findVertex(path[i]);
        for(auto edge : s->getAdj()){
            if(edge.getDest()->getInfo() == path[i+1]){
                Flight flight= Flight(path[i],path[i+1],edge.getAirline());
                res.push_back(flight);
                break;
            }
        }
    }
    return res;
}

void FlightManagementSystem::findBestFlightOptionByCity(const std::string &sourceCity, const std::string &destinationCity) const {
    vector<string> sourceCodes;
    vector<string> destinationCodes;
    for(auto vertex : flights.getVertexSet()){
        if(airports.find(vertex->getInfo())->second.getCity() == sourceCity){
            sourceCodes.push_back(vertex->getInfo());
        }
        if(airports.find(vertex->getInfo())->second.getCity() == destinationCity){
            destinationCodes.push_back(vertex->getInfo());
        }
    }
    int i = 0;
    int j = 0;
    while(i < sourceCodes.size()){

        cout << "Option " << i+1 << ": " << endl;
        for(const auto& flight : findBestFlightOption(sourceCodes[i], destinationCodes[j])){
            cout << flight.getSource() << " -> " << flight.getTarget() << " " << flight.getAirline() << endl;
        }
        cout << endl;
        i++;
        if(j < destinationCodes.size()-1)
        j++;
    }
}

void FlightManagementSystem::findBestFlightOptionByCoordinates(double latitude, double longitude, const string &destination) const {
    Position position = Position(latitude, longitude);
    int minDistance = INT_MAX;
    for (auto vertex : flights.getVertexSet()) {
        vertex->setNum((int)position.haversineDistance(airports.find(vertex->getInfo())->second.getPosition()));
    }
    vector<string> min;
    for (auto vertex : flights.getVertexSet()){
        if(vertex->getNum() < minDistance){
            minDistance = vertex->getNum();
            min.clear();
            min.push_back(vertex->getInfo());
        }
        else if(vertex->getNum() == minDistance){
            min.push_back(vertex->getInfo());
        }
    }

    int i = 1;
    for (const auto& airport : min){
        cout << "Option " << i << ": " << endl;
        for(const auto& flight : findBestFlightOption(airport,destination)){
            cout << flight.getSource() << " -> " << flight.getTarget() << " " << flight.getAirline() << endl;
        }
       i++;
    }

}

