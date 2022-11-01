#include "../include/Jogo.h"


Jogo::Jogo(): pGrafico(Gerenciadores::Graficos::getInstance())
{
    executar();
}

Jogo::~Jogo()
{
}

void Jogo::executar()
{

    pGrafico->executar();

    //j1->setTexture (pGrafico->textureMap.at(paths[2]));
    
    while(pGrafico->isWindowOpen())
    {

        pGrafico->handleEvent();
        pGrafico->updateDeltaTime();
        pGrafico->clear();
        
        pGrafico->display();        
    }

}

