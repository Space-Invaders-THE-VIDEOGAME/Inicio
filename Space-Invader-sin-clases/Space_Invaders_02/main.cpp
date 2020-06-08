#include <iostream>
#include <allegro.h>
#include "Inicio_Allegro.h"
#include "Disparos.h"

#define ANCHO 600
#define ALTO  375

class NAVE{
private:
    int X,Y;
    int n_disparos;
    int maxdisp;
    int tick;
public:
    BITMAP * img_nave;
    BITMAP* img_bala;
    void setX();
    void setY();
    void iniciaNB(char* ruta_nave,char*ruta_bala);
    void pintar(BITMAP* buffer);
    void mueve();
    void setN_Disparos();
    void setMaxDisparos();
    int getX();
    int getY();
    int getMaxDisp();
    int getNroDisp();
};
void NAVE::setX(){X=ANCHO/2;}
void NAVE::setY(){Y=ALTO-373;}
int NAVE::getX(){return X;}
int NAVE::getY(){return Y;}
int NAVE::getMaxDisp(){return maxdisp;}
void NAVE::setN_Disparos(){
    n_disparos = 0;
}
int NAVE::getNroDisp(){return n_disparos;}

void NAVE::setMaxDisparos(){
    maxdisp = 4;
}

void NAVE:: iniciaNB(char* ruta_nave,char*ruta_bala)
{
img_nave=load_bitmap(ruta_nave,NULL);
img_bala=load_bitmap(ruta_bala,NULL);
}
void NAVE::pintar(BITMAP* buffer)
{
    masked_blit(img_nave,buffer,0,0,X,Y,30,20);
}
void NAVE::mueve()
{
     if(key[KEY_LEFT])X -= 5;
        if(key[KEY_RIGHT])X += 5;
}
using namespace std;

int main(){

    inicia_allegro(ANCHO,ALTO);

    BITMAP *buffer = create_bitmap(ANCHO, ALTO);;
  ////BITMAP *nave = load_bitmap("Recursos/nave.bmp", NULL);

   NAVE N;
   N.iniciaNB("Imagenes/nave.bmp","Imagenes/Bala2.bmp");
    int contt = 0;
    Balas disparos[N.getMaxDisp()];

    while(!key[KEY_ESC]){
        clear_to_color(buffer,0x000000);
N.pintar(buffer);
N.mueve();
        if(key[KEY_SPACE]){
            crear_bala(N.getNroDisp(),N.getMaxDisp(),disparos,N.getX(),N.getY(),-6);
        }
        if(contt++ > 6){
            contt = 0;
        }
        pintar_bala(N.getNroDisp(),N.getMaxDisp(),disparos,buffer,N.img_bala);
        elimina_bala(N.getNroDisp(),N.getMaxDisp(),disparos,ANCHO,ALTO);

        blit(buffer,screen,0,0,0,0,ANCHO,ALTO);
        rest(20);
    }

	return 0;
}
END_OF_MAIN();

