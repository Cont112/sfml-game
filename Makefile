all:	
	g++ -c *.cpp src/*.cpp src/Gerenciadores/*.cpp  -I SFML/include
	g++ *.o -Wall -o main -L SFML/lib -lsfml-graphics -lsfml-window -lsfml-system
	rm -f *.o


	

