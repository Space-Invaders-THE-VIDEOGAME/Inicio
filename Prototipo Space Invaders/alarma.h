#ifndef ALARMA_H_INCLUDED
#define ALARMA_H_INCLUDED


class Alarma           //creamos una clase alarma para manejar los tiempos que se dibujen los sprites
{
    private:
        int cont;
    public:
        Alarma();
        bool alarma(int);
};


Alarma::Alarma()
{
    this ->cont=0;
}


bool Alarma::alarma(int seg)
{
    if(seg == 0){           // si el parametro recibido es igual a 0 no se dibujaran mas sprites
		return false;
	}

	if(cont >= seg){
		cont = 0;
		return true;
	}

	cont++;
	return false;
}
#endif // ALARMA_H_INCLUDED
