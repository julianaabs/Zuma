#ifndef _HEADER_H_
#define _HEADER_H_

template <class object>

class Node{

public:
	object bola;
	Node *next;
	Node *back;
	Node(void){}
};

template <class object>
class Lista{

public:
	Node<object> *head;
	Node<object> *tail;
	Lista(void);
	//Lista(object);
	int fsize;
	void InserirInicio(object h);
	void InserirPosicao(object h, int pos);
	void InserirFinal(object h);
	void RemoverInicio();
	void RemoverPosicao(int pos);
	void RemoverFinal();
	void NumeroElementos();
	void BuscarElemento(object h);
	void DeletarLista();
	void ImprimirLista();
	int Indice(object h);
};


#include "mainList.inl"

#endif
