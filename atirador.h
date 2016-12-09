#ifndef _ATIRADOR_H_
#define _ATIRADOR_H_

#include "mainList.h"
#include "bola.h"

/*
   A classe atirador gera as bolas, atira e verifica a colisão, depois 
   retorna a informação, que será tratada nas outras classes.
*/
class Atirador
{
public:
	Bola gerarBola(Lista<Bola> lista);

	int gerarY(int coeficiente, int x, int x1, y1);
	
	Bola colisao(Ponto colidiu, Lista<Bola> lista);

	void atirar(&Bola origem, &Bola alvo);
};

#include "atirador.cpp"

#endif
