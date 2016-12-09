#include <stdlib.h>
#include <time.h>

/*
   Construtor Ponto, iniciando as variaveis no ponto(0,0)
*/
Ponto::Ponto()
{
	x = 0;
	y = 0;
}

/*
   Construtor Ponto, iniciando as variaveis nos pontos informados.
*/
Ponto::Ponto(int _x, int _y)
{
	x = _x;
	y = _y;
}

/*
   Metodos get's set's das coordenadas X e Y.
*/
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

/*
   Construtor Bola, iniciando as variaveis no ponto(0,0) e criando uma cor randomicamente.
*/
Bola::Bola()
{
	srand (time(NULL));
	cor = rand() % 3 + 1;
	
	ponto.setX(0);
	ponto.setY(0);	
}
	
/*
   Construtor Bola, iniciando as variaveis nos pontos informados e criando uma cor randomicamente.
*/
Bola::Bola(int _x, int _y)
{
	srand (time(NULL));
	cor = rand() % 3 + 1;

	ponto.setX(_x);
	ponto.setY(_y);
}

/*
   Metodo get para a cor da bola.
*/
int Bola::getCor()
{
	return cor;
}
