#include <allegro.h>
BITMAP* lienzo;         // el bitmap lienzo es el fondo base donde se va a imprimir las otras imagenes
#include <iostream>
using namespace std;
# include <list>
#include <math.h>
#include "alarma.h"
#include "bala.h"
#include "nave.h"
#include"enemigos.h"
void crear_enemigos();
void movimiento_enemigo();
void init();
void deinit();
Alarma *tiempo = new Alarma();

int main()
{
    init();
    lienzo = create_bitmap(SCREEN_W,SCREEN_H);
    Nave *nave = new Nave();
    BITMAP* fondo =load_bitmap("imagen/fondo1.bmp",NULL);
    while (!key[KEY_ESC])
    {

        draw_sprite(lienzo,fondo,0,0);
        crear_enemigos();
        movimiento_enemigo();
        nave->mover();
        draw_sprite(screen,lienzo,0,0);
        clear_to_color(lienzo,0x3F36C5);
    }
    deinit();

    return 0;
}
END_OF_MAIN()


void init()                               //funcion para iniciar  allegro
{
    int depth, res;
    allegro_init();
    depth = desktop_color_depth();
    if (depth == 0)
        depth = 32;
    set_color_depth(depth);
    res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 700, 500, 0, 0);
    if (res != 0)
    {
        allegro_message(allegro_error);
        exit(-1);
    }

    install_timer();
    install_keyboard();
    install_mouse();

}
void deinit()
{
    clear_keybuf();

}


void crear_enemigos()
{
    static int cont =0;

    if (cont<5)
    {
        if (tiempo->alarma(200))                //       tiempo en que aparacen los enemigos
        {                                        //     cuanto mas alto el valor mas alejado el enemigo siguiente
            enemys.push_back(new Enemigo(-80,15,0));
            cont ++;
        }

    }
    else
    {
        if (tiempo->alarma(300))   //tiempo para separar los grupos de 5 enemigos
        {
        cont=0;
        }
    }
}

void movimiento_enemigo()
{
    for (list<Enemigo*>::iterator it = enemys.begin();it !=enemys.end();it++)// iterador para la bala
    {
        Enemigo *ene = *it;
        ene->accion();
    }
}
