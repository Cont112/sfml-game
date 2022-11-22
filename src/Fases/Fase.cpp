#include "../../include/Fases/Fase.h"

using namespace Entidades::Personagens;
using namespace Entidades::Obstaculos;

namespace Fases{

Gerenciadores::Gerenciador_Grafico* Fase::pGrafico = Gerenciadores::Gerenciador_Grafico::getInstance();
Gerenciadores::Gerenciador_Eventos* Fase::pEventos = Gerenciadores::Gerenciador_Eventos::getInstance();

    Fase::Fase(): Ente(ID), fundo(),listaPersonagens(), listaObstaculos(), 
                  pColisao(new Gerenciadores::Gerenciador_Colisoes(&listaPersonagens, &listaObstaculos))
    {
        if (pColisao == NULL)
        {
            std::cout << "Fase: Nao foi possivel criar o gerenciador de colisoes" << std::endl;
            exit(1);
        }
        
    }

    Fase::~Fase() 
    {
        if(pColisao){
            delete(pColisao);
            pColisao = nullptr;
        }

        listaObstaculos.limparLista();
        listaPersonagens.limparLista();
    }
    
    void Fase::criarPlataforma(const sf::Vector2f pos)
    {        
        Entidades::Obstaculos::Plataforma *plataforma = new Entidades::Obstaculos::Plataforma (pos);
        
        if (plataforma==nullptr)
        {
            std::cout<<"Erro ao criar plataforma"<<std::endl;
            exit(1);
        }

        listaObstaculos.addEntidade(static_cast<Entidades::Entidade*>(plataforma));      
    }
    
    void Fase::criarMago(const sf::Vector2f pos)
    {
        Entidades::Personagens::Jogador* jogador = pEventos->getJogador();
        
        Entidades::Personagens::Inimigos::Mago *mago = new Entidades::Personagens::Inimigos::Mago (pos, jogador);

        if (mago==nullptr)
        {
            std::cout<<"Erro ao criar mago"<<std::endl;
            exit(1);
        }

        listaPersonagens.addEntidade(static_cast<Entidades::Entidade*>(mago));

    }
    
    void Fase::criarEsqueleto(const sf::Vector2f pos)
    {
        Entidades::Personagens::Jogador* jogador = pEventos->getJogador();
        
        Entidades::Personagens::Inimigos::Esqueleto *esqueleto = new Entidades::Personagens::Inimigos::Esqueleto (pos, jogador);

        if (esqueleto==nullptr)
        {
            std::cout<<"Erro ao criar esqueleto"<<std::endl;
            exit(1);
        }

        listaPersonagens.addEntidade(static_cast<Entidades::Entidade*>(esqueleto));

    }
 
    void Fase::criarJogador(const sf::Vector2f pos)
    {
       Entidades::Personagens::Jogador *jogador1 = new Entidades::Personagens::Jogador(pos, sf::Vector2f(48.f, 48.f), IDs::jogador);
        
        if (jogador1==nullptr)
        {
            std::cout<<"Erro ao criar jogador"<<std::endl;
            exit(1);
        }

        listaPersonagens.addEntidade(static_cast<Entidades::Entidade*>(jogador1));
        pEventos->setJogador(jogador1);
    }
    
    void Fase::criarCaixa(const sf::Vector2f pos)
    {
       Entidades::Obstaculos::Caixa *caixa = new Entidades::Obstaculos::Caixa(pos);

       if(caixa == nullptr)
       {
        std::cout<<"erro ao criar caixa"<<std::endl;
        exit(1);
       }

       listaObstaculos.addEntidade(static_cast<Entidades::Entidade*>(caixa));

    }
    
    void Fase::criarEntidade( char letra,const sf::Vector2f pos)
    {
        switch (letra)
        {
        case ('j'):
        {
            criarJogador(sf::Vector2f(pos.x *50.f, pos.y *50.f));
        }
            break;
        case ('m'):
        {
            criarMago(sf::Vector2f(pos.x *50.f, pos.y *50.f));
        }
            break;
        case ('e'):
        {
            criarEsqueleto(sf::Vector2f(pos.x *50.f, pos.y *50.f));
        }
            break;
        case('p'):
        {
            criarPlataforma(sf::Vector2f(pos.x *50.f, pos.y *50.f));
        }
            break;
        
        case('c'):
        {
            criarCaixa(sf::Vector2f(pos.x *50.f, pos.y *50.f));
        }
            break;

        default:
            break;
        }
    }
    
    void Fase::executar()
    {
        pGrafico->render(fundo);
        atualizar();
        pColisao->executar();        
    }
    
    void Fase::atualizar()
    {
        listaPersonagens.atualizar();
        listaObstaculos.atualizar();
    }

}
