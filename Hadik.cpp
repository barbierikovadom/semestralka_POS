//
// Created by Dominika Barbieriková & Katarína Kalusová on 29. 12. 2020.
//

#include "Hadik.h"


Hadik::Hadik(Pravidla *pPravidla) {
    this->x = 2;
    this->y = 2;
    this->pole =  pPravidla->getPole();
    this->pole[this->x][this->y] = "> ";
    this->smer = "pravo";
    this->dlzka = 0;
    this->pravidla = pPravidla;
}

void Hadik::goTo(int px, int py) {
    this->pole[this->x][this->y] = "  ";
    this->setX(px);
    this->setY(py);
    int i,j,k,l = 0;

    while(this->smer == "pravo") {
        this->pole[this->x][(this->y)+i] = "> ";
        this->pole[this->x][(this->y)+i-1] = "  ";
        pravidla->vypisPole();
        i++;
        usleep(1000000);
    }
    while(this->smer == "lavo") {
        this->pole[this->x][this->y-j] = "< ";
        this->pole[this->x][this->y-j+1] = "  ";
        pravidla->vypisPole();
        j++;
        usleep(1000000);
    }
    while(this->smer == "hore") {
        this->pole[this->x-k][this->y] = "^ ";
        this->pole[this->x-k+1][this->y] = "  ";
        pravidla->vypisPole();
        k++;
        usleep(1000000);
    }
    while(this->smer == "dole") {
        this->pole[this->x+l][this->y] = "v ";
        this->pole[this->x+l-1][this->y] = "  ";
        pravidla->vypisPole();
        l++;
        usleep(1000000);
    }
}

void Hadik::zobrazSa(int px, int py) {
    this->goTo(px,py);

    //snaha o vypysovanie chvostika
    /**if(this->smer == "pravo") {
        for (int i = px - 1; i > px - dlzka - 1; i--) {
            this->pole[py][i] = "- ";
        }
    }
    if(this->smer == "lavo") {
        for (int i = px - 1; i > px - dlzka - 1; i--) {
            this->pole[py][i] = "- ";
        }
    }
    if(this->smer == "hore") {
        for (int i = px - 1; i > px - dlzka - 1; i--) {
            this->pole[py][i] = "- ";
        }
    }
    if(this->smer == "dole") {
        for (int i = px - 1; i > px - dlzka - 1; i--) {
            this->pole[py][i] = "- ";
        }
    }**/
}

bool Hadik::move(char znak) {
    if(znak == 'W' || znak == 'w'){
        if(this->x-1 > 0) {
            int px = this->x-1;
            this->smer = "hore";
            this->zobrazSa(px, this->y);
            return true;
        } else {
            cout << "Sem uz nemozes ist";
            return false;
        }
    } else if(znak == 'A' || znak == 'a'){
        if(this->y-1 > 0) {
            int py = this->y-1;
            this->smer = "lavo";
            this->zobrazSa(this->x,py);
            return true;
        } else {
            cout << "Sem uz nemozes ist";
            return false;
        }
    } else if(znak == 'S' || znak == 's'){
        if(this->x+1 < 19) {
            int px = this->x+1;
            this->smer = "dole";
            this->zobrazSa(px,this->y);
            return true;
        } else {
            cout << "Sem uz nemozes ist";
            return false;
        }
    } else if(znak == 'D' || znak == 'd'){
        if(this->y+1 < 19) {
            int py = this->y+1;
            this->smer = "pravo";
            this->zobrazSa(this->x,py);
            return true;
        } else {
            cout << "Sem uz nemozes ist";
            return false;
        }
    }
    cout << "ERROR in function Hadik::move()";
    return false;
}

string Hadik::getFarba() const {
    return this->farba;
}

void Hadik::setFarba(const string &pfarba) {
    this->farba = pfarba;
}

int Hadik::getX() const {
    return this->x;
}

void Hadik::setX(int px) {
    this->x = px;
}

int Hadik::getY() const {
    return this->y;
}

void Hadik::setY(int py) {
    this->y = py;
}

void Hadik::pridajDlzku() {
    this->dlzka++;
}

