//
// Created by Dominika on 29. 12. 2020.
//AHOJ AHOJ AHOJ
//
#include "Hadik.h"
#ifndef SEMESTRALKA_HRAC_H
#define SEMESTRALKA_HRAC_H

#endif //SEMESTRALKA_HRAC_H

class Hrac {
public:
    Hrac(Hadik* phadik) {
        this->hadik=phadik;
        this->body=0;
    }

    int getBody(){
        return body;
    }

    void zvysBody(){
        this->body++;
    }

private:
    int body;
    Hadik* hadik;
    int poradie;

};

