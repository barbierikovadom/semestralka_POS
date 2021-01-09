//
// Created by Dominika Barbieriková & Katarína Kalusová on 29. 12. 2020.
//

#include "ZbieraneObjekty.h"
#include <ctime>
#include <cstdlib>
#include "Pravidla.h"
#include "Hadik.h"
#include "Hrac.h"


int main() {

    srand(time(nullptr));

    Pravidla pravidla;
    Hadik* hadik = new Hadik(&pravidla);
    Hrac* hrac = new Hrac(hadik);
    ZbieraneObjekty objekt;

    objekt.nacitajPole(&pravidla);
    objekt.vytvorNovyObjekt();
    pravidla.printBorder();

    pravidla.vypisPole();
    objekt.vytvorNovyObjekt();
    pravidla.vypisPole();
    hadik->zobrazSa(5,5);
    pravidla.vypisPole();

    cout << " W, A, S, D \n" ;

    char znak;

    for (int i = 0; i < 50; ++i) {
        if(hadik->getX() == objekt.getX() && hadik->getY() == objekt.getY()) {
            objekt.setZjedeny(true);
            objekt.vytvorNovyObjekt();
            hadik->pridajDlzku();
            hrac->zvysBody();
        }
        scanf("  %c", &znak);
        if(hadik->move(znak)){
            cout << "score: " << hrac->getBody() << "\n";
            pravidla.vypisPole();
        }
    }
}

