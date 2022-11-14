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
    criarEntidades();      

    //loop principal 
    while(pGrafico->isWindowOpen())
    {
        pGrafico->executar();

        lista.executar();
        
        pGrafico->display(); 
     
    }


}
void Jogo:: criarEntidades()
{
    //criando entidades
    j1 = new  Entidades::Personagens::Jogador ();
    i1 = new  Entidades::Personagens::Inimigo ();
    chao = new Entidades::Obstaculos::Obstaculo();


    //criando texturas
    const char* jog1 = "assets/images.jpeg";
    const char* ini1 = "assets/index.jpeg";
    pGrafico->createTexture(jog1);
    pGrafico->createTexture(ini1);
    pGrafico->loadTextures();

    j1->setTextura(pGrafico->textureMap.at(jog1));
    i1->setTextura(pGrafico->textureMap.at(ini1));
    chao->setTextura(pGrafico->textureMap.at(ini1));

    //criando obstaculos 
    chao->setTamanho(sf::Vector2f(WIDTH, 20));//altura do chao = 20
    chao->setPosicao(sf::Vector2f(0, 640));//posicao chao*/   
    
    //listando entidades
    Entidades::Entidade *e1 = static_cast<Entidades::Entidade*>(j1);
    Entidades::Entidade *e2 = static_cast<Entidades::Entidade*>(i1);
    Entidades::Entidade *e3 = static_cast<Entidades::Entidade*>(chao);

    lista.addEntidade(e1);
    lista.addEntidade(e2);
    lista.addEntidade(e3);
    
}



