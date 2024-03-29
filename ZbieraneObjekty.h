//
// Created by Dominika Barbieriková & Katarína Kalusová on 29. 12. 2020.
//

#include "Pravidla.h"

#ifndef SEMESTRALKA_ZBIERANEOBJEKTY_H
#define SEMESTRALKA_ZBIERANEOBJEKTY_H

#endif //SEMESTRALKA_ZBIERANEOBJEKTY_H

class ZbieraneObjekty{
public:
    ZbieraneObjekty(){
        this->x = rand() % 17 + 1;
        this->y = rand() % 17 + 1;
        this->pocetBodov = 0;
        this->zjedeny = true;
    }

    int getPocetBodov() const {
        return this->pocetBodov;
    }

    bool isZjedeny() const {
        return zjedeny;
    }

    void setZjedeny(bool pZjedeny) {
        this->zjedeny = pZjedeny;
        this->pole[x][y] = "  ";
        this->vytvorNovyObjekt();
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    void nacitajPole(Pravidla *pPravidla){
        this->pole =  pPravidla->getPole();
    }

    void vytvorNovyObjekt() {
        if(zjedeny== true){
            this->x = rand() % 17 + 1;
            this->y = rand() % 17 + 1;
            this->pole[x][y] = "? ";
            this->zjedeny = false;
            this->pocetBodov = rand() % 4 + 1;
        }
    }

private:
    int x;
    int y;
    int pocetBodov;
    bool zjedeny;
    string** pole;
};
