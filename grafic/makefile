all: mensagem compilar

mensagem:
	@echo Iniciando compilacao

compilar: main.o
	g++ main.o -o zuma -L<sfml-install-path>/lib -lsfml-graphics -lsfml-window -lsfml-system
	@echo Compilacao finalizada

main.o: main.cpp
	g++ -c main.cpp
		