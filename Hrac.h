//
// Created by Dominika Barbieriková & Katarína Kalusová on 29. 12. 2021.
//
#include "Hadik.h"
#ifndef SEMESTRALKA_HRAC_H
#define SEMESTRALKA_HRAC_H

#endif //SEMESTRALKA_HRAC_H

class Hrac {
public:
    explicit Hrac(Hadik* phadik);
    int getBody();
    void zvysBody(int pBody);

private:
    int body;
    Hadik* hadik;
    int poradie;

};

