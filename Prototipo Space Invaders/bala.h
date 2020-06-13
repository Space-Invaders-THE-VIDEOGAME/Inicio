#ifndef BALA_H_INCLUDED
#define BALA_H_INCLUDED
class Bala
{
private:
    int x;
    int y;
    int tipo;
    BITMAP* sprite;
public:
    void mover_bala();
    Bala(int,int,int);
    int getx();
    int gety();
    ~Bala();
};

list < Bala*>balas;

int Bala::getx()
{
    return x;
}

int Bala::gety()
{
    return y;
}

Bala ::Bala(int _x,int _y,int _tipo)
{
    this -> x = _x;
    this -> y = _y;
    this ->sprite=load_bitmap("imagen/bala.bmp",NULL);
    this ->tipo= _tipo;
}

void Bala::mover_bala()
{

    if(y>0)
    {
        y--;
    }
    else
    {
        this->~Bala();
    }

    draw_sprite(lienzo,sprite,x,y);  //dibuja la bala sobre el fondo
}

Bala::~Bala()
{
    balas.remove(this);
}

static bool alarma_bala(int secons){
	static int cont = 0;

	if(secons == 0){
		return false;
	}

	if(cont >= secons){
		cont = 0;
		return true;
	}

	cont++;

	return false;
}
#endif // BALA_H_INCLUDED
