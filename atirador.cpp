#include <iostream>

Atirador::Atirador();
	
Bola Atirador::gerarBola(Lista<Bola> lista, Ponto origem)
{
	Bola bola = new Bola(origem.getX(), origem.getY());
	
	Nodo aux = lista->head;
	
	while(bola.getCor() == aux->bola.getCor())
	{
		bola = new Bola(origem.getX(), origem.getY());
	}
	
	

	return bola;
}

int Atirador::gerarY(int coeficiente, int x, int x1, y1)
{
	return coeficiente * (x - x1) + y1;
}

Bola Atirador::colisao(Ponto colisao, Lista<Bola> lista)
{
	Nodo aux = lista->head;
	
	while(aux->next != lista->tail)
	{
		int x = aux->bola.getX();
		int y = aux->bola.getY();
		
		if(((colisao.getX() > (x - 8))||(colisao.getX() < (x + 8)))&&((colisao.getY() > (y - 8))||(colisao.getY() < (y + 8))))
		{
			return aux->bola;
		}
		else
		{
			aux = aux->next;
		}
	}
	
}

void Atirador::atirar(&Bola origem, &Bola alvo)
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