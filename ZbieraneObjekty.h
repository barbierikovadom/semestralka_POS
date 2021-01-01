//
// Created by Dominika on 29. 12. 2020.
//

#include "Pravidla.h"

#ifndef SEMESTRALKA_ZBIERANEOBJEKTY_H
#define SEMESTRALKA_ZBIERANEOBJEKTY_H

#endif //SEMESTRALKA_ZBIERANEOBJEKTY_H

class ZbieraneObjekty{
public:
    ZbieraneObjekty(){
        this->x = rand() % 38 + 1;
        this->y = rand() % 38 + 1;
        this->pocetBodov = 0;
    }

    void vypisObjekt(Pravidla *pPravidla){
        string** pole =  pPravidla->getPole();
        pole[x][y] = "? ";
        pPravidla->setPole(pole);
    }

private:
    int x;
    int y;
    int pocetBodov;
};
