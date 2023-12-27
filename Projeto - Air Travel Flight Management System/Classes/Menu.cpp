

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
        cout << "| Q. Exit                                          |" << endl;
        drawBottom();
        cout << "Choose an option: ";
        cin >> key;
        switch (key) {
            case '1': {
                char key1;
                drawTop();
                cout << "| 1. Global number of airports                     |" << endl;
                cout << "| 2. Number of flights from airport                |" << endl;
                cout << "| 3. Number of airlines from airport               |" << endl;
                cout << "| 4. Number of countries from airport              |" << endl;
                cout << "| 5. Number of destinations from airport           |" << endl;
                cout << "| 6. Number of cities from airport                 |" << endl;
                cout << "| 7. Number of reachable destinations from airport |" << endl;
                cout << "| 8. Top airports with most traffic                 |" << endl;
                cout << "| 9. Essential airports                            |" << endl;
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
                        cout << "Number of flights from airport " << airport << ": "
                             << fms.getNumberOfFlightsFromAirport(airport) << endl;
                        break;
                    }

                    case '3': {
                        string airport;
                        cout << "Airport code: ";
                        cin >> airport;
                        cout << "Number of airlines from airport " << airport << ": "
                             << fms.getNumberOfAirlinesFromAirport(airport) << endl;
                        break;
                    }


                    case '4': {
                        string airport;
                        cout << "Airport code: ";
                        cin >> airport;
                        cout << "Number of countries from airport " << airport << ": "
                             << fms.getNumberOfCountriesFromAirport(airport) << endl;
                        break;
                    }

                    case '5': {
                        string airport;
                        cout << "Airport code: ";
                        cin >> airport;
                        cout << "Number of destinations from airport " << airport << ": "
                             << fms.getNumberOfDestinationsFromAirport(airport) << endl;
                        break;
                    }
                    case '6': {
                        string airport;
                        cout << "Airport code: ";
                        cin >> airport;
                        cout << "Number of cities from airport " << airport << ": "
                             << fms.getNumberOfCitiesFromAirport(airport) << endl;
                        break;
                    }
                    case '7': {
                        string airport;
                        int stops;
                        cout << "Airport code: ";
                        cin >> airport;
                        cout << "Number of reachable destinations from airport " << airport << ": "
                             << fms.getNumberOfReachableDestinationsFromAirport(airport, stops) << endl;
                        break;
                    }
                    case '8': {
                        int k;
                        cout << "Number of airports: ";
                        cin >> k;
                        fms.getTopAirportWithMostTraffic(k);
                        break;
                    }
                    case '9': {

                        cout << "Number of airports: ";
                        cout<< fms.getEssentialAirports().size();
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
                cout << "| 4.  Get number of countries from city            |" << endl;
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
                        string city;
                        cout << "City: ";
                        cin >> city;
                        cout << "Number of flights per city " << city << ": " << fms.getNumberOfFlightsPerCity(city)
                             << endl;
                        break;
                    }
                    case '3': {
                        string airline;
                        cout << "Airline: ";
                        cin >> airline;
                        cout << "Number of flights per airline " << airline << ": "
                             << fms.getNumberOfFlightsPerAirline(airline) << endl;
                        break;
                    }
                    case '4': {
                        string city;
                        cout << "City: ";
                        cin >> city;
                        cout << "Number of countries from city " << city << ": "
                             << fms.getNumberOfCountriesFromCity(city) << endl;
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
                cout << "| 1.  Find best flight option                      |" << endl;
                cout << "| 2.  Find best flight option by city              |" << endl;
                cout << "| 3.  Find best flight option by coordinates       |" << endl;
                cout << "| Q.  Exit                                         |" << endl;
                drawBottom();
                cout << "Choose an option: ";
                cin >> key5;
                switch (key5) {
                    case '1': {
                        char key6;
                        drawTop();
                        cout << "| 1.  Code                                         |" << endl;
                        cout << "| 2.  Airport Name                                 |" << endl;
                        cout << "| Q.  Exit                                         |" << endl;
                        drawBottom();
                        cout << "Choose an option: ";
                        cin >> key6;
                        switch(key6) {
                            case '1': {
                                string source, target;
                                cout << "Source airport code: ";
                                cin >> source;
                                cout << "Target airport code: ";
                                cin >> target;
                                for (const auto &flight: fms.findBestFlightOption(source, target)) {
                                    cout << flight.source << " -> " << flight.target << " (";
                                    for (int j = 0; j < flight.airlines.size(); j++) {
                                        cout << flight.airlines[j];
                                        if (j != flight.airlines.size() - 1) {
                                            cout << ", ";
                                        }
                                    }
                                    cout << ")" << endl;
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
                                fms.findBestFlightOptionByAirportName(source, target);
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
                        fms.findBestFlightOptionByCity(source, sourceCountry, target, targetCountry);
                        break;
                    }
                    case '3': {
                        double lat, lon;
                        string target;
                        cout << "Latitude: ";
                        cin >> lat;
                        cout << "Longitude: ";
                        cin >> lon;
                        cout << "Target airport code: ";
                        cin >> target;
                        fms.findBestFlightOptionByCoordinates(lat, lon, target);
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

