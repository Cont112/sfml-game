#include "../include/Jogo.h"


Jogo::Jogo(): pGrafico(Gerenciadores::Gerenciador_Grafico::getInstance()), 
              j1()
{
    executar();
}

Jogo::~Jogo()
{
}

void Jogo::executar()
{

    const char* path = "assets/barreto.jpg";
    sf::Texture texture;
    if(!texture.loadFromFile(path))
        std::cout << "Nao foi possivel carregar a textura" << std::endl;
    else
        std::cout << "Textura carregada com sucesso!" << std::endl;
    j1.setTextura(&texture);
    
    


    

    while(pGrafico->isWindowOpen())
    {

        pGrafico->handleEvent();
        pGrafico->updateDeltaTime();
        pGrafico->clear();

        j1.imprimir_se();
        j1.movimentar();
       
        pGrafico->display();        
    }

}

