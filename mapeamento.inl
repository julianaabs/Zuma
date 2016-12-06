#include <iostream>
#include "mapeamento.h"

Map::Map(Node<object> *auxInserido, Lista<object> *auxGame){
	ThreeVerify = 0;
	maisPosition = -1;
	menosPosition = -1;
	numberOfBalls;
	game = auxGame;
	auxAfter = NULL;
	auxBefore = NULL;
	inserido = auxInserido;
}

template <class object>
void Lista<object>::DeletarSeq(){
	Node<object> *cont = auxBefore->next; 
	while(cont!=auxAfter){
		Node<object> *tmp = cont;
		cont = tmp->next;
		delete tmp;
	}

	fsize-=numberOfBalls;
}

void Map::RemoveSeq(){

	if(VerifySeq(inserido)==true){
			Pontos();
			DeletarSeq();
			auxBefore->next = auxAfter;
			while(VerifySeq(auxBefore)){
				DeletarSeq();
				auxBefore->next = auxAfter;
				Combo();
			}
	}
	numberOfBalls = maisPosition - menosPosition;
}

void Map::Pontos(){
	if(numberOfBalls == 3){
		player.points = 30;
	}else if(numberOfBalls > 3){
		for(int i=4; i<=numberOfBalls; i++){
			player.points+=10;
		}
	}
}

/* Realiza a eliminação de sequências com qualquer número de bolinhas realizando um tipo de "mapeamento". O nó que está
sendo inserido é passado como referência pois através dele será feito o mapeamento com os elementos da frente e os elementos
de trás (utilizando os nós 'before' e 'after'). Após o mapeamento, os índices da primeira e da última bolinhas da sequência
são guardados para poder eliminar aquela sequência e depois fazer o ligamento das duas cadeias restantes.
*/
bool Map::VerifySeq(Node<object> *inserido){
	auxAfter = inserido;
	bool before, after;
	while(auxAfter->data == inserido->data && auxAfter->next != NULL){
		auxAfter = auxAfter->next;
		after = true;
	}
	maisPosition = game.Indice(auxAfter->back);
	auxBefore = inserido;
	while(auxBefore->data == inserido->data && auxBefore->back != NULL){
		auxBefore = auxBefore->back;
		before = true;
	}
	menosPosition = game.Indice(auxBefore->next);
	numberOfBalls = maisPosition - menosPosition;
	if(before || after){
		return true;
	}
	else{
		return false;
	}
	return false;
}

bool Map::Combo(){
	while(VerifySeq(auxBefore)==true){
		player.points+=100;
		return true;
	}
	return false;
}

void Map::Tiro(Node<object> *auxInserido){
	
}