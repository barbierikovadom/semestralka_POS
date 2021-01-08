
#include "ZbieraneObjekty.h"
#include <time.h>
#include <stdlib.h>
#include "Pravidla.cpp"
#include "Hadik.h"
#include "Hrac.h"


int main() {
    srand (time(NULL));
    Pravidla pravidla;
    Hadik* hadik = new Hadik(&pravidla);
    Hrac* hrac = new Hrac(hadik);
    ZbieraneObjekty objekt;
    objekt.nacitajPole(&pravidla);
    objekt.vytvorNovyObjekt();
    pravidla.printBorder();
    if(hadik->getX() == objekt.getX() && hadik->getY() == objekt.getY()) {
        objekt.setZjedeny(true);
        hadik->pridajDlzku();
        hrac->zvysBody();
    }
    pravidla.vypisPole();
    objekt.vytvorNovyObjekt();
    pravidla.vypisPole();
    hadik->zobrazSa(5,5);
    pravidla.vypisPole();
    cout << " W, A, S, D \n" ;
    char  znak;
    for (int i = 0; i < 5; ++i) {
        scanf("  %c", &znak);
        if(hadik->move(znak)){
            cout << "score: " << hrac->getBody() << "\n";
            pravidla.vypisPole();
        }
    }

}

