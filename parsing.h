//
// Created by user on 08.12.2022.
//
#include <iostream>
#include "string"
#include "fstream"

#ifndef UNTITLED_PARSING_H
#define UNTITLED_PARSING_H
bool reconciliation_lines(const char *in_text, const char *example);//Определяет совпадение
const char *text_position(const char *in_text, const char *example);//Определяет позицию в тексте
std::string text_between_positions(const char *start_text_position, const char *end_text_position, const char *some_text);//функция посиска строки от и до
std::string take_between(const char *from, const char *to);//Функция поиска строки от и до
const char *text_between_positions2(const char *text, const char *prefix, const char *suffix, std::string &out); //Функция передвигает указатель и копирует кусочек текста
char* read_out_file(const std::string& filename);//Функция чтения файла
struct testing_structures; //структура для данных
#endif //UNTITLED_PARSING_H
