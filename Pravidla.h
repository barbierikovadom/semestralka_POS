//
// Created by Katarína Kalusová on 30/12/2020.
//
#include <iostream>
#include <stdio.h>

#ifndef SEMESTRALKA_PRAVIDLA_H
#define SEMESTRALKA_PRAVIDLA_H


class Pravidla {
public:

    Pravidla() {}

    void printBorder(){
        for(int i = 0; i < 70; i++)
        {
            printf("*");
        }

        printf("\n");

        for (int j = 0; j < 40; j++) {
            for(int i = 0; i < 70; i++)
            {
                if( i == 0 || i == 69){
                    printf("*");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        for(int i = 0; i < 70; i++)
        {
            printf("*");
        }
    }
private:

};


#endif //SEMESTRALKA_PRAVIDLA_H
