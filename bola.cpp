#include <stdlib.h>
#include <time.h>

Ponto::Ponto()
{
	x = 0;
	y = 0;
}

Ponto::Ponto(int _x, int _y)
{
	x = _x;
	y = _y;
}

int Ponto::getX()
{
	return x;
}

void Ponto::setX(int _x)
{
	x = _x;
}

int Ponto::getY()
{
	return y;
}

void Ponto::setY(int _y)
{
	y = _y;
}

Bola::Bola()
{
	srand (time(NULL));
	cor = rand() % 3 + 1;
	
	ponto.setX(0);
	ponto.setY(0);	
}
	
Bola::Bola(int _x, int _y)
{
	srand (time(NULL));
	cor = rand() % 3 + 1;

	ponto.setX(_x);
	ponto.setY(_y);
}

int Bola::getCor()
{
	return cor;
}