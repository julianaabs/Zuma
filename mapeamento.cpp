#include <iostream>
#include ""

Map::Map(Node<object> *auxInserido, Lista<object> *auxGame){
	ThreeVerify = 0;
	maisPosition = -1;
	menosPosition = -1;
	game = auxGame;
	auxAfter = NULL;
	auxBefore = NULL;
	inserido = auxInserido;
}

void Map::Combo(){
	auxAfter = inserido;
	while(auxAfter->data == inserido->data && auxAfter->next != NULL){
		auxAfter = auxAfter->next;
	}
	maisPosition = game.Indice(auxAfter->back);
	while(auxBefore->data == inserido->data && auxBefore->back != NULL){
		auxBefore = auxBefore->back;
	}
	menosPosition = game.Indice(auxBefore->next);

}