//
// Created by Dominika Barbieriková & Katarína Kalusová on 30/12/2020.
//

#include "Pravidla.h"

Pravidla::Pravidla() {
    for (int i = 0; i < 20; i++) {
        pole[i] = new string[20];
        for (int j = 0; j < 20; j++) {
            pole[i][j] = "  ";
        }
    }
}

void Pravidla::printBorder() {
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
    vypisPole();
}

void Pravidla::vypisPole() {
    for (int j = 0; j < 20; j++) {
        for (int i = 0; i < 20; i++) {
            cout << pole[j][i] ;
        }
        cout << endl;
    }
}

string **Pravidla::getPole() {
    return pole;
}

void Pravidla::setPole(string **pole) {
    this->pole = pole;
}







