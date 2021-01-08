//
// Created by Katarína Kalusová on 30/12/2020.
//
#include <iostream>
#include <stdio.h>
#include <string>
#include <curses.h>

#ifndef SEMESTRALKA_PRAVIDLA_H
#define SEMESTRALKA_PRAVIDLA_H

using namespace std;

class Pravidla {
public:
    Pravidla() {
        for (int i = 0; i < 20; i++) {
            pole[i] = new string[20];
            for (int j = 0; j < 20; j++) {
                pole[i][j] = "  ";
            }
        }
    }

    void printBorder() {
        for (int i = 0; i < 20; i++) {
            pole[0][i] = "* ";
            pole[19][i] = "* ";
        }

        for (int j = 0; j < 20; j++) {
            for (int i = 0; i < 20; i++) {
                if (i == 0 || i == 19) {
                    pole[j][0] = "* ";
                    pole[j][19] = "* ";
                }
            }
        }
    this->vypisPole();
    }

    ~Pravidla(){
        for(int i = 0; i < 20; i++) {
            delete[] pole[i];
        }
        delete[] pole;

    }

    string **getPole() const {
        return pole;
    }

    void vypisPole(){
        for (int j = 0; j < 20; j++) {
            for (int i = 0; i < 20; i++) {
                cout << pole[j][i] ;
            }
            cout << endl;
        }
    }

    void setPole(string **pole) {
        this->pole = pole;
    }



private:
    string** pole = new string*[20];

};


#endif //SEMESTRALKA_PRAVIDLA_H
