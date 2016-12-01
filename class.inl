#include <iostream>
#include "header.h"

template <class object>
Lista<object>::Lista(){
	fsize = 0;
	head = NULL;
	tail = NULL;
}

template <class object>
void Lista<object>::InserirInicio(object h){
	if(fsize!=0){
		Node<object> *tmp = new Node<object>();
		tmp->data = h;
		tmp->next = head;
		head->back = tmp;
		head = tmp;
		fsize++;
	}else{
		Node<object> *tmp = new Node<object>();
		tmp->data = h;
		head = tmp;
		tail = tmp;
		tail->next = NULL;
		tail->back = NULL;
		fsize=1;
	}
}


template <class object>
void Lista<object>::InserirPosicao(object h, int pos){
	if(pos==0){
		InserirInicio(h);
		return;
	}
	if(pos>fsize){
		std::cout << "Posição inválida" << std::endl;
		return;
	}
	Node<object> *tmp = new Node<object>();
	Node<object> *cont = head;	
	for(int i=1; i<=fsize; i++){
		if(i==pos){
			tmp->data = h;
			tmp->next = cont->next;
			Node<object> *next = cont->next;
			next->back = tmp;
			cont->next = tmp;
			tmp->back = cont;
			fsize++;
			break;
		}else{
			cont = cont->next;
		}
	}
}

template <class object>
void Lista<object>::InserirFinal(object h){
	if(fsize!=0){
		Node<object> *tmp = new Node<object>();
		tmp->data = h;
		tail->next = tmp;
		tmp->back = tail;
		tail = tmp;
		tail->next = NULL;
		tail->back = tmp->back;
		fsize++;
	}
}

template <class object>
void Lista<object>::RemoverInicio(){
	if(fsize==0){
		std::cout << "Lista vazia" << std::endl;
		return;
	}
	else if(fsize==1){
		delete head;
		head=NULL;
		tail=NULL;
		return;
	}else{
		Node<object> *tmp;
		tmp = head;
		head = head->next;
		head->back = NULL;
		delete tmp;
		fsize--;
	}
}

template <class object>
void Lista<object>::RemoverPosicao(int pos){
	if(fsize==0){
		std::cout << "Lista vazia" << std::endl;
		return;
	}
	if(pos>fsize){
		std::cout << "Operação inválida" << std::endl;
		return;
	}
	if(pos == 0){
		RemoverInicio();
		return;
	}
	Node<object> *cont = head;
	for(int i=1; i<=fsize; i++){
		if(i==pos){
			Node<object> *tmp = cont->next;
			tmp->back = cont;
			cont->next = tmp->next;
			cont->back = tmp->back;
			delete tmp;
			fsize--;
			break;
		}else{
			cont = cont->next;
		}
	}
}


template <class object>
void Lista<object>::RemoverFinal(){
	if(fsize==0){
		std::cout << "Lista vazia" << std::endl;
		return;
	}
	if(fsize==1){
		delete head;
		head=NULL;
		tail=NULL;
		return;
	}
	Node<object> *cont = head;
	while(cont->next!=tail) {
		cont = cont->next;	
	}
	tail = cont;
	delete cont->next;
	tail->next = NULL;
	fsize--;
}

template <class object>
void Lista<object>::NumeroElementos(){
	std::cout << "Tamanho da lista: " << fsize << std::endl;
}

template <class object>
void Lista<object>::BuscarElemento(object x){
	Node<object> *cont;
	int pos = 0;
	for(cont = head; cont!=NULL; cont = cont->next) {
		if(x==cont->data){
			std::cout << "Elemento encontrado na posicao " << pos << std::endl;
			return;
		}
		pos++;
	}
	std::cout << "Elemento nao esta na lista" << std::endl;
}


template <class object>
void Lista<object>::DeletarLista(){
	Node<object> *cont = head; 
	while(cont!=NULL){
		Node<object> *tmp = cont;
		cont = tmp->next;
		delete tmp;
	}
	fsize=0;
	head = NULL;
	tail = NULL;
}

template <class object>
void Lista<object>::ImprimirLista(){
	Node<object> *cont = head;
	while(cont!=NULL){
		std::cout << cont->data << std::endl;
		cont = cont->next;
	}
}