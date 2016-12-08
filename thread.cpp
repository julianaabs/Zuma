#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <time.h>

void RunList(Lista<object>){
	Lista<int> l; //tipo bola
	/* Aqui precisará rodar um loop pra inserir um elemento na fila a cada x segundos
	utilizar função sleep da thread */
	while(){
		Bola bola = new Bola(posicaoinicialX,posicaoinicialY);
		l.InserirFinal(bola); //random
		std::this_thread::sleep_for(std::chrono::miliseconds(2000));
	}if(numberofBalls<10){
		std::this_thread::sleep_for(std::chrono::miliseconds(2000));
	}
}
void Control(){

}

int main(){
	std::thread queue (RunList);

	std::thread shot (Control);

    // Makes the main thread wait for the new thread to finish execution, therefore blocks its own execution
	first.join();
	second.join();

	return 0;
}
