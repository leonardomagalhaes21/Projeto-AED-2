//
// Created by tiago on 18-12-2023.
//

#include "Menu.h"
#include "Data.h"
#include <iostream>

int main(){
    cout << "Loading ..." << endl;
    Data d = Data();
    for (auto a : d.getAirports()){
        std::cout << a.first << " -- " << a.second.getName() <<std::endl;
    }


    return 0;
}
