//
// Created by Dominika Barbieriková & Katarína Kalusová on 29. 12. 2020.
//

#include "ZbieraneObjekty.h"
#include <time.h>
#include <stdlib.h>
#include "Pravidla.h"
#include "Hadik.h"
#include "Hrac.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <iostream>
#include <string.h>


struct spolocneData{
    pthread_mutex_t* mutex;
    pthread_cond_t* stlacenaKlavesa;
    pthread_cond_t* vypisane;

    Pravidla pravidla;
    Hadik* hadik = new Hadik(&pravidla);
    Hrac* hrac = new Hrac(hadik);
    ZbieraneObjekty objekt;

    bool bolZadanyKlaves;
    char zadanyKlaves;
};

void* vypis(void* thData) {

    struct spolocneData *data = (struct spolocneData *) thData;
    using namespace std;
    pthread_mutex_lock(data->mutex);

    while (data->bolZadanyKlaves == false) {
        pthread_cond_wait(data->stlacenaKlavesa, data->mutex);

    }
        //toto asi nechať v main a sem dať len pohyb hadíka
        // len data->hadik->move(data->zadanyKlaces) + vypisPole
        //aby sa hadík pohyboval daným smerom pokým nieje stlačený kláves
        if (data->hadik->getX() == data->objekt.getX() && data->hadik->getY() == data->objekt.getY()) {
            data->objekt.setZjedeny(true);
            data->objekt.vytvorNovyObjekt();
            data->hadik->pridajDlzku();
            data->hrac->zvysBody(data->objekt.getPocetBodov());
        }
        if (data->hadik->move(data->zadanyKlaves)) {
            cout << "score: " << data->hrac->getBody() << "\n";
            data->pravidla.printBorder();
        }

        data->bolZadanyKlaves = false;

    pthread_mutex_unlock(data->mutex);
    pthread_cond_signal(data->vypisane);

    return 0;

}

void* zmenaSmeru(void* thData) {
    struct spolocneData *data = (struct spolocneData *) thData;

    pthread_mutex_lock(data->mutex);
    pthread_cond_wait(data->vypisane, data->mutex);

    char znak;
    scanf("  %c", &znak);
    data->bolZadanyKlaves = true;
    data->zadanyKlaves = znak;

    if (data->hadik->move(data->zadanyKlaves)) {
        cout << "score: " << data->hrac->getBody() << "\n";
        data->pravidla.printBorder();
    }

    pthread_mutex_unlock(data->mutex);
    pthread_cond_signal(data->stlacenaKlavesa);


    return 0;
}

int main(int argc, char *argv[]) {
    using namespace std;
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

    /*for (int i = 0; i < 50; ++i) {
         if(hadik->getX() == objekt.getX() && hadik->getY() == objekt.getY()) {
             objekt.setZjedeny(true);
             objekt.vytvorNovyObjekt();
             hadik->pridajDlzku();
             hrac->zvysBody(objekt.getPocetBodov());
         }
         scanf("  %c", &znak);
         if(hadik->move(znak)){
             cout << "score: " << hrac->getBody() << "\n";
             pravidla.vypisPole();
         }
     }*/

     pthread_mutex_t mutex;
     pthread_cond_t cond1;
     pthread_cond_t cond2;

     pthread_mutex_init(&mutex,NULL);
     pthread_cond_init(&cond1, NULL);
     pthread_cond_init(&cond2, NULL);

     struct spolocneData data;
     data.mutex = &mutex;
     data.vypisane = &cond1;
     data.stlacenaKlavesa = &cond2;
     data.bolZadanyKlaves = true;
     data.zadanyKlaves = 'D';

     printf("-------Zaciatok hadíka---------\n");
     //while(scanf("  %c", &znak) != 'q') {
         pthread_t vypisVlakno;
         pthread_create(&vypisVlakno, NULL, &vypis, &data);

         pthread_t zmenaSmeruVlakno;
         pthread_create(&zmenaSmeruVlakno, NULL, &zmenaSmeru, &data);

         pthread_join(vypisVlakno, NULL);
         pthread_join(zmenaSmeruVlakno, NULL);
   //  }
     printf("-------Koniec hadíka---------\n");
     pthread_mutex_destroy(&mutex);
     pthread_cond_destroy(&cond1);
     pthread_cond_destroy(&cond2);

    return 0;
}

