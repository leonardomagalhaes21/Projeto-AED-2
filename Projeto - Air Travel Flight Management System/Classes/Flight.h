//
// Created by tiago on 18-12-2023.
//

#ifndef PROJETO2_FLIGHT_H
#define PROJETO2_FLIGHT_H


#include <string>

class Flight {
public:
    Flight(const std::string& source, const std::string& target, const std::string& airline);

    // Métodos de acesso
    std::string getSource() const;
    std::string getTarget() const;
    std::string getAirline() const;

private:
    std::string source;
    std::string target;
    std::string airline;
};

#endif //PROJETO2_FLIGHT_H
