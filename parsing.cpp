//
// Created by user on 08.12.2022.
//
#include <iostream>
#include "string"
#include "fstream"

bool reconciliation_lines(const char *in_text, const char *example) {
    if (in_text == nullptr || example == nullptr) { //Проверка что входные данные не пустые
        return false;
    }
    const char *in_text_pos = in_text; //Для запоменания расположения указателя в тексте
    const char *in_example_pos = example; //Для запоменания расположения указателя в тексте
    while (*in_text_pos != '\0') {// Проверяем что текст не закончился
        if (*in_text_pos == *in_example_pos) {//Сверка символов
            in_text_pos++;
            in_example_pos++;
            continue;
        } else if (*in_example_pos == '\0') {//Если программа перешла суда, то значит закончился первый массив и все символы совпадают
            return true;
        } else {}
        return false;//Если программа перешла суда, то значит символы не совпадают
    }
    return true;//Если программа перешла суда, то значит символы в первом тексте закончились быстрее чем во втором
}

const char *text_position(const char *in_text, const char *example) {
    if (in_text == nullptr || example == nullptr) { //Проверка что входные данные не пустые
        return nullptr;
    }
    const char *in_text_pos = in_text; //Для запоменания расположения указателя в тексте
    while (*in_text_pos != '\0') {// Проверяем что текст не закончился
        if (reconciliation_lines(in_text_pos, example)) {//передаём в готовую функцию текущую строку со сдвигом
            return in_text_pos;//возвращаем то где нашлось
        }
        in_text_pos++;//передвигает указатель дальше
    }
    return nullptr;
}

std::string text_between_positions(const char *start_text_position, const char *end_text_position, const char *some_text) {
    if (start_text_position == nullptr || end_text_position == nullptr || some_text == nullptr) { //Проверка что входные данные не пустые
        return "nullptr";//Пишем о том что работать не будет
    }
    std::string s; //Переменная для записи результата
    const char *text_pos = text_position(some_text, start_text_position); //Копируем строку без начального куска текста
    while (*start_text_position == *text_pos) {
        start_text_position++;
        text_pos++;
    }
    while (!reconciliation_lines(text_pos,end_text_position)) {//Пишем до дех пор пока не найдём второй кусок текста
        s.push_back(*text_pos++);//посимвольная запись в результат
    }
    return s;
}

std::string take_between(const char *from, const char *to) {
    std::string s; //Переменная для записи результата
    while (from != to) {
        if (*from == '\0') {
            return "";//типо пустая строка
        }
        s.push_back(*from++);//посимвольная запись в результат
    }
    return s;
}

const char *text_between_positions2(const char *text, const char *prefix, const char *suffix, std::string &out) {//Функция передвигает указатель и копирует кусочек текста
    if (prefix == nullptr || suffix == nullptr || text == nullptr) { //Проверка что входные данные не пустые
        return "nullptr";//Пишем о том что работать не будет
    }
    std::string s; //Переменная для записи результата
    if (text_position(text, prefix) != nullptr) {
        text = text_position(text, prefix); //Копируем строку без начального куска текста
    } else {
        return nullptr;
    }
    while (*prefix == *text) {//передвигаем курсор на длинну префикса
        prefix++;
        text++;
    }
    while (!reconciliation_lines(text,suffix)) {//Пишем до дех пор пока не найдём второй кусок текста
        out.push_back(*text++);//посимвольная запись в результат
    }
    out.push_back('\t');
    return text;
}

char* read_out_file(const std::string& filename) {
    std::fstream fin{"AT_PRUCAT2HCBDEDBTR7CYICFZUYY.mb_cfg", std::fstream::binary | std::fstream::in};//Открытие фала
    if (!fin)//Проверка что открылось без ошибок
    {
        std::cout << "file is missing" << std::endl;
    }
    fin.seekg(0, std::istream::end);//Перемещаемся в конец файла
    std::streamsize file_size = fin.tellg();//Переменная запоминает длинну файла, аналог int
    char* file_content = new char[file_size + 1];//Хранилище/массив требуемого размера в оперативной памяти
    fin.seekg(0);//Перемещаемся в начало файла
    fin.read(file_content, file_size);//Копирование файла в созданный массив (хранилище)
    fin.close();//Закрываем файл
    file_content[file_size] = '\0';//Дописываем ноль вконце
    return file_content;
}