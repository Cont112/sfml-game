all:	
	g++ -c *.cpp src/*.cpp src/Entidades/*.cpp src/Entidades/Personagens/*.cpp src/Fases/*.cpp src/Gerenciadores/*.cpp src/Listas/*.cpp -I SFML/include
	g++ *.o -Wall -o main -L SFML/lib -lsfml-graphics -lsfml-window -lsfml-system
	rm -f *.o


	

