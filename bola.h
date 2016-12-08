#ifndef _BOLA_H_
#define _BOLA_H_

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