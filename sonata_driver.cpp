//
// Created by user on 10.01.2023.
//

#include "sonata_driver.h"
#include "parsing.h"

sonata_driver::sonata_driver() : name(), address(), num(0)
{

}

const char* sonata_driver::parse_data(const char* in)
{
    std::string dev_num;
    in = text_between_positions2(in, "ItemName=\"", "\"", name);
    in = text_between_positions2(in, "Device=\"", "\"",  dev_num);
    in = text_between_positions2(in, "Channel=\"", "\"", address);
    num = std::stoi(dev_num);

    return in;
}