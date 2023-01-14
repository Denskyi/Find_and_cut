#include <iostream>
#include "string"
#include "fstream"
#include "parsing.h"
#include "sonata_driver.h"

// parsing.cpp, parsing.h
void writing_in_file(const char* file_content,const std::string& filename);//Функция записи в файл
class sonata_driver_print{//новый класс печати , думал сделать его в качестве дополнения к соната драйвер но чёт нее вышло
    std::string name;//тип переменных должен совпадать с тем что отправим в консоль
    std::string address;//тип переменных должен совпадать с тем что отправим в консоль
    std::string num;//тип переменных должен совпадать с тем что отправим в консоль
public:
    explicit sonata_driver_print(std::string name, std::string address, std::string num);//тип переменных должен совпадать с тем что отправим в консоль
    friend std::ostream &operator<<(std::ostream &sout, const sonata_driver_print &instance);//позволяет обратиться к объектам класса
};

sonata_driver_print::sonata_driver_print(std::string name, std::string address, std::string num)  : name(name), address(address), num(num)//тип переменных должен совпадать с тем что отправим в консоль так же в скобочках должна быть сама переменная
{}

std::ostream &operator<<(std::ostream &sout, const sonata_driver_print &instance)//распаковывываем переменные в классе
{
    sout << "Print class:" << instance.num << instance.address << instance.name << std::endl;//вывод на экран через переменную instance
return sout;
}
int main() {
    const char *text1 = "test print";
    std::cout << text1<< std::endl;
    char text2[16];
    text2[15] = '\0';
    int i = 0;
    while (text1[i] != '\0') {
        text2[i] = text1[i];
        i++;
    }
    std::cout << text2<< std::endl;
    std::cout << text_position("test system","sys")<< std::endl;
    std::cout << text_between_positions("11","15","1234567890_11_12_13_14_15_16_17_18_19")<< std::endl;
    const char *some_text = "Ep 10_11_12_13_14_15_16_17_18_19 izi";
    std::cout << take_between("some_text + 8", some_text + 20) << std::endl;
    sonata_driver driver{};//тестирование структуры соната_драйвер

    const char* file_content_copy = read_out_file("AT_PRUCAT2HCBDEDBTR7CYICFZUYY.mb_cfg");//Хранилище/массив требуемого размера в оперативной памяти
 //   std::cout << file_content_copy << std::endl;//Вывод файла в консоль из массива (оперативной памяти)
    writing_in_file(file_content_copy, "some file.txt");
    delete[] file_content_copy;//Очистка из памяти
    return 0;


}



void writing_in_file(const char* file_content,const std::string& filename) {
    std::fstream fout{filename, std::fstream::binary | std::fstream::out};//Открываем файл для записи
    while (file_content != nullptr) {
        std::string dev_name;
        std::string dev_num;
        std::string address;
        file_content = text_between_positions2(file_content, "ItemName=\"", "\"", dev_name);
        file_content = text_between_positions2(file_content, "Device=\"", "\"", dev_num);
        file_content = text_between_positions2(file_content, "Channel=\"", "\"", address);
        if (fout) {
            sonata_driver_print printer{dev_name, address, dev_num};//помещает то что нашли суда
            std::cout << printer;
            fout << dev_name << dev_num << address << std::endl;//запись в файл результата
        }
    }
}

