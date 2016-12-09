#include <iostream>

/* 
   Função que cria um objeto Bola, após isso, verifica se a Bola criada tem a cor existente na lista de bolas,
   no caso, é analizada a primeira bola da lista comparada com o objeto criado, enquanto a Bola for diferente 
   do primeiro elemento bola da lista, vai ser instanciado um novo elemento Bola que será analizado novamente.
*/   
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

/*
	Função retorna a coordenada Y da equação da reta, 
*/
int Atirador::gerarY(int coeficiente, int x, int x1, y1)
{
	return coeficiente * (x - x1) + y1;
}

/*
   Com um evento do sfml, é possivel verificar se um objeto colidiu com algum outro elemento, sabendo disso
   o front-end dessa colisão, cria um objeto Ponto com as coordenadas da colisão e chama a função colisao.
   Na função colisao, e feita uma verificação de todos os objetos da lista de bolas. Pegamos as coordenadas 
   dos objetos bola e verificamos se o ponto que colidiu está no raio do objeto, se o ponto estiver no raio 
   da bola, esta será retornada, para fazer a verificação de combo.
*/
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
/*
   A função atirar faz com que ao objeto Bola do atirador(Bola origem) movasse de acordo com a posição do mouse(Bola alvo).
*/
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
