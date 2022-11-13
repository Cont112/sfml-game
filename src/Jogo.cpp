#include "../include/Jogo.h"

#define WIDTH 1280
#define HEIGHT 720

Jogo::Jogo(): pGrafico(Gerenciadores::Gerenciador_Grafico::getInstance()), 
              j1(),
              i1(),
              chao()
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
    chao.setTextura(pGrafico->textureMap.at(ini1));
    
    //setando posicao do chao 
    chao.setTamanho(sf::Vector2f(WIDTH, 20));//altura do chao = 20
    chao.setPosicao(sf::Vector2f(0, 640));//posicao chao
    
        


    //loop principal 
    while(pGrafico->isWindowOpen())
    {
        pGrafico->executar();

        j1.executar();
        i1.executar();       
        chao.executar();
        pGrafico->display();        
    }


}
void Jogo:: criarEntidades()
{
    
}



