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
	auxAfter = inserido;
	while(auxAfter->data == inserido->data && auxAfter->next != NULL){
		auxAfter = auxAfter->next;
	}
	maisPosition = game.Indice(auxAfter->back);
	while(auxBefore->data == inserido->data && auxBefore->back != NULL){
		auxBefore = auxBefore->back;
	}
	menosPosition = game.Indice(auxBefore->next);
	game.DeletarSeq();
	numberOfBalls = maisPosition - menosPosition;
	auxBefore->next = auxAfter;

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

bool Map::VerifySeq(Node<object> *inserido){
	auxAfter = inserido;
	while(auxAfter->data == inserido->data && auxAfter->next != NULL){
		auxAfter = auxAfter->next;
		return true;
	}
	maisPosition = game.Indice(auxAfter->back);
	while(auxBefore->data == inserido->data && auxBefore->back != NULL){
		auxBefore = auxBefore->back;
		return true;
	}
	menosPosition = game.Indice(auxBefore->next);
	return false;
}

void Map::Combo(){
	while(VerifySeq()==true){
		player.points+=100;
	}
}

void Map::Tiro(Node<object> *auxInserido){
	
}