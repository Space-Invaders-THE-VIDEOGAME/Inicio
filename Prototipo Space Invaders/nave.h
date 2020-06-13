#ifndef NAVE_H_INCLUDED
#define NAVE_H_INCLUDED
class Nave
{
private:
    int x;
    int y;
    BITMAP* sprite;
public:
    Nave ();
    void mover ();
};

Nave::Nave()
{
    x=300;    //cordenadas (300,400) donde aparece la nave del jugador
    y=400;
    sprite=load_bitmap("imagen/nave.bmp",NULL);
}

void Nave::mover()
{
    if (key[KEY_SPACE]&&alarma_bala(1))
    {
        balas.push_back(new Bala(x+(sprite->w/2)-3,y,0));
    }

    for (list<Bala*>::iterator it =balas.begin();it !=balas.end();it++)// iterador para la bala
    {
        Bala* b= *it;
        b->mover_bala();
    }


    if (key[KEY_RIGHT])
    {
        x++;
    }
    if (key[KEY_LEFT])
    {
        x--;
    }

    if (key[KEY_UP])
    {
        y--;
    }
    if (key[KEY_DOWN])
    {
        y++;
    }
    draw_sprite(lienzo,sprite,x,y);
}
#endif // NAVE_H_INCLUDED
