
#include "ZbieraneObjekty.h"
#include <time.h>
#include <stdlib.h>
#include<time.h>
#include<ctype.h>
#include <time.h>
#include <unistd.h>
#include "Pravidla.cpp"

int main() {
    Pravidla pravidla;
    pravidla.printBorder();
    ZbieraneObjekty objekt;
    objekt.vypisObjekt(&pravidla);
    pravidla.vypisPole(pravidla.getPole());
}


