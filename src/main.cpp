#include <SFML/Graphics.hpp>
#include "../stdafx.h"

const int LARGURA = 1600, ALTURA = 960;

int main()
{
    sf::RenderWindow janela(sf::VideoMode(LARGURA, ALTURA), "Janela", sf::Style::Close | sf::Style::Titlebar);
    int i = 0;
    while (janela.isOpen())
    {
        
        sf::Event event;
        while (janela.pollEvent(event))
        {
            if (event.type == event.Closed)
                janela.close();
        }
        
        //inicio do frame
        janela.clear(sf::Color::White);
        
        std::cout << "Frame: " << i << std::endl;
        i++;
        
        //final do frame
        janela.display();
    } 
}
