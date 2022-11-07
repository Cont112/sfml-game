#include "../include/Jogo.h"


Jogo::Jogo(): pGrafico(Gerenciadores::Gerenciador_Grafico::getInstance()) , j1()
{
    executar();
}

Jogo::~Jogo()
{
    pGrafico->~Gerenciador_Grafico();
    std::cout << "Jogo fechou." << std::endl;
}

void Jogo::executar()
{

    const char* path = "assets/images.jpeg";
    const char* path2 = "assets/index.jpeg";

    pGrafico->createTexture(path);
    pGrafico->createTexture(path2);
    pGrafico->loadTextures();

    
    j1.setTextura(pGrafico->textureMap.at(path));

    
    while(pGrafico->isWindowOpen())
    {

        pGrafico->handleEvent();
        pGrafico->updateDeltaTime();
        pGrafico->clear();

        pGrafico->render(j1.getShape());
        j1.movimentar();
       
        pGrafico->display();        
    }


}

