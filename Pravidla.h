//
// Created by Dominika Barbieriková & Katarína Kalusová on 30/12/2020.
//
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <curses.h>

#ifndef SEMESTRALKA_PRAVIDLA_H
#define SEMESTRALKA_PRAVIDLA_H

using namespace std;

class Pravidla {
public:
    Pravidla();
    void printBorder();
    void vypisPole();
    string **getPole();
    void setPole(string **pole);

    ~Pravidla(){
        for(int i = 0; i < 20; i++) {
            delete[] pole[i];
        }
        delete[] pole;
    }

private:
    string** pole = new string*[20];

};

#endif //SEMESTRALKA_PRAVIDLA_H
