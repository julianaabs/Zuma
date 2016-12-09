#ifndef _BOLA_H_
#define _BOLA_H_

/*
   Classe Ponto representa as coordenadas (x,y) que serão utilizadas na Classe Bola.
*/
class Ponto
{
	int x;
	int y;
public:
	Ponto();
	Ponto(int _x, int _y);
	
	int getX();
	void setX(int _x);
	
	int getY();
	void setY(int _y);
};

/*
   Classe Bola tem a representação da cor, que será tratada no front-end, de acordo com o numero,
   exemplor(1 = bola vermelha) e as coordenadas da bola no plano.
*/
class Bola
{
	int cor;	
public:

	Ponto ponto;

	Bola();
	Bola(int _x, int _y);

	int getCor();
};

#include "bola.cpp"

#endif
