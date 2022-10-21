#include "../include/Gerenciadores/Graficos.h"

#include<cstring>
#include<iostream>

#define FONT_PATH "./assets/Fonts/Mayan.ttf"
#define W_NAME "Tab"
#define WIDTH 1200
#define HEIGHT 720
#define FRAME_RATE 144

namespace Gerenciadores {

Graficos* Graficos::instance = NULL;

Graficos* Graficos::getInstance()
{
    if(instance == NULL)
    {
        instance = new Graficos();
    }
    return instance;

}

float Graficos::dt = 0;

Graficos::Graficos(): window(new sf::RenderWindow(sf::VideoMode(WIDTH,HEIGHT), W_NAME)),
                      view(sf::Vector2f(WIDTH/2, HEIGHT/2), sf::Vector2f(WIDTH,HEIGHT)),
                      clock() {}

Graficos::~Graficos()
{
    
    delete(window);
}

void Graficos::render(sf::RectangleShape* shape)
{
    window->draw(*shape);
}

void Graficos::display()
{
    if(window != nullptr)
        window->display();
    else 
    {
        std::cout << "Erro ao criar janela (display)" << std::endl;
        exit(1);
    } 
}

void Graficos::clear()
{
    if(window != NULL)
        window->clear();
    else
        {
            std::cout << "Erro ao criar janela (clear)" << std::endl;
            exit(1);
        }
}

bool Graficos::isWindowOpen() const
{
    if(window != NULL)
        return window->isOpen();
    std::cout << "Erro ao verificar a janela" << std::endl;
    exit(1);
}

void Graficos::closeWindow()
{
    if(window != NULL)
        window->close();

    else
    {
        std::cout << "Nao eh possivel fechar a janela." << std::endl;
        exit(1);
    }
}

void Graficos::updateDeltaTime()
{
    dt = clock.getElapsedTime().asSeconds();
    std::cout << dt << std::endl;
    clock.restart();
}

}
