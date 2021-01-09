//
// Created by Dominika Barbieriková & Katarína Kalusová on 29. 12. 2020.
//
#include "Hrac.h"


Hrac::Hrac(Hadik *phadik) {
    this->hadik=phadik;
    this->body=0;
}

int Hrac::getBody() {
    return body;
}

void Hrac::zvysBody() {
    this->body++;
}
