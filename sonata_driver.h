//
// Created by user on 10.01.2023.
//

#ifndef UNTITLED_SONATA_DRIVER_H
#define UNTITLED_SONATA_DRIVER_H


#include <string>

class sonata_driver {
        std::string name;
        std::string address;
        int num;
public:
    sonata_driver();//объявление конструктора
    const char* parse_data(const char* in);
};


#endif //UNTITLED_SONATA_DRIVER_H