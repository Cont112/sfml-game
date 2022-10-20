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

void Graficos::render(sf::Text* text)
{
    window->draw(*text);
}

void Graficos::display()
{
    window->display();
}

void Graficos::clear()
{
    window->clear();
}

bool Graficos::isWindowOpen() const
{
    return window->isOpen();
}

void Graficos::closeWindow()
{
    window->close();
}

void Graficos::updateDeltaTime()
{
    dt = clock.getElapsedTime().asSeconds();
    std::cout << dt << std::endl;
    clock.restart();
}
}
