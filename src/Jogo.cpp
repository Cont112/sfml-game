#include "../include/Jogo.h"


Jogo::Jogo()
{
    executar();
}

Jogo::~Jogo()
{
}

void Jogo::executar()
{

    std::vector<const char*> paths;

    

    paths.push_back("assets/index.jpeg");
    paths.push_back("assets/images.jpeg");
    paths.push_back("assets/barreto.jpg");
    
    for(const char* path : paths)
    {
        pGrafico->createTexture(path);
    }
    pGrafico->loadTextures();

    //j1->setTexture (pGrafico->textureMap.at(paths[2]));
    
    while(pGrafico->isWindowOpen())
    {

        pGrafico->handleEvent();
        pGrafico->updateDeltaTime();
        pGrafico->clear();
        
        pGrafico->display();        
    }

}

