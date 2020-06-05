#include <iostream>
#include "allegro.h"

using namespace std;

bool comenzar_Juego = true;

int main()
{
    if(comenzar_Juego){
        cout << " :) " << endl;
    }
    else{
        cout << " :( " << endl;
    }
    return 0;
}
END_OF_MAIN(); // NECESARIO SINO TIRA ERROR: SDL_MAIN
