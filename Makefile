all:	
	g++ -c *.cpp src/*.cpp src/Entidades/*.cpp src/Entidades/Personagens/*.cpp src/Entidades/Personagens/Inimigos/*.cpp src/Listas/*.cpp src/Entidades/Obstaculos/*.cpp src/Gerenciadores/*.cpp src/Fases/*.cpp src/Menus/*.cpp -I SFML/include
	g++ *.o -Wall -o main -L SFML/lib -lsfml-graphics -lsfml-window -lsfml-system
	rm -f *.o


	

