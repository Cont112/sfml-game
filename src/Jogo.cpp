#include "../include/Jogo.h"
using namespace std;


Gerenciadores::Gerenciador_Grafico* Jogo::pGrafico = Gerenciadores::Gerenciador_Grafico::getInstance();
Gerenciadores::Gerenciador_Eventos* Jogo::pEventos = Gerenciadores::Gerenciador_Eventos::getInstance();

Jogo::Jogo(): gamestate(0)
{
    executar();
}

Jogo::~Jogo()
{
    pGrafico->deletarInstance();
    pEventos->deletarInstance();
    if(pColisao)
        delete pColisao;
    
    delete lista;
    delete j1;
    std::cout << "Jogo fechou!" << std::endl;
}

void Jogo::executar()
{
    criarEntidades();
    pColisao = new Gerenciadores::Gerenciador_Colisoes(listaMoveis, listaFixos);
    pEventos->setJogador(j1);

    //loop principal 
    while(pGrafico->isWindowOpen())
    {
        pGrafico->executar();
        pEventos->executar();
        lista->atualizar();
        pColisao->executar();    
        pGrafico->display(); 
        
    }


}
void Jogo:: criarEntidades()
{
    //criando entidades
    j1 = new  Entidades::Personagens::Jogador (sf::Vector2f(50.0f,500.f),sf::Vector2f(60.f,60.f),IDs::jogador);
    Entidades::Personagens::Inimigos::Esqueleto* i1 = new Entidades::Personagens::Inimigos::Esqueleto(sf::Vector2f(640.0f,500.0f), j1);
    Entidades::Personagens::Inimigos::Mago* i2 = new Entidades::Personagens::Inimigos::Mago(sf::Vector2f(500.f,500.f),j1);
    Entidades::Obstaculos::Plataforma* chao = new Entidades::Obstaculos::Plataforma(sf::Vector2f(640.0f,700.0f));
    Entidades::Obstaculos::Caixa* caixa = new Entidades::Obstaculos::Caixa(sf::Vector2f(300.0f,200.0f));
    
    lista = new Listas::Lista_Entidades();
    listaMoveis = new Listas::Lista_Entidades();
    listaFixos = new Listas::Lista_Entidades();


    //listando entidades
    Entidades::Entidade *e1 = static_cast<Entidades::Entidade*>(j1);
    Entidades::Entidade *e2 = static_cast<Entidades::Entidade*>(i1);
    Entidades::Entidade *e3 = static_cast<Entidades::Entidade*>(i2);
    Entidades::Entidade *e4 = static_cast<Entidades::Entidade*>(chao);
    Entidades::Entidade *e5 = static_cast<Entidades::Entidade*>(caixa);

    lista->addEntidade(e1);
    lista->addEntidade(e2);
    lista->addEntidade(e3);
    lista->addEntidade(e4);
    lista->addEntidade(e5);

    listaMoveis->addEntidade(e1);
    listaMoveis->addEntidade(e2);
    listaFixos->addEntidade(e3);
    listaFixos->addEntidade(e4);
    listaFixos->addEntidade(e5);
}

