#include <iostream>
#include <stdlib.h>
#include <time.h>

class Ponto
{
	int x;
	int y;

public:
	Ponto()
	{
		x = 0;
		y = 0;
	}

	Ponto(int _x, int _y)
	{
		x = _x;
		y = _y;
	}

	int getX()
	{
		return x;
	}

	void setX(int _x)
	{
		x = _x;
	}

	int getY()
	{
		return y;
	}

	void setY(int _y)
	{
		y = _y;
	}

};

class Bola
{
	int cor;
	
public:

	Ponto ponto;

	Bola(int _x, int _y)
	{
		srand (time(NULL));
		cor = rand() % 3 + 1;

		ponto.setX(_x);
		ponto.setY(_y);
	}

	int getCor()
	{
		return cor;
	}
	
	void setCor(int _cor)
	{
		cor = _cor;
	}
};

class atirador
{
	Bola origem = new Bola(MatheusX, MatheusY);
	Ponto alvo = Ponto(MateusMouseX, MateusMouseY);

public:

	atirador();

	Bola gerarBola()
	{
		Bola bola = new Bola(2);

		return bola;
	}

	int gerarY(int coeficiente, int x, int x1, y1)
	{
		return coeficiente * (x - x1) + y1;
	}

	void atirar(Bola origem, Bola alvo)
	{
		int x1 = origem.getX();
		int y1 = origem.getY();

		int x2 = alvo.getX();
		int y2 = alvo.getY();
		
		int coeficiente = (y2 - y1)/(x2 - x1);

		while(origem.getX() < 640 || origem.getY() < 450)
		{
			origem.setX(origem.getX()+1);

			origem.setY(gerarY(coeficiente, origem.getX(), x1, y1));
		}
	}
};