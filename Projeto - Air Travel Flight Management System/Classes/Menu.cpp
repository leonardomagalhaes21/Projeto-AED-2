

#include "Menu.h"
#include "Data.h"
#include "FlightManagementSystem.h"
#include <iostream>

using namespace std;


/**
 * @brief Default constructor for the Menu class.
 *
 * @detail This constructor initializes an instance of the Menu class.
 *
 * Time Complexity: O(1)
 */
    Menu::Menu() {}

/**
 * @brief Draws the top section of the menu interface.
 *
 * @detail This function is responsible for rendering the top section of the menu interface.
 *
 * Time Complexity: O(1)
 */
    void Menu::drawTop(){
        cout << "____________________________________________________" << endl;
        cout << "|" << "====================== Menu ======================" << "|" << endl;
        cout << "|__________________________________________________|" << endl;
    }

/**
 * @brief Draws the bottom section of the menu interface.
 *
 * @detail This function is responsible for rendering the bottom section of the menu interface.
 *
 * Time Complexity: O(1)
 */
    void Menu::drawBottom(){
        cout << "|__________________________________________________|" << endl;
        cout << "|==================================================|" << endl;
        cout << "|__________________________________________________|" << endl;
    }

/**
 * @brief Display the main menu and handle user interactions.
 *
 * @info This method initializes a FlightManagementSystem and Data objects, then displays a menu with different options.
 * The user can choose options related to airports, statistics, or finding the best flight options.
 *
 * @complexity Time complexity: depends on the option chosen by the user.
 */
void Menu::showMenu() {
    Data d = Data();
    FlightManagementSystem fms = FlightManagementSystem(d);

    char key;
    bool flag = true;
    while (flag) {
        drawTop();
        cout << "| 1. Get from airports                             |" << endl;
        cout << "| 2. Statistics                                    |" << endl;
        cout << "| 3. Best flight option                            |" << endl;
        cout << "| 4. Personalized preferences                      |" << endl;
        cout << "| Q. Exit                                          |" << endl;
        drawBottom();
        cout << "Choose an option: ";
        cin >> key;
        switch (key) {
            case '1': {
                char key1;
                drawTop();
                cout << "| 1. Global number of airports                     |" << endl;
                cout << "| 2. Number of flights/airlines out of airport     |" << endl;
                cout << "| 3. Number of countries flown from airport        |" << endl;
                cout << "| 4. Number of reachable destinations from airport |" << endl;
                cout << "| 5. Number of destinations from airport with stops|" << endl;
                cout << "| 6. Top airports with most traffic                |" << endl;
                cout << "| 7. Essential airports                            |" << endl;
                cout << "| Q. Exit                                          |" << endl;
                drawBottom();
                cout << "Choose an option: ";
                cin >> key1;
                switch (key1) {
                    case '1': {
                        cout << "Global number of airports: " << fms.getGlobalNumberOfAirports() << endl;
                        break;
                    }
                    case '2': {
                        string airport;
                        cout << "Airport code: ";
                        cin >> airport;
                        cout << "Number of flights out of " << airport << ": "
                             << fms.getNumberOfFlightsFromAirport(airport) << endl;
                        cout << "Number of airlines out of " << airport << ": "
                             << fms.getNumberOfAirlinesFromAirport(airport) << endl;
                        break;
                    }

                    case '3': {
                        string airport;
                        cout << "Airport code: ";
                        cin >> airport;
                        cout << "Number of countries flown from " << airport << ": "
                             << fms.getNumberOfCountriesFromAirport(airport) << endl;
                        break;
                    }

                    case '4': {
                        string airport;
                        cout << "Airport code: ";
                        cin >> airport;
                        fms.numberOfReachableDestinationsFromAirport(airport);
                        break;
                    }

                    case '5': {
                        string airport;
                        int stops;
                        cout << "Airport code: ";
                        cin >> airport;
                        cout << "Max stops: ";
                        cin >> stops;
                        fms.numberOfReachableDestinationsFromAirportWithStops(airport, stops);
                        break;
                    }
                    case '6': {
                        int k;
                        cout << "Number of airports: ";
                        cin >> k;
                        fms.getTopAirportWithMostTraffic(k);
                        break;
                    }
                    case '7': {
                        cout << "Number of airports: ";
                        auto essential = fms.getEssentialAirports();
                        cout<< essential.size() << endl;
                        for (const auto& airport : essential){
                            cout << airport << " (" << d.getAirports().find(airport)->second.getName() << ")" <<endl;
                        }
                        break;
                    }
                    case 'Q' : {
                        break;
                    }
                    default: {
                        cout << endl << "Invalid option!" << endl;
                    }
                };
                break;

            }
            case '2': {
                char key2;
                drawTop();
                cout << "| 1.  Get global number of flights                 |" << endl;
                cout << "| 2.  Get number of flights per city               |" << endl;
                cout << "| 3.  Get number of flights per airline            |" << endl;
                cout << "| 4.  Get number of countries flown from city      |" << endl;
                cout << "| 5.  Get max trip with stops                      |" << endl;
                cout << "| Q.  Exit                                         |" << endl;
                drawBottom();
                cout << "Choose an option: ";
                cin >> key2;
                switch (key2) {
                    case '1': {
                        cout << "Global number of flights: " << fms.getGlobalNumberOfFlights() << endl;
                        break;
                    }
                    case '2': {
                        fms.numberOfFlightsPerCity();
                        break;
                    }
                    case '3': {
                        fms.numberOfFlightsPerAirline();
                        break;
                    }
                    case '4': {
                        string city, country;
                        cout << "City: ";
                        cin.ignore();
                        getline(cin, city);
                        cout << "Country: ";
                        getline(cin, country);
                        cout << "Number of countries flown from " << city << " (" << country << "): "
                             << fms.getNumberOfCountriesFromCity(city, country) << endl;
                        break;
                    }

                    case '5': {
                        cout << "Loading... (This is going to take 20-25 seconds)" << endl;
                        fms.getMaxTripWithStops();
                        break;
                    }
                    case 'Q' : {
                        break;
                    }
                    default: {
                        cout << endl << "Invalid option!" << endl;
                    }
                };
                break;

            }

            case '3': {
                char key5;
                drawTop();
                cout << "| 1.  Find best flight option from airport         |" << endl;
                cout << "| 2.  Find best flight option from city            |" << endl;
                cout << "| 3.  Find best flight option from coordinates     |" << endl;
                cout << "| Q.  Exit                                         |" << endl;
                drawBottom();
                cout << "Choose an option: ";
                cin >> key5;
                switch (key5) {
                    case '1': {
                        char key6;
                        drawTop();
                        cout << "| 1.  To airport                                   |" << endl;
                        cout << "| 2.  To city                                      |" << endl;
                        cout << "| 3.  To coordinates                               |" << endl;
                        cout << "| Q.  Exit                                         |" << endl;
                        drawBottom();
                        cout << "Choose an option: ";
                        cin >> key6;
                        switch(key6){
                            case '1': {
                                char key7;
                                drawTop();
                                cout << "| 1.  Code                                         |" << endl;
                                cout << "| 2.  Airport Name                                 |" << endl;
                                cout << "| Q.  Exit                                         |" << endl;
                                drawBottom();
                                cout << "Choose an option: ";
                                cin >> key7;
                                switch(key7) {
                                    case '1': {
                                        string source, target;
                                        cout << "Source airport code: ";
                                        cin >> source;
                                        cout << "Target airport code: ";
                                        cin >> target;
                                        auto vec = fms.findBestFlightOptions(source, target);
                                        for(int i = 0; i < vec.size(); i++){
                                            for(const auto& flight : vec[i]){
                                                fms.printRoute(flight);
                                            }
                                            if (i != vec.size() -1) {
                                                cout << endl << '\t' << '\t' << "Or..." << endl;
                                            }
                                        }
                                        break;
                                    }
                                    case '2': {
                                        string source, target;
                                        cout << "Source airport name: ";
                                        cin.ignore();
                                        getline(cin, source);
                                        cout << "Target airport name: ";
                                        getline(cin, target);
                                        fms.findBestFlightOptionsByAirportName(source, target);
                                        break;
                                    }
                                    case 'Q' : {
                                        break;
                                    }
                                    default: {
                                        cout << endl << "Invalid option!" << endl;
                                    }
                                };
                                break;
                            }
                            case '2': {
                                char key13;
                                drawTop();
                                cout << "| 1.  Code                                         |" << endl;
                                cout << "| 2.  Airport Name                                 |" << endl;
                                cout << "| Q.  Exit                                         |" << endl;
                                drawBottom();
                                cout << "Choose an option: ";
                                cin >> key13;
                                switch(key13) {
                                    case '1': {
                                        string source, target, country;
                                        cout << "Source airport code: ";
                                        cin >> source;
                                        cout << "Target city name: ";
                                        cin.ignore();
                                        getline(cin, target);
                                        cout << "Target country name: ";
                                        getline(cin, country);
                                        fms.findBestFlightOptionsByAirportCodeToCityName(source, target, country);
                                        break;
                                    }
                                    case '2': {
                                        string source, target, country;
                                        cout << "Source airport name: ";
                                        cin.ignore();
                                        getline(cin, source);
                                        cout << "Target city name: ";
                                        getline(cin, target);
                                        cout << "Target country name: ";
                                        getline(cin, country);
                                        fms.findBestFlightOptionsByAirportNameToCityName(source, target, country);
                                        break;
                                    }
                                    case 'Q' : {
                                        break;
                                    }
                                    default: {
                                        cout << endl << "Invalid option!" << endl;
                                    }
                                };
                                break;
                            }
                            case '3': {
                                char key14;
                                drawTop();
                                cout << "| 1.  Code                                         |" << endl;
                                cout << "| 2.  Airport Name                                 |" << endl;
                                cout << "| Q.  Exit                                         |" << endl;
                                drawBottom();
                                cout << "Choose an option: ";
                                cin >> key14;
                                switch(key14) {
                                    case '1': {
                                        string source, target;
                                        cout << "Source airport code: ";
                                        cin >> source;
                                        double lat, lon;
                                        cout << "Latitude: ";
                                        cin >> lat;
                                        cout << "Longitude: ";
                                        cin >> lon;
                                        fms.findBestFlightOptionsByAirportCodeToCoordinates(source, lat, lon);
                                        break;
                                    }
                                    case '2': {
                                        string source, target;
                                        cout << "Source airport name: ";
                                        cin >> source;
                                        double lat, lon;
                                        cout << "Latitude: ";
                                        cin >> lat;
                                        cout << "Longitude: ";
                                        cin >> lon;
                                        fms.findBestFlightOptionsByAirportNameToCoordinates(source, lat, lon);
                                        break;
                                    }
                                    case 'Q' : {
                                        break;
                                    }
                                    default: {
                                        cout << endl << "Invalid option!" << endl;
                                    }
                                };
                                break;
                            }
                            case 'Q' : {
                                break;
                            }
                            default: {
                                cout << endl << "Invalid option!" << endl;
                            }
                        };
                        break;
                    }
                    case '2': {
                        char key8;
                        drawTop();
                        cout << "| 1.  To airport                                   |" << endl;
                        cout << "| 2.  To city                                      |" << endl;
                        cout << "| 3.  To coordinates                               |" << endl;
                        cout << "| Q.  Exit                                         |" << endl;
                        drawBottom();
                        cout << "Choose an option: ";
                        cin >> key8;
                        switch(key8){
                            case '1': {
                                char key9;
                                drawTop();
                                cout << "| 1.  Code                                         |" << endl;
                                cout << "| 2.  Airport Name                                 |" << endl;
                                cout << "| Q.  Exit                                         |" << endl;
                                drawBottom();
                                cout << "Choose an option: ";
                                cin >> key9;
                                switch(key9) {
                                    case '1': {
                                        string source, sourceCountry, target;
                                        cout << "Source city: ";
                                        cin.ignore();
                                        getline(cin, source);
                                        cout << "Source country: ";
                                        getline(cin, sourceCountry);
                                        cout << "Target airport code: ";
                                        cin >> target;
                                        fms.findBestFlightOptionsByCityToAirportCode(source, sourceCountry, target);
                                        break;
                                    }
                                    case '2': {
                                        string source, sourceCountry, target;
                                        cout << "Source city: ";
                                        cin.ignore();
                                        getline(cin, source);
                                        cout << "Source country: ";
                                        getline(cin, sourceCountry);
                                        cout << "Target airport name: ";
                                        getline(cin, target);
                                        fms.findBestFlightOptionsByCityToAirportName(source, sourceCountry, target);
                                        break;
                                    }
                                    case 'Q' : {
                                        break;
                                    }
                                    default: {
                                        cout << endl << "Invalid option!" << endl;
                                    }
                                };
                                break;
                            }
                            case '2': {
                                string source, sourceCountry, target, targetCountry;
                                cout << "Source city: ";
                                cin.ignore();
                                getline(cin, source);
                                cout << "Source country: ";
                                getline(cin, sourceCountry);
                                cout << "Target city: ";
                                getline(cin, target);
                                cout << "Target country: ";
                                getline(cin, targetCountry);
                                fms.findBestFlightOptionsByCity(source, sourceCountry, target, targetCountry);
                                break;
                            }
                            case '3': {
                                double lat, lon;
                                string source, sourceCountry;
                                cout << "Source city: ";
                                cin.ignore();
                                getline(cin, source);
                                cout << "Source country: ";
                                getline(cin, sourceCountry);
                                cout << "Latitude: ";
                                cin >> lat;
                                cout << "Longitude: ";
                                cin >> lon;
                                fms.findBestFlightOptionsByCityToCoordinates(source, sourceCountry, lat, lon);
                                break;
                            }
                            case 'Q' : {
                                break;
                            }
                            default: {
                                cout << endl << "Invalid option!" << endl;
                            }
                        };
                        break;
                    }
                    case '3': {
                        char key10;
                        drawTop();
                        cout << "| 1.  To airport                                   |" << endl;
                        cout << "| 2.  To city                                      |" << endl;
                        cout << "| 3.  To coordinates                               |" << endl;
                        cout << "| Q.  Exit                                         |" << endl;
                        drawBottom();
                        cout << "Choose an option: ";
                        cin >> key10;
                        switch(key10){
                            case '1': {
                                char key11;
                                drawTop();
                                cout << "| 1.  Code                                         |" << endl;
                                cout << "| 2.  Airport Name                                 |" << endl;
                                cout << "| Q.  Exit                                         |" << endl;
                                drawBottom();
                                cout << "Choose an option: ";
                                cin >> key11;
                                switch(key11) {
                                    case '1': {
                                        double lat, lon;
                                        string target;
                                        cout << "Latitude: ";
                                        cin >> lat;
                                        cout << "Longitude: ";
                                        cin >> lon;
                                        cout << "Target airport code: ";
                                        cin >> target;
                                        fms.findBestFlightOptionsByCoordinates(lat, lon, target);
                                        break;
                                    }
                                    case '2': {
                                        double lat, lon;
                                        string target;
                                        cout << "Latitude: ";
                                        cin >> lat;
                                        cout << "Longitude: ";
                                        cin >> lon;
                                        cout << "Target airport name: ";
                                        cin.ignore();
                                        getline(cin, target);
                                        fms.findBestFlightOptionsByCoordinatesToAirportName(lat, lon, target);
                                        break;
                                    }
                                    case 'Q' : {
                                        break;
                                    }
                                    default: {
                                        cout << endl << "Invalid option!" << endl;
                                    }
                                };
                                break;
                            }
                            case '2': {
                                double lat, lon;
                                string target, targetCountry;
                                cout << "Latitude: ";
                                cin >> lat;
                                cout << "Longitude: ";
                                cin >> lon;
                                cout << "Target city: ";
                                cin.ignore();
                                getline(cin, target);
                                cout << "Target country: ";
                                getline(cin, targetCountry);
                                fms.findBestFlightOptionsByCoordinatesToCity(lat, lon, target, targetCountry);
                                break;
                            }
                            case '3': {
                                double lat1, lon1, lat2, lon2;
                                cout << "Source latitude: ";
                                cin >> lat1;
                                cout << "Source longitude: ";
                                cin >> lon1;
                                cout << "Target latitude: ";
                                cin >> lat2;
                                cout << "Target longitude: ";
                                cin >> lon2;
                                fms.findBestFlightOptionsByCoordinatesToCoordinates(lat1, lon1, lat2, lon2);
                                break;
                            }
                            case 'Q' : {
                                break;
                            }
                            default: {
                                cout << endl << "Invalid option!" << endl;
                            }
                        };

                        break;
                    }
                    case 'Q' : {
                        break;
                    }
                    default: {
                        cout << endl << "Invalid option!" << endl;
                    }
                };
                break;

            }
            case '4' : {
                char key12;
                drawTop();
                cout << "| 1.  Best flight option with selected airlines    |" << endl;
                cout << "| Q.  Exit                                         |" << endl;
                drawBottom();
                cout << "Choose an option: ";
                cin >> key12;
                switch(key12){
                    case '1': {
                        char key14;
                        drawTop();
                        cout << "| 1.  Find best flight option from airport         |" << endl;
                        cout << "| 2.  Find best flight option from city            |" << endl;
                        cout << "| 3.  Find best flight option from coordinates     |" << endl;
                        cout << "| Q.  Exit                                         |" << endl;
                        drawBottom();
                        cout << "Choose an option: ";
                        cin >> key14;
                        switch(key14){
                            case '1' : {
                                char key15;
                                drawTop();
                                cout << "| 1.  To airport                                   |" << endl;
                                cout << "| 2.  To city                                      |" << endl;
                                cout << "| 3.  To coordinates                               |" << endl;
                                cout << "| Q.  Exit                                         |" << endl;
                                drawBottom();
                                cout << "Choose an option: ";
                                cin >> key15;
                                switch(key15){
                                    case '1' : {
                                        char key16;
                                        drawTop();
                                        cout << "| 1.  Code                                         |" << endl;
                                        cout << "| 2.  Airport Name                                 |" << endl;
                                        cout << "| Q.  Exit                                         |" << endl;
                                        drawBottom();
                                        cout << "Choose an option: ";
                                        cin >> key16;
                                        switch(key16){
                                            case '1' : {
                                                string source, target;
                                                cout << "Source airport code: ";
                                                cin >> source;
                                                cout << "Target airport code: ";
                                                cin >> target;

                                                vector<string> airlines;
                                                string airline;
                                                char key17 = 'Y';

                                                while (key17 == 'Y') {
                                                    cout << "Enter airline code: ";
                                                    cin >> airline;
                                                    airlines.push_back(airline);

                                                    cout << "Add more? (Y/N): ";
                                                    cin >> key17;
                                                }
                                                cin.ignore();
                                                cout << endl;


                                                auto vec = fms.findBestFlightOptions(source, target, airlines);
                                                for(int i = 0; i < vec.size(); i++){
                                                    for(const auto& flight : vec[i]){
                                                        fms.printRoute(flight);
                                                    }
                                                    if (i != vec.size() -1) {
                                                        cout << endl << '\t' << '\t' << "Or..." << endl;
                                                    }
                                                }
                                                break;
                                            }
                                            case '2' : {
                                                string source, target;
                                                cout << "Source airport name: ";
                                                cin.ignore();
                                                getline(cin, source);
                                                cout << "Target airport name: ";
                                                getline(cin, target);

                                                vector<string> airlines;
                                                string airline;
                                                char key17 = 'Y';

                                                while (key17 == 'Y') {
                                                    cout << "Enter airline code: ";
                                                    cin >> airline;
                                                    airlines.push_back(airline);

                                                    cout << "Add more? (Y/N): ";
                                                    cin >> key17;
                                                }
                                                cin.ignore();
                                                cout << endl;

                                                fms.findBestFlightOptionsByAirportName(source, target, airlines);
                                                break;
                                            }
                                            case 'Q' : {
                                                break;
                                            }
                                            default: {
                                                cout << endl << "Invalid option!" << endl;
                                            }
                                        };
                                        break;
                                    }
                                    case '2' : {
                                        char key18;
                                        drawTop();
                                        cout << "| 1.  Code                                         |" << endl;
                                        cout << "| 2.  Airport Name                                 |" << endl;
                                        cout << "| Q.  Exit                                         |" << endl;
                                        drawBottom();
                                        cout << "Choose an option: ";
                                        cin >> key18;
                                        switch(key18){
                                            case '1' : {
                                                string source, targetCountry, target;
                                                cout << "Source airport code: ";
                                                cin >> source;
                                                cout << "Target city name: ";
                                                cin.ignore();
                                                getline(cin, target);
                                                cout << "Target country name: ";
                                                getline(cin, targetCountry);


                                                vector<string> airlines;
                                                string airline;
                                                char key19 = 'Y';

                                                while (key19 == 'Y') {
                                                    cout << "Enter airline code: ";
                                                    cin >> airline;
                                                    airlines.push_back(airline);

                                                    cout << "Add more? (Y/N): ";
                                                    cin >> key19;
                                                }
                                                cin.ignore();
                                                cout << endl;

                                                fms.findBestFlightOptionsByAirportCodeToCityName(source, target, targetCountry, airlines);
                                                break;
                                            }
                                            case '2' : {
                                                string source, targetCountry, target;
                                                cout << "Source airport name: ";
                                                cin >> source;
                                                cout << "Target city name: ";
                                                cin.ignore();
                                                getline(cin, target);
                                                cout << "Target country name: ";
                                                getline(cin, targetCountry);


                                                vector<string> airlines;
                                                string airline;
                                                char key20 = 'Y';

                                                while (key20 == 'Y') {
                                                    cout << "Enter airline code: ";
                                                    cin >> airline;
                                                    airlines.push_back(airline);

                                                    cout << "Add more? (Y/N): ";
                                                    cin >> key20;
                                                }
                                                cin.ignore();
                                                cout << endl;

                                                fms.findBestFlightOptionsByAirportNameToCityName(source, target, targetCountry, airlines);
                                                break;
                                            }
                                            case 'Q' : {
                                                break;
                                            }
                                            default: {
                                                cout << endl << "Invalid option!" << endl;
                                            }
                                        };
                                        break;
                                    }
                                    case '3' : {
                                        char key21;
                                        drawTop();
                                        cout << "| 1.  Code                                         |" << endl;
                                        cout << "| 2.  Airport Name                                 |" << endl;
                                        cout << "| Q.  Exit                                         |" << endl;
                                        drawBottom();
                                        cout << "Choose an option: ";
                                        cin >> key21;
                                        switch (key21) {
                                            case '1' : {
                                                string source, target;
                                                cout << "Source airport code: ";
                                                cin >> source;
                                                double lat, lon;
                                                cout << "Latitude: ";
                                                cin >> lat;
                                                cout << "Longitude: ";
                                                cin >> lon;
                                                vector<string> airlines;
                                                string airline;
                                                char key22 = 'Y';

                                                while (key22 == 'Y') {
                                                    cout << "Enter airline code: ";
                                                    cin >> airline;
                                                    airlines.push_back(airline);

                                                    cout << "Add more? (Y/N): ";
                                                    cin >> key22;
                                                }
                                                cin.ignore();
                                                cout << endl;

                                                fms.findBestFlightOptionsByAirportCodeToCoordinates(source, lat, lon,
                                                                                                    airlines);
                                                break;
                                            }
                                            case '2' : {
                                                string source, target;
                                                cout << "Source airport name: ";
                                                cin.ignore();
                                                getline(cin, source);
                                                double lat, lon;
                                                cout << "Latitude: ";
                                                cin >> lat;
                                                cout << "Longitude: ";
                                                cin >> lon;
                                                vector<string> airlines;
                                                string airline;
                                                char key23 = 'Y';

                                                while (key23 == 'Y') {
                                                    cout << "Enter airline code: ";
                                                    cin >> airline;
                                                    airlines.push_back(airline);

                                                    cout << "Add more? (Y/N): ";
                                                    cin >> key23;
                                                }
                                                cin.ignore();
                                                cout << endl;

                                                fms.findBestFlightOptionsByAirportNameToCoordinates(source, lat, lon,
                                                                                                    airlines);
                                                break;
                                            }
                                            case 'Q' : {
                                                break;
                                            }
                                            default: {
                                                cout << endl << "Invalid option!" << endl;
                                            }
                                        };
                                        break;
                                    }
                                    case 'Q' : {
                                        break;
                                    }
                                    default: {
                                        cout << endl << "Invalid option!" << endl;
                                    }
                                }
                                break;
                            }
                            case '2' : {
                                char key24;
                                drawTop();
                                cout << "| 1.  To airport                                   |" << endl;
                                cout << "| 2.  To city                                      |" << endl;
                                cout << "| 3.  To coordinates                               |" << endl;
                                cout << "| Q.  Exit                                         |" << endl;
                                drawBottom();
                                cout << "Choose an option: ";
                                cin >> key24;
                                switch(key24) {
                                    case '1' : {
                                        char key25;
                                        drawTop();
                                        cout << "| 1.  Code                                         |" << endl;
                                        cout << "| 2.  Airport Name                                 |" << endl;
                                        cout << "| Q.  Exit                                         |" << endl;
                                        drawBottom();
                                        cout << "Choose an option: ";
                                        cin >> key25;
                                        switch (key25) {
                                            case '1' : {
                                                string source, sourceCountry, target;
                                                cout << "Source city: ";
                                                cin.ignore();
                                                getline(cin, source);
                                                cout << "Source country: ";
                                                getline(cin, sourceCountry);
                                                cout << "Target airport code: ";
                                                cin >> target;

                                                vector<string> airlines;
                                                string airline;
                                                char key26 = 'Y';

                                                while (key26 == 'Y') {
                                                    cout << "Enter airline code: ";
                                                    cin >> airline;
                                                    airlines.push_back(airline);

                                                    cout << "Add more? (Y/N): ";
                                                    cin >> key26;
                                                }
                                                cin.ignore();
                                                cout << endl;

                                                fms.findBestFlightOptionsByCityToAirportCode(source, sourceCountry,target, airlines);
                                                break;
                                            }
                                            case '2' : {
                                                string source, sourceCountry, target;
                                                cout << "Source city: ";
                                                cin.ignore();
                                                getline(cin, source);
                                                cout << "Source country: ";
                                                getline(cin, sourceCountry);
                                                cout << "Target airport name: ";
                                                getline(cin, target);

                                                vector<string> airlines;
                                                string airline;
                                                char key27 = 'Y';

                                                while (key27 == 'Y') {
                                                    cout << "Enter airline code: ";
                                                    cin >> airline;
                                                    airlines.push_back(airline);

                                                    cout << "Add more? (Y/N): ";
                                                    cin >> key27;
                                                }
                                                cin.ignore();
                                                cout << endl;

                                                fms.findBestFlightOptionsByCityToAirportName(source, sourceCountry,target, airlines);
                                                break;
                                            }
                                            case 'Q' : {
                                                break;
                                            }
                                            default: {
                                                cout << endl << "Invalid option!" << endl;
                                            }
                                        };
                                        break;
                                    }
                                    case '2' : {
                                        string source, sourceCountry, target, targetCountry;
                                        cout << "Source city: ";
                                        cin.ignore();
                                        getline(cin, source);
                                        cout << "Source country: ";
                                        getline(cin, sourceCountry);
                                        cout << "Target city: ";
                                        getline(cin, target);
                                        cout << "Target country: ";
                                        getline(cin, targetCountry);

                                        vector<string> airlines;
                                        string airline;
                                        char key28 = 'Y';

                                        while (key28 == 'Y') {
                                            cout << "Enter airline code: ";
                                            cin >> airline;
                                            airlines.push_back(airline);

                                            cout << "Add more? (Y/N): ";
                                            cin >> key28;
                                        }
                                        cin.ignore();
                                        cout << endl;

                                        fms.findBestFlightOptionsByCity(source, sourceCountry, target, targetCountry, airlines);
                                        break;
                                    }
                                    case '3' : {
                                        double lat, lon;
                                        string source, sourceCountry;
                                        cout << "Source city: ";
                                        cin.ignore();
                                        getline(cin, source);
                                        cout << "Source country: ";
                                        getline(cin, sourceCountry);
                                        cout << "Latitude: ";
                                        cin >> lat;
                                        cout << "Longitude: ";
                                        cin >> lon;

                                        vector<string> airlines;
                                        string airline;
                                        char key29 = 'Y';

                                        while (key29 == 'Y') {
                                            cout << "Enter airline code: ";
                                            cin >> airline;
                                            airlines.push_back(airline);

                                            cout << "Add more? (Y/N): ";
                                            cin >> key29;
                                        }
                                        cin.ignore();
                                        cout << endl;

                                        fms.findBestFlightOptionsByCityToCoordinates(source, sourceCountry, lat, lon, airlines);
                                        break;
                                    }
                                    case 'Q' : {
                                        break;
                                    }
                                    default: {
                                        cout << endl << "Invalid option!" << endl;
                                    }
                                };
                                break;
                            }
                            case '3' : {
                                char key30;
                                drawTop();
                                cout << "| 1.  To airport                                   |" << endl;
                                cout << "| 2.  To city                                      |" << endl;
                                cout << "| 3.  To coordinates                               |" << endl;
                                cout << "| Q.  Exit                                         |" << endl;
                                drawBottom();
                                cout << "Choose an option: ";
                                cin >> key30;
                                switch(key30) {
                                    case '1' : {
                                        char key31;
                                        drawTop();
                                        cout << "| 1.  Code                                         |" << endl;
                                        cout << "| 2.  Airport Name                                 |" << endl;
                                        cout << "| Q.  Exit                                         |" << endl;
                                        drawBottom();
                                        cout << "Choose an option: ";
                                        cin >> key31;
                                        switch (key31) {
                                            case '1' : {
                                                double lat, lon;
                                                string target;
                                                cout << "Latitude: ";
                                                cin >> lat;
                                                cout << "Longitude: ";
                                                cin >> lon;
                                                cout << "Target airport code: ";
                                                cin >> target;

                                                vector<string> airlines;
                                                string airline;
                                                char key32 = 'Y';

                                                while (key32 == 'Y') {
                                                    cout << "Enter airline code: ";
                                                    cin >> airline;
                                                    airlines.push_back(airline);

                                                    cout << "Add more? (Y/N): ";
                                                    cin >> key32;
                                                }
                                                cin.ignore();
                                                cout << endl;

                                                fms.findBestFlightOptionsByCoordinates(lat, lon, target, airlines);
                                                break;
                                            }
                                            case '2' : {
                                                double lat, lon;
                                                string target;
                                                cout << "Latitude: ";
                                                cin >> lat;
                                                cout << "Longitude: ";
                                                cin >> lon;
                                                cout << "Target airport name: ";
                                                cin.ignore();
                                                getline(cin, target);

                                                vector<string> airlines;
                                                string airline;
                                                char key33 = 'Y';

                                                while (key33 == 'Y') {
                                                    cout << "Enter airline code: ";
                                                    cin >> airline;
                                                    airlines.push_back(airline);

                                                    cout << "Add more? (Y/N): ";
                                                    cin >> key33;
                                                }
                                                cin.ignore();
                                                cout << endl;

                                                fms.findBestFlightOptionsByCoordinatesToAirportName(lat, lon, target,airlines);
                                                break;
                                            }
                                            case 'Q' : {
                                                break;
                                            }
                                            default: {
                                                cout << endl << "Invalid option!" << endl;
                                            }
                                        };
                                        break;
                                    }
                                    case '2' : {
                                        double lat, lon;
                                        string target, targetCountry;
                                        cout << "Latitude: ";
                                        cin >> lat;
                                        cout << "Longitude: ";
                                        cin >> lon;
                                        cout << "Target city: ";
                                        cin.ignore();
                                        getline(cin, target);
                                        cout << "Target country: ";
                                        getline(cin, targetCountry);

                                        vector<string> airlines;
                                        string airline;
                                        char key34 = 'Y';

                                        while (key34 == 'Y') {
                                            cout << "Enter airline code: ";
                                            cin >> airline;
                                            airlines.push_back(airline);

                                            cout << "Add more? (Y/N): ";
                                            cin >> key34;
                                        }
                                        cin.ignore();
                                        cout << endl;

                                        fms.findBestFlightOptionsByCoordinatesToCity(lat, lon, target, targetCountry, airlines);
                                        break;
                                    }
                                    case '3' : {
                                        double lat1, lon1, lat2, lon2;
                                        cout << "Source latitude: ";
                                        cin >> lat1;
                                        cout << "Source longitude: ";
                                        cin >> lon1;
                                        cout << "Target latitude: ";
                                        cin >> lat2;
                                        cout << "Target longitude: ";
                                        cin >> lon2;

                                        vector<string> airlines;
                                        string airline;
                                        char key35 = 'Y';

                                        while (key35 == 'Y') {
                                            cout << "Enter airline code: ";
                                            cin >> airline;
                                            airlines.push_back(airline);

                                            cout << "Add more? (Y/N): ";
                                            cin >> key35;
                                        }
                                        cin.ignore();
                                        cout << endl;

                                        fms.findBestFlightOptionsByCoordinatesToCoordinates(lat1, lon1, lat2, lon2, airlines);
                                        break;
                                    }
                                    case 'Q' : {
                                        break;
                                    }
                                    default: {
                                        cout << endl << "Invalid option!" << endl;
                                    }
                                };
                                break;
                            }
                            case 'Q' : {
                                break;
                            }
                            default: {
                                cout << endl << "Invalid option!" << endl;
                            }
                        };
                        break;
                    }
                    case 'Q' : {
                        break;
                    }
                    default: {
                        cout << endl << "Invalid option!" << endl;
                    }
                };
                break;
            }
            case 'Q' : {
                flag = false;
                break;
            }
            default: {
                cout << endl << "Invalid option!" << endl;
            }

        };

        cout << endl;
        cout << "Would you like to do something else? (Y/N) \n";
        char newCicle;
        cin >> newCicle;
        if (newCicle == 'N') flag = false;
        while (newCicle != 'Y') {
            if (newCicle == 'N') {
                flag = false;
                break;
            }
            cout << "Please type \"Y\" or \"N\"." << endl;
            cin >> newCicle;
        }
    }
}

