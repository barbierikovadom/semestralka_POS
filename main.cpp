
#include "ZbieraneObjekty.h"
#include <time.h>
#include <stdlib.h>
#include<time.h>
#include<ctype.h>
#include <time.h>
#include <unistd.h>
#include "Pravidla.cpp"
#include "Hadik.h"

int main() {
    srand (time(NULL));
    Pravidla pravidla;
    Hadik* hadik = new Hadik(&pravidla);
    ZbieraneObjekty objekt;
    objekt.nacitajPole(&pravidla);
    objekt.vytvorNovyObjekt();
    pravidla.printBorder();
    if(hadik->getX() == objekt.getX() && hadik->getY() == objekt.getY()) {
        objekt.setZjedeny(true);
        hadik->pridajDlzku();
    }
    pravidla.vypisPole(pravidla.getPole());
    objekt.vytvorNovyObjekt();
    pravidla.vypisPole(pravidla.getPole());
}


