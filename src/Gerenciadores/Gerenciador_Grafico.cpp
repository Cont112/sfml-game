#include "../../include/Gerenciadores/Gerenciador_Grafico.h"

#include<cstring>
#include<iostream>

#define W_NAME "Tab"
#define WIDTH 1280
#define HEIGHT 720
#define FRAME_RATE 144

namespace Gerenciadores {

Gerenciador_Grafico* Gerenciador_Grafico::instance = NULL;

Gerenciador_Grafico* Gerenciador_Grafico::getInstance()
{   
    if(instance == NULL)
    {
        instance = new Gerenciador_Grafico();
    }
    return instance;

}

float Gerenciador_Grafico::dt = 0;

Gerenciador_Grafico::Gerenciador_Grafico(): window(new sf::RenderWindow(sf::VideoMode(WIDTH,HEIGHT), W_NAME)),
                      view(sf::Vector2f(WIDTH/2, HEIGHT/2), sf::Vector2f(WIDTH,HEIGHT)),
                      clock(),
                      textureMap() {}

Gerenciador_Grafico::~Gerenciador_Grafico()
{
    std::map<const char*, sf::Texture*>::iterator it;
    for(it = textureMap.begin(); it != textureMap.end();it++)
    {
        delete it->second;
    }
    textureMap.clear();
    delete(window);
    std::cout << "Gerenciador_Grafico foi destruido!" << std::endl;
}

void Gerenciador_Grafico::render(sf::RectangleShape shape)
{
    window->draw(shape);
}

void Gerenciador_Grafico::display()
{
    if(window != NULL)
        window->display();
    else 
    {
        std::cout << "Erro ao criar janela (display)" << std::endl;
        exit(1);
    } 
}

void Gerenciador_Grafico::clear()
{
    if(window != NULL)
        window->clear();
    else
        {
            std::cout << "Erro ao criar janela (clear)" << std::endl;
            exit(1);
        }
}

bool Gerenciador_Grafico::isWindowOpen() const
{
    if(window != NULL)
        return window->isOpen();
    std::cout << "Erro ao verificar a janela" << std::endl;
    exit(1);
}

void Gerenciador_Grafico::closeWindow()
{
    if(window != NULL)
        window->close();

    else
    {
        std::cout << "Nao foi possivel fechar a janela." << std::endl;
        exit(1);
    }
}

sf::RenderWindow* Gerenciador_Grafico::getWindow() const 
{
    if(window != NULL)
        return window;
    std::cout << "A janela nao existe!" << std::endl;
    exit(1);
}

float Gerenciador_Grafico::getDt() const
{
    return dt;
}

void Gerenciador_Grafico::updateDeltaTime()
{
    dt = clock.getElapsedTime().asSeconds();
    clock.restart();
}


void Gerenciador_Grafico::createTexture(const char* path)
{
    bool jaCriada = false;
    std::map<const char*, sf::Texture*>::iterator it;

    for(it = textureMap.begin(); it != textureMap.end(); it++)
    {
        if(it->first == path)
        {
            jaCriada = true;
            std::cout << "Textura ja existe!" << std::endl;
        }
        
    }

    if(!jaCriada){ 
        sf::Texture* texture = new sf::Texture;
        textureMap.insert(std::pair<const char*, sf::Texture*>(path,texture));
        if(!texture->loadFromFile(path)){
            std::cout << "Nao foi possivel carregar a textura" << std::endl;
            exit(1);
        }
        std::cout << "Textura no caminho " << path << " criada e carregada com sucesso!" << std::endl;
    }
}

void Gerenciador_Grafico::deletarInstance()
{
    if(instance){
        delete instance;
    } else {
        std::cout << "Gerenciador_Grafico: nao foi possivel deletar instancia, nao existe!" << std::endl;
    }
}

void Gerenciador_Grafico::executar()
{
    updateDeltaTime();
    clear();
}

}
