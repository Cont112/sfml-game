#include "../include/Jogo.h"


Jogo::Jogo(): pGrafico(Gerenciadores::Gerenciador_Grafico::getInstance()), 
              j1()
{
    executar();
}

Jogo::~Jogo()
{
    pGrafico->~Gerenciador_Grafico();
    std::cout << "Jogo fechou!" << std::endl;
}

void Jogo::executar()
{
    //criando texturas
    const char* jog1 = "assets/images.jpeg";
    const char* ini1 = "assets/index.jpeg";

    pGrafico->createTexture(jog1);
    pGrafico->createTexture(ini1);
    pGrafico->loadTextures();

    //setando texturas
    j1.setTextura(pGrafico->textureMap.at(jog1));
    i1.setTextura(pGrafico->textureMap.at(ini1));
    
    //loop principal 
    while(pGrafico->isWindowOpen())
    {
        pGrafico->executar();

        j1.executar();
        i1.executar();       
        pGrafico->display();        
    }


}

