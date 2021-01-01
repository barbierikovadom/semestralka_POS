//
// Created by Dominika on 29. 12. 2020.
//
#include <string>
#include <iostream>
#ifndef SEMESTRALKA_HADIK_H
#define SEMESTRALKA_HADIK_H

#endif //SEMESTRALKA_HADIK_H

using namespace std;

class Hadik{
public:
    Hadik(const string &farba) : farba(farba) {}

    const string getFarba() const {
        return this->farba;
    }

    void setFarba(const string &pfarba) {
        this->farba = pfarba;
    }

    int getX() const {
        return this->x;
    }

    void setX(int px) {
        this->x = px;
    }

    int getY() const {
        return this->y;
    }

    void setY(int py) {
        this->y = py;
    }

    void goTo(int px, int py){
        this->setX(px);
        this->setY(py);
    }

private:
    string farba;
    int x;
    int y;
    int dlzka;
};