#include "../../include/Gerenciadores/Graficos.h"

#include<cstring>
#include<iostream>

#define FONT_PATH "../assets/Fonts/Mayan.ttf"
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
                      clock(),
                      textureMap() {}

Graficos::~Graficos()
{
    std::map<const char*, sf::Texture*>::iterator it;
    for(it = textureMap.begin(); it != textureMap.end();it++)
    {
        std::cout << it->first << std::endl; 
        delete it->second;
    }
    textureMap.clear();
    delete(window);
}

void Graficos::render(sf::RectangleShape* shape)
{
    window->draw(*shape);
}

void Graficos::render(sf::Sprite* sprite)
{
    window->draw(*sprite);
}

void Graficos::display()
{
    if(window != NULL)
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
        std::cout << "Nao foi possivel fechar a janela." << std::endl;
        exit(1);
    }
}

sf::RenderWindow* Graficos::getWindow() const 
{
    if(window != NULL)
        return window;
    std::cout << "A janela nao existe!" << std::endl;
    exit(1);
}

void Graficos::handleEvent()
{
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                closeWindow();
        }
        
}

void Graficos::updateDeltaTime()
{
    dt = clock.getElapsedTime().asSeconds();
    clock.restart();
}

void Graficos::loadTextures()
{
    std::map<const char*, sf::Texture*>::iterator it;
    for (it = textureMap.begin(); it != textureMap.end(); it++)
    {
        it->second->loadFromFile(it->first);
    }
}

void Graficos::createTexture(const char* path)
{
    std::map<const char*, sf::Texture*>::iterator it;

    for(it = textureMap.begin(); it != textureMap.end(); it++)
    {
        if(it->first == path)
        {
            std::cout << "Textura ja existe!" << std::endl;
            exit(1);
        }
        
    }

    sf::Texture* texture = new sf::Texture;
    textureMap.insert(std::pair<const char*, sf::Texture*>(path,texture));
        
    
}

}
