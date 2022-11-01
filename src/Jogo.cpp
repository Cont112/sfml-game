#include "../include/Jogo.h"


Jogo::Jogo(): pGrafico(Gerenciadores::Graficos::getInstance())
{
    isRunning = false;
    executar();
}

Jogo::~Jogo()
{
}

void Jogo::executar()
{

    pGrafico->executar();
    
    while(pGrafico->isWindowOpen())
    {

        pGrafico->handleEvent();
        pGrafico->updateDeltaTime();
        pGrafico->clear();
        
        pGrafico->display();        
    }

}

