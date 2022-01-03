//
// Created by Dominika Barbieriková & Katarína Kalusová on 29. 12. 2021.
//

#include "Server.h"
#include "Client.h"
#include <iostream>

int main(int argc, char const *argv[]){
    if(argc == 2){
        if(*argv[1] == 's'){
            //spusti server
            Server(1025);
        }
        else if (*argv[1] == 'c'){
            //spusti client
            Client(1025);
        }
        else {
            std::cout << "nevhodny parameter, pouzi Client alebo server";
        }
    }  else {
        std::cout << "male/velke mnozstvo parametrov";
    }

    return 0;
}
