#include "../../include/Fases/Fase.h"

using namespace Entidades::Personagens;
using namespace Entidades::Obstaculos;

namespace Fases{

Gerenciadores::Gerenciador_Grafico* Fase::pGrafico = Gerenciadores::Gerenciador_Grafico::getInstance();
Gerenciadores::Gerenciador_Eventos* Fase::pEventos = Gerenciadores::Gerenciador_Eventos::getInstance();

    Fase::Fase(const IDs ID): Ente(ID),listaPersonagens(), listaObstaculos(), player2(false),
                  pColisao(new Gerenciadores::Gerenciador_Colisoes(&listaPersonagens, &listaObstaculos)), ativo(0)
    {
        if (pColisao == NULL)
        {
            std::cout << "Fase: Nao foi possivel criar o gerenciador de colisoes" << std::endl;
            exit(1);
        }
        shape.setOrigin(sf::Vector2f(0.0f,0.0f));
        shape.setPosition(sf::Vector2f(0.0f,0.0f));
        shape.setSize((sf::Vector2f)pGrafico->getWindow()->getSize());

    }

    Fase::~Fase() 
    {
        if(pColisao){
            delete(pColisao);
            pColisao = nullptr;
        }
    }
    
    void Fase::criarPlataforma(const sf::Vector2f pos, bool v)
    {        
        Entidades::Obstaculos::Plataforma *plataforma = new Entidades::Obstaculos::Plataforma (pos,v);
        
        if (plataforma==nullptr)
        {
            std::cout<<"Erro ao criar plataforma"<<std::endl;
            exit(1);
        }

        listaObstaculos.addEntidade(static_cast<Entidades::Entidade*>(plataforma));      
    }
    
    void Fase::criarMago(const sf::Vector2f pos)
    {
        Entidades::Personagens::Jogador* jogador = pEventos->getJogador(true);
        
        Entidades::Personagens::Inimigos::Mago *mago = new Entidades::Personagens::Inimigos::Mago (pos, jogador, &listaObstaculos);

        if (mago==nullptr)
        {
            std::cout<<"Erro ao criar mago"<<std::endl;
            exit(1);
        }

        listaPersonagens.addEntidade(static_cast<Entidades::Entidade*>(mago));

    }
    
    void Fase::criarEsqueleto(const sf::Vector2f pos)
    {
        Entidades::Personagens::Jogador* jogador = pEventos->getJogador(true);
        
        Entidades::Personagens::Inimigos::Esqueleto *esqueleto = new Entidades::Personagens::Inimigos::Esqueleto (pos, jogador, DANO_ESQUELETO);

        if (esqueleto==nullptr)
        {
            std::cout<<"Erro ao criar esqueleto"<<std::endl;
            exit(1);
        }

        listaPersonagens.addEntidade(static_cast<Entidades::Entidade*>(esqueleto));

    }

    void Fase::criarCavaleiro(const sf::Vector2f pos)
    {
        Entidades::Personagens::Jogador* jogador = pEventos->getJogador(true);

        Entidades::Personagens::Inimigos::Cavaleiro *cavaleiro = new Entidades::Personagens::Inimigos::Cavaleiro (pos, jogador, DANO_CAVALEIRO);
        if (cavaleiro==nullptr)
        {
            std::cout<<"Erro ao criar esqueleto"<<std::endl;
            exit(1);
        }

        listaPersonagens.addEntidade(static_cast<Entidades::Entidade*>(cavaleiro));

    }
 
    void Fase::setJogador1(Entidades::Personagens::Jogador* j)
    {
        j1 = j;
        listaPersonagens.addEntidade(static_cast<Entidades::Entidade*>(j1));
    }
    void Fase::setJogador2(Entidades::Personagens::Jogador* j)
    {
        j2 = j;
        listaPersonagens.addEntidade(static_cast<Entidades::Entidade*>(j2));
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
    
    void Fase::criarLava(const sf::Vector2f pos)
    {
        Entidades::Obstaculos::Lava *lava = new Entidades::Obstaculos::Lava(pos);

       if(lava == nullptr)
       {
        std::cout<<"erro ao criar caixa"<<std::endl;
        exit(1);
       }

       listaObstaculos.addEntidade(static_cast<Entidades::Entidade*>(lava));
    }

    void Fase::criarEntidade( char letra,const sf::Vector2f pos)
    {
        bool v = true;
        if(ID == IDs::bosque)
            v = false;
        
        switch (letra)
        {
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
            criarPlataforma(sf::Vector2f(pos.x *50.f, pos.y *50.f), v);
        }
            break;
        
        case('c'):
        {
            criarCaixa(sf::Vector2f(pos.x *50.f, pos.y *50.f));
        }
            break;
        case('k'):
        {
            criarCavaleiro(sf::Vector2f(pos.x*50.f, pos.y*50.f));
        }

        case ('l'):
        {
            criarLava(sf::Vector2f(pos.x *50.f, pos.y *50.f));
        }
            break;

        default:
            break;
        }
    }

    void Fase::doisJogadores(bool j)
    {
        player2 = j;
    }
    
    bool Fase::getDoisJogadores()
    {
        return player2;
    }
    
    void Fase::executar()
    {
        imprimir_se();
        atualizar();
        pColisao->executar();        
    }
    
    void Fase::atualizar()
    { 
        listaPersonagens.atualizar();
        listaObstaculos.atualizar();
    }


}
