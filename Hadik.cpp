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
}

void Hadik::goTo(int px, int py) {
    this->pole[this->x][this->y] = "  ";
    this->setX(px);
    this->setY(py);


    if(this->smer == "pravo") {
        this->pole[this->x][this->y] = "> ";
    }
    if(this->smer == "lavo") {
        this->pole[this->x][this->y] = "< ";
    }
    if(this->smer == "hore") {
        this->pole[this->x][this->y] = "^ ";
    }
    if(this->smer == "dole") {
        this->pole[this->x][this->y] = "v ";
    }
}

void Hadik::zobrazSa(int px, int py) {
    this->goTo(px,py);

    //snaha o vypysovanie chvostika
    if(this->smer == "pravo") {
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
    }
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

