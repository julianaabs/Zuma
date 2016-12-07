#ifndef _MAPEAMENTO_H_
#define _MAPEAMENTO_H_

template <class object>

class Map{
public:
	int ThreeVerify;
	int maisPosition;
	int menosPosition;
	int position;
	int counterCombo;
	gamer player;
	Lista<object> game;
	Node <object> *inserido;
	Node<object> *auxBefore;
	Node<object> *auxAfter;
	Map Map(Node<object> *auxInserido, Lista<object> *auxGame);
	//void RemoveSeq();
	void DeletarSeq();
	bool VerifySeq();
	void Pontos();
	//bool Combo();
	//void Tiro();

}

#include "mapeamento.inl"

//fazer 2 whiles, um p frente e um p trás, p ir pegando os índices enquanto for a mesma bolinha
//e enquanto nao for null, menor do q 0 ou lista size
//deletar, puxar lista, pontos, quais nós deletados


#endif