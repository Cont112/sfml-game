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
    //criando texturas
    const char* ini1 = "assets/inimigo.png";
    const char* sky1 = "assets/nskybox.jpg";

    //criando entidades
    j1 = new  Entidades::Personagens::Jogador (sf::Vector2f(50.0f,500.f),sf::Vector2f(100.f,100.f),IDs::jogador);
    Entidades::Personagens::Inimigo* i1 = new  Entidades::Personagens::Inimigo (sf::Vector2f(640.0f,500.f), sf::Vector2f(100.f,100.f), j1 ,IDs::esqueleto);
    Entidades::Obstaculos::Plataforma* chao = new Entidades::Obstaculos::Plataforma(sf::Vector2f(0.0f,700.0f));
   //Entidades::Obstaculos::Obstaculo* sky = new Entidades::Obstaculos::Obstaculo(sf::Vector2f(0.0f,0.0f), sf::Vector2(WIDTH, HEIGHT), sky1, IDs::caixa);
    
    lista = new Listas::Lista_Entidades();
    listaMoveis = new Listas::Lista_Entidades();
    listaFixos = new Listas::Lista_Entidades();



    pGrafico->createTexture(ini1);

    i1->setTextura(pGrafico->textureMap.at(ini1));


    //listando entidades
    Entidades::Entidade *e1 = static_cast<Entidades::Entidade*>(j1);
    Entidades::Entidade *e2 = static_cast<Entidades::Entidade*>(i1);
    Entidades::Entidade *e3 = static_cast<Entidades::Entidade*>(chao);

    lista->addEntidade(e1);
    lista->addEntidade(e2);
    lista->addEntidade(e3);

    listaMoveis->addEntidade(e1);
    listaMoveis->addEntidade(e2);
    listaFixos->addEntidade(e3);
}

