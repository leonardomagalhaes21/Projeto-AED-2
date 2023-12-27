

#ifndef PROJETO2_AIRLINE_H
#define PROJETO2_AIRLINE_H


#include <string>

class Airline {
public:
    Airline(const std::string& code, const std::string& name, const std::string& callsign, const std::string& country);

    // Métodos de acesso
    std::string getCode() const;
    std::string getName() const;
    std::string getCallsign() const;
    std::string getCountry() const;

private:
    std::string code;       ///< The code of the airline.
    std::string name;       ///< The name of the airline.
    std::string callsign;   ///< The callsign of the airline.
    std::string country;    ///< The country of the airline.
};


#endif //PROJETO2_AIRLINE_H
