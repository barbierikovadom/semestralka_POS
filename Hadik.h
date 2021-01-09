//
// Created by Dominika Barbieriková & Katarína Kalusová on 29. 12. 2020.
//
#include <string>
#include <iostream>
#include <unistd.h>
#include "Pravidla.h"

#ifndef SEMESTRALKA_HADIK_H
#define SEMESTRALKA_HADIK_H

using namespace std;

class Hadik{
public:
    explicit Hadik( Pravidla *pPravidla);
    void zobrazSa(int px, int py);
    bool move(char znak);
    string getFarba() const;
    void setFarba(const string &pfarba);
    int getX() const;
    void setX(int px);
    int getY() const;
    void setY(int py);
    void goTo(int px, int py);
    void pridajDlzku();

private:
    int x;
    int y;
    int dlzka;
    string** pole;
    string smer;
    string farba;
    Pravidla *pravidla;
};

#endif //SEMESTRALKA_HADIK_H