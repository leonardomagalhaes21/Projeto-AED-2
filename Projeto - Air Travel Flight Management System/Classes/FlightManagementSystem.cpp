

#include <set>

#include "FlightManagementSystem.h"
#include <climits>

using namespace std;

/**
 * @brief Constructs a new FlightManagementSystem object
 *
 * @param d Data object
 *
 * @complexity Time complexity: O(1)
 */
FlightManagementSystem::FlightManagementSystem(Data d) {
    airports = d.getAirports();
    airlines = d.getAirlines();
    flights = d.getFlightsGraph();
}

/**
 * @brief Gets the number of airports in the system
 *
 * @return number of airports
 *
 * @complexity Time complexity: O(1)
 */
int FlightManagementSystem::getGlobalNumberOfAirports() const {
    return (int) airports.size();
}

/**
 * @brief Get the global number of flights.
 *
 * @return The total number of flights in the system.
 *
 * @complexity Time complexity: O(V + E), where V is the number of vertices and E is the number of edges in the flights graph.
 */
int FlightManagementSystem::getGlobalNumberOfFlights() const {
    int count = 0;
    for (auto vertex : flights.getVertexSet()) {
        count += (int) vertex->getAdj().size();
    }
    return count;
}

/**
 * @brief Get the number of flights departing from a specific airport.
 *
 * @param airportCode The code of the airport.
 *
 * @return The number of flights departing from the specified airport.
 *
 * @complexity Time Complexity: O(E), where E is the number of edges in the flights graph.
 */
int FlightManagementSystem::getNumberOfFlightsFromAirport(const string& airportCode) const {
    auto vertex = flights.findVertex(airportCode);

    return (int) vertex->getAdj().size();
}

/**
 * @brief Get the number of airlines operating from a specific airport.
 *
 * @param airportCode The code of the airport.
 *
 * @return The number of unique airlines operating from the specified airport.
 *
 * @complexity Time Complexity: O(E), where E is the number of edges in the flights graph.
 */
int FlightManagementSystem::getNumberOfAirlinesFromAirport(const string &airportCode) const {
    auto vertex = flights.findVertex(airportCode);
    set<string> codes;
    for (auto edge : vertex->getAdj()) {
        codes.insert(edge.getAirline());
    }

    return (int) codes.size();
}

/**
 * @brief Get the number of flights departing from a specific city.
 *
 * @param city The name of the city.
 *
 * @return The number of flights departing from the specified city.
 *
 * @complexity Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the flights graph.
 */
int FlightManagementSystem::getNumberOfFlightsPerCity(const string &city) const {
    int count = 0;
    for(auto vertex : flights.getVertexSet()) {
        if (airports.find(vertex->getInfo())->second.getCity() == city) {
            count += (int) vertex->getAdj().size();
        }
    }
    return count;
}

/**
 * @brief Get the number of flights operated by a specific airline.
 *
 * @param airline The code of the airline.
 *
 * @return The number of flights operated by the specified airline.
 *
 * @complexity Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the flights graph.
 */
int FlightManagementSystem::getNumberOfFlightsPerAirline(const string &airline) const {
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

/**
 * @brief Get the number of countries connected to a specific airport.
 *
 * @param airportCode The code of the airport.
 *
 * @return The number of unique countries connected to the specified airport.
 *
 * @complexity Time Complexity: O(E), where E is the number of edges in the flights graph.
 */
int FlightManagementSystem::getNumberOfCountriesFromAirport(const string &airportCode) const {
    auto vertex = flights.findVertex(airportCode);
    set<string> countries;
    for (const auto& edge : vertex->getAdj()) {
        countries.insert(airports.find(edge.getDest()->getInfo())->second.getCountry());
    }
    return (int) countries.size();
}

/**
 * @brief Get the number of countries connected to a specific city.
 *
 * @param city The name of the city.
 *
 * @return The number of unique countries connected to the specified city.
 *
 * @complexity Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the flights graph.
 */
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

/**
 * @brief Get the number of destinations connected to a specific airport.
 *
 * @param airportCode The code of the airport.
 *
 * @return The number of unique destinations connected to the specified airport.
 *
 * @complexity Time Complexity: O(E), where E is the number of edges in the flights graph.
 */
int FlightManagementSystem::getNumberOfDestinationsFromAirport(const string &airportCode) const {
    auto vertex = flights.findVertex(airportCode);
    set<string> destinations;
    for (const auto& edge : vertex->getAdj()) {
        destinations.insert(edge.getDest()->getInfo());
    }
    return (int) destinations.size();
}

/**
 * @brief Get the number of cities connected to a specific airport.
 *
 * @param airportCode The code of the airport.
 *
 * @return The number of unique cities connected to the specified airport.
 *
 * @complexity Time Complexity: O(E), where E is the number of edges in the flights graph.
 */
int FlightManagementSystem::getNumberOfCitiesFromAirport(const string &airportCode) const {
    auto vertex = flights.findVertex(airportCode);
    set<string> cities;
    for (const auto& edge : vertex->getAdj()) {
        cities.insert(airports.find(edge.getDest()->getInfo())->second.getCity());
    }
    return (int) cities.size();
}

/**
 * @brief Get the number of reachable destinations from a specific airport with a maximum number of stops.
 *
 * @param airportCode The code of the airport.
 * @param maxStops The maximum number of stops.
 *
 * @return The number of reachable destinations from the specified airport with a maximum number of stops.
 *
 * @complexity Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the flights graph.
 */
int FlightManagementSystem::getNumberOfReachableDestinationsFromAirport(const string &airportCode, int maxStops) const {
    vector<string> destinations = flights.nodesAtDistanceBFS(airportCode, maxStops+1);

    return (int) destinations.size() - 1;
}

void FlightManagementSystem::getMaxTripWithStops() {
    int maxStops = 0;
    vector<pair<string, string>> maxTripAirports;

    for (auto sourceVertex : flights.getVertexSet()) {
        vector<pair<string,string>> aux;
        int stops = calcStopsBFS(sourceVertex, aux);
        if (stops > maxStops) {
            maxStops = stops;
            maxTripAirports = aux;
        }
        else if (stops == maxStops) {
            maxTripAirports.insert(maxTripAirports.end(), aux.begin(), aux.end());
        }
    }

    cout << "Maximum Trips have " << maxStops << " stops: " << endl;
    for (const auto& airports : maxTripAirports) {
        cout << airports.first << " --> " << airports.second << endl;
    }
}

int FlightManagementSystem::calcStopsBFS(Vertex* source, vector<pair<string,string>> &aux) {
    int maxdistance = 0;

    for (auto vertex : flights.getVertexSet()) {
        vertex->setVisited(false);
        vertex->setProcessing(false);
    }

    queue<pair<Vertex*, int>> q;
    q.push({source, 0});
    source->setProcessing(true);

    unordered_set<string> visited;
    visited.insert(source->getInfo());

    while (!q.empty()) {
        auto current = q.front().first;

        if (q.front().second > maxdistance) {
            maxdistance = q.front().second;
            aux = {{source->getInfo(), current->getInfo()}};
        } else if (q.front().second == maxdistance) {
            aux.push_back({source->getInfo(), current->getInfo()});
        }

        for (const Edge& edge : current->getAdj()) {
            auto w = edge.getDest();
            if (visited.find(w->getInfo()) == visited.end()) {
                q.push({w, q.front().second + 1});
                w->setProcessing(true);

                // Adicionando vértice ao conjunto de visitados
                visited.insert(w->getInfo());
            }
        }

        q.pop();
        current->setVisited(true);
        current->setProcessing(false);
    }

    return maxdistance;
}

/**
 * @brief Get the top k airports with most traffic.
 *
 * @param k The number of airports to return.
 *
 * @return A vector containing the top k airports with most traffic.
 *
 * @complexity Time Complexity: O(V log V), where V is the number of vertices in the flights graph.
 */
void FlightManagementSystem::getTopAirportWithMostTraffic(int k) const {
    vector<Vertex*> res = flights.getVertexSet();
    sort(res.begin(), res.end(), [](Vertex* a, Vertex* b) {
        return (a->getIndegree() + a->getOutdegree()) > (b->getIndegree() + b->getOutdegree()); // ordem inversa
    });

    if (k <= 0 || k > flights.getVertexSet().size()) return;
    for (int i = 0; i < k; i++){
        cout << i+1 << " -> " << res[i]->getInfo() << " -- " << airports.find(res[i]->getInfo())->second.getName() << endl;
    }
}

/**
 * @brief Get the essential airports.
 *
 * @return A set containing the essential airports.
 *
 * @complexity Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the flights graph.
 */
unordered_set<string> FlightManagementSystem::getEssentialAirports() const {
    return flights.articulationPoints();
}

/**
 * @brief Finds the best flight option between two airports.
 *
 * @param source The code of the source airport.
 * @param destination The code of the destination airport.
 *
 * @return A vector containing the best flight option between the two airports.
 *
 * @complexity Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the flights graph.
 */
vector<Route> FlightManagementSystem::findBestFlightOption(const string &source, const string &destination) const {
    auto path = flights.shortestPathBFS(source, destination);
    vector<Route> res;
    for(int i = 0; i < path.size()-1; i++){
        Vertex* s = flights.findVertex(path[i]);
        vector<string> FlightAirlines;
        for(auto edge : s->getAdj()){
            if(edge.getDest()->getInfo() == path[i+1]){
                FlightAirlines.push_back(edge.getAirline());
            }
        }
        Route route = {path[i], path[i+1], FlightAirlines};
        res.push_back(route);
    }
    return res;
}
/**
 * @brief Finds the best flight option between two airports.
 *
 * @param source The name of the source airport.
 * @param destination The name of the destination airport.
 *
 * @return A vector containing the best flight option between the two airports.
 *
 * @complexity Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the flights graph.
 */
void FlightManagementSystem::findBestFlightOptionByAirportName(const string &source, const string &destination) const {
    string s,d;
    for(auto vertex : flights.getVertexSet()){
        if(airports.find(vertex->getInfo())->second.getName() == source){
            s = vertex->getInfo();
        }
        if(airports.find(vertex->getInfo())->second.getName() == destination){
            d = vertex->getInfo();
        }
    }
    for(const auto& flight : findBestFlightOption(s,d)){
        cout << flight.source << " -> " << flight.target << " (";
        for(int i = 0; i < flight.airlines.size(); i++){
            cout << flight.airlines[i];
            if(i != flight.airlines.size() - 1) {
                cout << ", ";
            }
        }
        cout << ")" << endl;
    }
}

/**
 * @brief Finds the best flight option between two cities.
 *
 * @param sourceCity The name of the source city.
 * @param sourceCountry The name of the source country.
 * @param destinationCity The name of the destination city.
 * @param destinationCountry The name of the destination country.
 *
 * @return A vector containing the best flight option between the two cities.
 *
 * @complexity Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the flights graph.
 */
void FlightManagementSystem::findBestFlightOptionByCity(const string &sourceCity, const string &sourceCountry, const string &destinationCity, const string &destinationCountry) const {
    vector<string> sourceCodes;
    vector<string> destinationCodes;
    for(auto vertex : flights.getVertexSet()){
        if(airports.find(vertex->getInfo())->second.getCity() == sourceCity && airports.find(vertex->getInfo())->second.getCountry() == sourceCountry){
            sourceCodes.push_back(vertex->getInfo());
        }
        if(airports.find(vertex->getInfo())->second.getCity() == destinationCity && airports.find(vertex->getInfo())->second.getCountry() == destinationCountry){
            destinationCodes.push_back(vertex->getInfo());
        }
    }
    int i = 0;
    int j = 0;
    while(i < sourceCodes.size()){

        cout << "Option " << i+1 << ": " << endl;
        for(const auto& flight : findBestFlightOption(sourceCodes[i], destinationCodes[j])){
            cout << flight.source << " -> " << flight.target << " (";
            for(int p = 0; p < flight.airlines.size(); p++){
                cout << flight.airlines[p];
                if(p != flight.airlines.size() - 1) {
                    cout << ", ";
                }
            }
            cout << ")" << endl;
        }
        cout << endl;
        i++;
        if(j < destinationCodes.size()-1)
        j++;
    }
}

/**
 * @brief Find the best flight options from the nearest airport (in terms of haversine distance) to the given coordinates to the specified destination.
 *
 * This function calculates the haversine distance from the given coordinates to each airport's coordinates in the system,
 * selects the nearest airport, and then finds the best flight options from that airport to the specified destination.
 *
 * @param latitude The latitude of the target coordinates.
 * @param longitude The longitude of the target coordinates.
 * @param destination The code of the destination airport.
 *
 * @note If the destination code is not valid, a message is printed, and the function returns without further processing.
 *
 * @complexity Time Complexity: O(V), where V is the number of vertices in the flights graph.
 */
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
    bool flag=false;
    if(airports.find(destination) == airports.end()){
        flag = true;
    }
    if (flag){
        cout << "No Code available" << endl;
        return;
    }
    int i = 1;
    for (const auto& airport : min){
        cout << "Option " << i << ": " << endl;
        for(const auto& flight : findBestFlightOption(airport,destination)){
            cout << flight.source << " -> " << flight.target << " (";
            for(int j = 0; j < flight.airlines.size(); j++){
                cout << flight.airlines[j];
                if(j != flight.airlines.size() - 1) {
                    cout << ", ";
                }
            }
            cout << ")" << endl;
        }
        cout << endl;
        i++;
    }

}

/**
 * @brief Find the best flight options from the source airport to the destination airport considering a given set of airlines.
 *
 * This function finds the best flight options from the source airport to the destination airport, considering only the
 * selected set of airlines. It uses breadth-first search to find the shortest path based on the specified airlines.
 *
 * @param source The code of the source airport.
 * @param destination The code of the destination airport.
 * @param selectedAirlines The vector of selected airline codes to consider in the search.
 *
 * @return A vector of Route objects representing the best flight options from the source to the destination.
 *
 * @complexity Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the flights graph.
 */
vector<Route> FlightManagementSystem::findBestFlightOptionWithGivenAirlines(const string &source, const string &destination,const vector<string> &selectedAirlines) const {
    auto path = flights.shortestPathBFS(source, destination,selectedAirlines);
    vector<Route> res;
    for(int i = 0; i < path.size()-1; i++){
        Vertex* s = flights.findVertex(path[i]);
        vector<string> FlightAirlines;
        for(auto edge : s->getAdj()){
            if(edge.getDest()->getInfo() == path[i+1]){
                FlightAirlines.push_back(edge.getAirline());
            }
        }
        Route route = {path[i], path[i+1], FlightAirlines};
        res.push_back(route);
    }
    return res;
}

