

#include "Menu.h"
#include "FlightManagementSystem.h"

using namespace std;

int main() {
    /*Data d = Data();
    FlightManagementSystem fms = FlightManagementSystem(d);
    vector<string> s;
    s.push_back("AFR");
    s.push_back("RYR");
    s.push_back("EIN");
    auto vec = fms.findBestFlightOptions("CDG", "CIY",s);
    for(int i = 0; i < vec.size(); i++){
        for(const auto& flight : vec[i]){
            fms.printRoute(flight);
        }
        if (i != vec.size() -1) {
            cout << endl << '\t' << '\t' << "Or..." << endl;
        }
    }

    cout << "--------------------'\n'";
    fms.findBestFlightOptionsByAirportName("Charles De Gaulle", "Comiso",s);
    cout << "--------------------'\n'";
    fms.findBestFlightOptionsByAirportCodeToCityName("CDG", "Comiso","Italy",s);
    cout << "--------------------'\n'";
    fms.findBestFlightOptionsByAirportNameToCityName("Charles De Gaulle", "Comiso","Italy",s);
    cout << "--------------------'\n'";
    fms.findBestFlightOptionsByAirportCodeToCoordinates("CDG", 37.000000,14.614400,s);
    cout << "--------------------'\n'";
    fms.findBestFlightOptionsByAirportNameToCoordinates("Charles De Gaulle", 37.000000,14.614400,s);
    cout << "--------------------'\n'";

    fms.findBestFlightOptionsByCityToAirportCode("Paris", "France", "CIY",s);
    cout << "--------------------'\n'";
    fms.findBestFlightOptionsByCityToAirportName("Paris", "France","Comiso",s);
    cout << "--------------------'\n'";
    fms.findBestFlightOptionsByCity("Paris", "France","Comiso", "Italy",s);
    cout << "--------------------'\n'";
    fms.findBestFlightOptionsByCityToCoordinates("Paris", "France", 37.000000, 14.614400,s);
    cout << "--------------------'\n'";

    fms.findBestFlightOptionsByCoordinates(49.012779, 2.550000, "CIY",s);
    cout << "--------------------'\n'";
    fms.findBestFlightOptionsByCoordinatesToAirportName(49.012779, 2.550000,"Comiso",s);
    cout << "--------------------'\n'";
    fms.findBestFlightOptionsByCoordinatesToCity(49.012779, 2.550000, "Comiso", "Italy",s);
    cout << "--------------------'\n'";
    fms.findBestFlightOptionsByCoordinatesToCoordinates(49.012779, 2.550000, 37.000000, 14.614400,s);*/

    cout << "Loading ..." << endl;
    Menu m = Menu();
    m.showMenu();
    cout << "\n";
    return 0;
}