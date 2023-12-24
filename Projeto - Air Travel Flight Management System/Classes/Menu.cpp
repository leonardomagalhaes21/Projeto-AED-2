//
// Created by tiago on 18-12-2023.
//

#include "Menu.h"
#include "Data.h"
#include "FlightManagementSystem.h"
#include <iostream>

using namespace std;

int main(){
    cout << "Loading ..." << endl;
    Data d = Data();
    FlightManagementSystem fms = FlightManagementSystem(d);
    auto b = d.getFlightsGraph().findVertex("OPO");
    for (auto a : b->getAdj()) {
        cout << a.getDest()->getInfo() <<" -- " << d.getAirlines().find(a.getAirline())->second.getName()  << " -- " <<  d.getAirports().find(a.getDest()->getInfo())->second.getName() << endl;
    }

    cout << fms.getGlobalNumberOfAirports() << endl;
    cout << fms.getGlobalNumberOfFlights() << endl;
    cout << fms.getNumberOfFlightsFromAirport("OPO") << endl;
    cout << fms.getNumberOfAirlinesFromAirport("OPO") << endl;
    cout << fms.getNumberOfFlightsPerCity("Miami") << endl;
    cout << fms.getNumberOfFlightsPerAirline("TAP") << endl;
    cout << fms.getNumberOfCountriesFromAirport("OPO") << endl;
    cout << fms.getNumberOfCountriesFromCity("Miami") << endl;
    cout << fms.getNumberOfDestinationsFromAirport("OPO") << endl;
    cout << fms.getNumberOfCitiesFromAirport("OPO") << endl;
    cout << fms.getNumberOfReachableDestinationsFromAirport("OPO", 2) << endl;

    return 0;
}
