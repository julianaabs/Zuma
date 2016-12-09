#ifndef _MAPEAMENTO_H_
#define _MAPEAMENTO_H_
#include "mainList.h"


template <class object>
class Map{
public:
	//Guarda a posição da última bola a ser removida da sequência
	int maisPosition;
	//Guarda a posição da primeira bola a ser removida da sequência
	int menosPosition;
	//Guarda o número de bolas excluídas da lista para efetuar a pontuação do jogador
	int numberOfBalls;
	//Contador de combos
	int counterCombo;
	//Pontos do jogador
	int points;
	//Lista encadeada do jogo
	Lista<object> *game;
	//Nó da bolinha que foi inserida na lista, usada para realizar o mapeamento das sequências
	Node <object> *inserido;
	//Nó auxiliar que é a cabeça da sequência a ser removida
	Node<object> *auxBefore;
	//Nó auxiliar que é a cauda da sequência a ser removida
	Node<object> *auxAfter;
	//Construtor da classe
	Map(Node<object> *auxInserido, Lista<object> *auxGame);
	//Realiza o loop de verificações para deletar a sequência e os combos
	void RemoveSeq();
	//Deleta a sequência de bolinhas iguais
	void DeletarSeq();
	//Verifica se existe uma sequência de bolinhas iguais
	bool VerifySeq(Node<object> *inserido);
	//Distribui os pontos do jogador de acordo com o número de bolinhas excluídas
	void Pontos();
};

#include "mapeamento.inl"

//fazer 2 whiles, um p frente e um p trás, p ir pegando os índices enquanto for a mesma bolinha
//e enquanto nao for null, menor do q 0 ou lista size
//deletar, puxar lista, pontos, quais nós deletados


#endif