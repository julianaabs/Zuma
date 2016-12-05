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
			game.DeletarSeq();
	}
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

void Map::Combo(){
	while(VerifySeq(auxBefore)==true){
		player.points+=100;
	}
}

void Map::Tiro(Node<object> *auxInserido){
	
}