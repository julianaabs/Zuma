#include <iostream>
#include "mapeamento.h"
#include "mainList.h"

//Construtor da classe
template <class object>
Map<object>::Map(Node<object> *auxInserido, Lista<object> *auxGame){
	maisPosition = -1;
	menosPosition = -1;
	counterCombo = 0;
	numberOfBalls = 0;
	game = auxGame;
	points = 0;
	auxAfter = NULL;
	auxBefore = NULL;
	inserido = auxInserido;
}

/* Deleta a sequência de bolinhas iguais, sendo a cabeça da lista a primeira bolinha da sequência (auxBefore->next)
*/ 
template <class object>
void Map<object>::DeletarLista(){
	Node<object> *cont = auxBefore->next; 
	while(cont!=auxAfter){
		Node<object> *tmp = cont;
		cont = tmp->next;
		delete tmp;
	}
	game->fsize-=numberOfBalls;
}

/* Remove a sequência de bolinhas, além de realizar a verificação para saber se houve combo.
Após fazer a ligação das duas cadeias, se a verificação retornar true quer dizer que houve combo, assim 
incrementando o valor do contador de combos. Dentro do while, é feita a ligação das duas novas cadeias e o processo
se repete sempre que houver sequência de bolinhas a serem removidas. */
template <class object>
void Map<object>::RemoveSeq(){
 	if(VerifySeq(inserido)==true){
		Pontos();
		DeletarLista();
		auxBefore->next = auxAfter;
		auxAfter->back = auxBefore;
		inserido = auxBefore;
		/* Loop da verificação dos combos */
		while(VerifySeq(auxBefore)){
			counterCombo++;
			Pontos();
			DeletarLista();
			auxBefore->next = auxAfter;
			auxAfter->back = auxBefore;
		}
	}
} 

/* Realiza a contagem dos pontos do jogador de acordo com o número de bolinhas excluídas. Cada bolinha vale 10 pontos
e o jogador ganha 100 pontos extras por combo.
*/
template <class object>
void Map<object>::Pontos(){
	if(numberOfBalls == 3){
		points = 30;
	}else if(numberOfBalls > 3){
		for(int i=4; i<=numberOfBalls; i++){
			points+=10;
		}
	}
	if(counterCombo > 0){
		points+=100;
	}
}

/* Realiza a verificação de sequências com qualquer número de bolinhas realizando um tipo de "mapeamento". O nó que está
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