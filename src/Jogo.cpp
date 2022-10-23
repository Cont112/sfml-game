#include "../include/Jogo.h"

using namespace Gerenciadores;

Jogo::Jogo() : pGrafico(Graficos::getInstance())
{
    executar();
}

Jogo::~Jogo()
{
}

void Jogo::executar()
{
    sf::RectangleShape* box = new sf::RectangleShape(sf::Vector2f(100.f,100.f));
    sf::Vector2f velocity(sf::Vector2f(.1f,.1f));
    const char* path = "../assets/images.jpeg";
    pGrafico->createTexture(path);
    pGrafico->loadTextures();
    box->setTexture(pGrafico->textureMap.at(path));

    while(pGrafico->isWindowOpen())
    {

        pGrafico->handleEvent();
        //
        pGrafico->updateDeltaTime();
        pGrafico->clear();

        pGrafico->render(box);

        box->setPosition(box->getPosition() + velocity);
        //
        //
        pGrafico->display();
    }
}

