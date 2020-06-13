#ifndef ENEMIGOS_H_INCLUDED
#define ENEMIGOS_H_INCLUDED
class Enemigo
{
private:
    float x;
    float y;
    int vidaE;
    int cont;
    int tipo;
    BITMAP* sprite;
    BITMAP* vida_enemy;
    Alarma*alarma_enemy;
public:
    Enemigo(float,float,int);
    ~Enemigo();
    void mover_enemigo();
    void accion();

};

list <Enemigo*> enemys;

Enemigo::Enemigo(float x, float y, int _tipo)
{
    this ->x=x;
    this ->y=y;
    this ->sprite  =  load_bitmap("imagen/enemigo.bmp",NULL);
    this ->vida_enemy=load_bitmap("imagen/b_vida.bmp",NULL);
    this ->alarma_enemy = new Alarma[15];
    this ->tipo = _tipo;
    this ->vidaE = 100;
}


Enemigo::~Enemigo()
{
    enemys.remove(this);
    destroy_bitmap(this->sprite);
    destroy_bitmap(this->vida_enemy);

    delete[]alarma_enemy;
}
void Enemigo::accion()
{

    draw_sprite(lienzo,this->sprite,x,y); // imprime al enemigo  sobre el lienzo
    float tam_vidaE =(50.0/100.0)*vidaE;
    stretch_sprite(lienzo,vida_enemy,x,y,tam_vidaE,5);// pinta la barra de vida del enemigo
    for (list<Bala*>::iterator it =balas.begin(); it !=balas.end(); it++) // iterador de las balas del jugador
    {
        Bala* b= *it;
        if (b->getx() >=x && b->getx() <= x+sprite->w && b->gety() >=y && b->gety() <= y+sprite->h)
        {
            delete b;       //si se cumple la condicion  bala desaparece cuando coliicione con el enemigo
            this ->vidaE-=4;
        }
    }
    this ->mover_enemigo();
    if (this ->vidaE<=0 or this->x>SCREEN_W)
    {
        delete this;               //elimina los enemigos cunado ya no tienen vida
    }
}




void Enemigo::mover_enemigo()
{
    switch(this->tipo)            //  funcion para el movimiento  de la nave enmiga hay 0,1 y 2 dependiendo del switch
    {
    case 0:
        if(this->alarma_enemy[0].alarma(6))
        {
            x+=4;
            y+=0;
        }
        break;
    case 1:
        if(this->alarma_enemy[0].alarma(6))
        {
            x+=2;
            y+= cos(x/100);
        }
        break;

    case 2:
        if(this->alarma_enemy[0].alarma(2))
        {
            x+= 1.5;

            if(this->y >= SCREEN_H - (SCREEN_H/3))
            {
                cont = -1;
            }

            if(cont == -1)
            {
                y+= pow((x-(this->x - SCREEN_H/4))/100,2) * cont;
            }
            else
            {
                y+= pow(x/100,2);
            }
        }
        break;
    }
}

#endif // ENEMIGOS_H_INCLUDED
