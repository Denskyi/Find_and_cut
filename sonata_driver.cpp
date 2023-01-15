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
    try {
        num = std::stoi(dev_num);
    } catch (const std::exception) {
        num = 0;
    }
    return in;//Возвращает состояние файла
}
std::ostream &operator<<(std::ostream &sout, const sonata_driver &instance)
{
    sout << "Print:" << instance.num << instance.name << instance.address << std::endl;
    return sout;//Возвращает строку  полученную в результате работы, не понятно только как впринципе возможно дважды чё-то вернуть?
}
//const char *printing_driver;