all:
	g++ -o main src/*.cpp -lsfml-graphics -lsfml-audio -lsfml-network -lsfml-window -lsfml-system
clean:
	rm *.o