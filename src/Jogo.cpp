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

    //Listas::Lista<Entidades::Entidade> entityList; 
    //entityList.push_back(box);
    //entityList.push_back(sqr);
    Entidades::Entidade* box = new Entidades::Entidade(sf::Vector2f(100.f,100.f));
    Entidades::Entidade* sqr = new Entidades::Entidade(sf::Vector2f(100.f,100.f));
    
    //inicializando jogador
    
    Entidades::Personagens::Jogador* j1;
    //j1->setVelocidade(Fisica::CoordF (1.f, 1.f));

    std::vector<const char*> paths;

    paths.push_back("assets/index.jpeg");
    paths.push_back("assets/images.jpeg");
    paths.push_back("assets/barreto.jpg");
    
    for(const char* path : paths)
    {
        pGrafico->createTexture(path);
    }
    pGrafico->loadTextures();

    box->setTexture(pGrafico->textureMap.at(paths[0]));
    sqr->setTexture(pGrafico->textureMap.at(paths[1]));
    //j1->setTexture (pGrafico->textureMap.at(paths[2]));
    
    while(pGrafico->isWindowOpen())
    {

        pGrafico->handleEvent();
        pGrafico->updateDeltaTime();
        pGrafico->clear();

        pGrafico->render(box);
        pGrafico->render(sqr);
        sqr->move(sf::Vector2f(0.f,.1f));
        box->move(sf::Vector2f(.1f,0.f));

        //pGrafico->render(j1);
        //j1->movimentar();

        pGrafico->display();        
    }

}

