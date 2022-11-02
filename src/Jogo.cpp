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

    const char* path = "assets/images.jpeg";
    pGrafico->createTexture(path);
    pGrafico->loadTextures();



    
    while(pGrafico->isWindowOpen())
    {

        pGrafico->handleEvent();
        pGrafico->updateDeltaTime();
        pGrafico->clear();
       

        pGrafico->display();        
    }

}

