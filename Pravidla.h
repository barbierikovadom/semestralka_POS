//
// Created by Katarína Kalusová on 30/12/2020.
//
#include <iostream>
#include <stdio.h>
#include <string>

#ifndef SEMESTRALKA_PRAVIDLA_H
#define SEMESTRALKA_PRAVIDLA_H

using namespace std;

class Pravidla {
public:
    Pravidla() {
        for (int i = 0; i < 40; i++) {
            pole[i] = new string[40];
            for (int j = 0; j < 40; j++) {
                pole[i][j] = "  ";
            }
        }
    }

    void printBorder() {
        for (int i = 0; i < 40; i++) {
            pole[0][i] = "* ";
            pole[39][i] = "* ";
        }

        for (int j = 0; j < 40; j++) {
            for (int i = 0; i < 40; i++) {
                if (i == 0 || i == 39) {
                    pole[j][0] = "* ";
                    pole[j][39] = "* ";
                }
            }
        }
    this->vypisPole(this->pole);
    }

    ~Pravidla(){
        for(int i = 0; i < 40; i++) {
            delete[] pole[i];
        }
        delete[] pole;

    }

    string **getPole() const {
        return pole;
    }

    void vypisPole(string** pPole){
        for (int j = 0; j < 40; j++) {
            for (int i = 0; i < 40; i++) {
                cout << pPole[j][i] ;
            }
            cout << endl;
        }
    }

    void setPole(string **pole) {
        this->pole = pole;
    }

private:
    string** pole = new string*[40];

};


#endif //SEMESTRALKA_PRAVIDLA_H
