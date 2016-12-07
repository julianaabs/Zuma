#include <iostream>
#include "mapeamento.h"
#include "mainList.h"

template <class object>
Map<object>::Map(Node<object> *auxInserido, Lista<object> *auxGame){
	ThreeVerify = 0;
	maisPosition = -1;
	menosPosition = -1;
	counterCombo = 0;
	numberOfBalls = 0;
	game = auxGame;
	player = new gamer();
	auxAfter = NULL;
	auxBefore = NULL;
	inserido = auxInserido;
}

template <class object>
void Map<object>::DeletarSeq(){
	Node<object> *cont = auxBefore->next; 
	while(cont!=auxAfter){
		Node<object> *tmp = cont;
		cont = tmp->next;
		delete tmp;
	}
	game->fsize-=numberOfBalls;
}

template <class object>
void Map<object>::RemoveSeq(){
 	if(VerifySeq(inserido)==true){
		Pontos();
		DeletarSeq();
		auxBefore->next = auxAfter;
		auxAfter->back = auxBefore;
		inserido = auxBefore;
		while(VerifySeq(auxBefore)){
			counterCombo++;
			Pontos();
			DeletarSeq();
			auxBefore->next = auxAfter;
			auxAfter->back = auxBefore;
		}
	}
} 

template <class object>
void Map<object>::Pontos(){
	if(numberOfBalls == 3){
		player->points = 30;
	}else if(numberOfBalls > 3){
		for(int i=4; i<=numberOfBalls; i++){
			player->points+=10;
		}
	}
	if(counterCombo > 0){
		player->points+=100;
	}
}

/* Realiza a eliminação de sequências com qualquer número de bolinhas realizando um tipo de "mapeamento". O nó que está
sendo inserido é passado como referência pois através dele será feito o mapeamento com os elementos da frente e os elementos
de trás (utilizando os nós 'before' e 'after'). Após o mapeamento, os índices da primeira e da última bolinhas da sequência
são guardados para poder eliminar aquela sequência e depois fazer o ligamento das duas cadeias restantes.
*/
template <class object>
bool Map<object>::VerifySeq(Node<object> *inserido){
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
	numberOfBalls = maisPosition - menosPosition;
	return false;
}

/* bool Map::Combo(){
	
}

/* void Map::Tiro(Node<object> *auxInserido){
	
} */