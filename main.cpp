#include <iostream>
#include "string"
#include "fstream"
#include "parsing.h"

// parsing.cpp, parsing.h
void writing_in_file(const char* file_content,const std::string& filename);//Функция записи в файл
int main() {
    const char *text1 = "test print";
    std::cout << text1<< std::endl;
    char text2[16];
    text2[15] = '\0';
    int i = 0;
    while (text1[i] != '\0') {
        text2[i] = text1[i];
        i++;
    }//test
    std::cout << text2<< std::endl;
    std::cout << text_position("test system","sys")<< std::endl;
    std::cout << text_between_positions("11","15","1234567890_11_12_13_14_15_16_17_18_19")<< std::endl;
    const char *some_text = "Ep 10_11_12_13_14_15_16_17_18_19 izi";
    std::cout << take_between("some_text + 8", some_text + 20) << std::endl;




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
            fout << dev_name << dev_num << address << std::endl;//запись в файл результата
        }
    }
}

