//
// Created by tiago on 18-12-2023.
//

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
    std::string code;
    std::string name;
    std::string callsign;
    std::string country;
};


#endif //PROJETO2_AIRLINE_H
