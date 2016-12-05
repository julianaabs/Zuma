#include <iostream>

//Inserir e for igual
//Inserir e não for igual

void Triple_Combo(object x, int position){
	InserirPosicao(x, position);
	if(x->data == x->next && x->next){
		Noode<object> *aux;
		x->next->next = x->back->back;
		delete x;
	}
}

void Combo(object x, int position){
	
}