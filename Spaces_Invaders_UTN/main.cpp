#include <iostream>
#include "Inicio_Allegro.h"
#include "Disparos_nave.h"
#include "allegro.h"

using namespace std;

// ********* TAMAÑO PANTALLA ********* //
class tamanoPantalla{
    private:
        int anchoPantalla;
        int altoPantalla;
    public:
        void setAnchoPantalla();
        int getAnchoPantalla();
        void setAltoPantalla();
        int getAltoPantalla();

};
// **** ANCHO **** //
void tamanoPantalla::setAnchoPantalla(){
    anchoPantalla = 600;
}
int tamanoPantalla::getAnchoPantalla(){
    return anchoPantalla;
}
// **** ALTO **** //
void tamanoPantalla::setAltoPantalla(){
    altoPantalla = 375;
}
int tamanoPantalla::getAltoPantalla(){
    return altoPantalla;
}

// ********* DISPAROS NAVE ********* //
class disparosNave{
    private:
        int maxDisparos;
        int numeroDisparos;
        int dsw,contadorTiempo;
    public:
        void setMaxDisparos();
        void setNumeroDisparos();
        void setDsw(int );
        void setContadorTiempo(int );
        int getMaxDisparos();
        int getNumeroDisparos();
        int getDsw();
        int getContadorTiempo();
};
void disparosNave::setMaxDisparos(){
    maxDisparos = 1;
}
void disparosNave::setNumeroDisparos(){
    numeroDisparos = 0;
}
void disparosNave::setDsw(int num){
    dsw = num;
}
void disparosNave::setContadorTiempo(int cont){
    if(cont == 0){
        contadorTiempo = 0;
    }
    else{
        contadorTiempo+=1;
    }

}
int disparosNave::getMaxDisparos(){
    return maxDisparos;
}
int disparosNave::getContadorTiempo(){
    return contadorTiempo;
}
int disparosNave::getDsw(){
    return dsw;
}
int disparosNave::getNumeroDisparos(){
    return numeroDisparos;
}

// ************************************************************************** //
// ************************************************************************** //
/*void iniciar_bitmaps(BITMAP *buffer,BITMAP *bala,BITMAP *nave){
    tamanoPantalla tam;

}*/
// ************************************************************************** //

int main()
{
    tamanoPantalla tam;
    disparosNave disp;
    Balas disparos[disp.getMaxDisparos()];
    // INICIAR ALLEGRO //
    inicia_allegro(tam.getAnchoPantalla(),tam.getAltoPantalla());

    // INICIAR BITMAPS //
    //iniciar_bitmaps(BITMAP buffer,BITMAP bala, BITMAP nave);
    BITMAP *buffer = create_bitmap(tam.getAnchoPantalla(),tam.getAltoPantalla());
    BITMAP *bala = load_bitmap("Imagenes/Bala2.bmp",NULL);
    BITMAP *nave = load_bitmap("Imagenes/nave.bmp",NULL);

    int x = tam.getAnchoPantalla();
    int y = tam.altoPantalla() - 50;

    while(!key[KEY_ESC]){

        clear_to_color(buffer,0x000000); // LIMPIA EL BUFFER DE COLOR NEGRO
        masked_blit(nave,buffer,0,0,x,y,30,20);

        if(key[KEY_SPACE] && disp.getDsw() == 0){
            crear_bala(disp.getNumeroDisparos(),disp.getMaxDisparos(),disparos,x,y,-4);
            disp.setDsw(1);
        }
        disp.setContadorTiempo(0);
        while(disp.getContadorTiempo() != 6){
            disp.setContadorTiempo(1);
        }
        pintar_bala(disp.getNumeroDisparos(),disp.getMaxDisparos(),disparos,buffer,bala);
        elimina_bala(disp.getNumeroDisparos(),disp.getMaxDisparos(),disparos,tam.getAnchoPantalla(),tam.getAltoPantalla());

        if(key[KEY_LEFT]){
            x -= 5;
        }
        if(key[KEY_RIGHT]){
            x+= 5;
        }
        blit(buffer,screen,0,0,0,0,tam.getAnchoPantalla(),tam.getAltoPantalla());
        rest(20);


    }




    return 0;
}
END_OF_MAIN(); // NECESARIO SINO TIRA ERROR: SDL_MAIN
