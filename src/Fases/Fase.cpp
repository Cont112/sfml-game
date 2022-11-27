#include "../../include/Fases/Fase.h"

using namespace Entidades::Personagens;
using namespace Entidades::Obstaculos;

namespace Fases{

Gerenciadores::Gerenciador_Grafico* Fase::pGrafico = Gerenciadores::Gerenciador_Grafico::getInstance();
Gerenciadores::Gerenciador_Eventos* Fase::pEventos = Gerenciadores::Gerenciador_Eventos::getInstance();

    Fase::Fase(): Ente(ID),listaPersonagens(), listaObstaculos(), player2(false),
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
        Entidades::Personagens::Jogador* jogador = pEventos->getJogador(true);
        
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
        Entidades::Personagens::Jogador* jogador = pEventos->getJogador(true);
        
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
       Entidades::Personagens::Jogador *jogador1 = new Entidades::Personagens::Jogador(pos, sf::Vector2f(48.f, 48.f), false,IDs::jogador);
       jogador1->setAtividade(true);
        
        if (jogador1==nullptr)
        {
            std::cout<<"Erro ao criar jogador"<<std::endl;
            exit(1);
        }

        listaPersonagens.addEntidade(static_cast<Entidades::Entidade*>(jogador1));
        pEventos->setJogador(jogador1);
    }
    
    void Fase::criarJogador2(const sf::Vector2f pos)
    {
        Entidades::Personagens::Jogador *jogador2 = new Entidades::Personagens::Jogador(pos, sf::Vector2f(48.f, 48.f), true,IDs::jogador);
        jogador2->setAtividade(true);

        if (jogador2==nullptr)
        {
            std::cout<<"Erro ao criar jogador2"<<std::endl;
            exit(1);
        }

        listaPersonagens.addEntidade(static_cast<Entidades::Entidade*>(jogador2));
        pEventos->setJogador2(jogador2);
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
        switch (letra)
        {
        case ('j'):
        {
            criarJogador(sf::Vector2f(pos.x *50.f, pos.y *50.f));
        }
            break;
        case ('s'):
        {
            if (player2)
            {
                criarJogador2(sf::Vector2f(pos.x *50.f, pos.y *50.f));
            }    
                
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
    void Fase::setAtivo(bool a)
    {
        ativo = a;
        if(ativo)
        {
            for(int i =0; i < listaObstaculos.getTamanho(); i++)
            {
                listaObstaculos[i]->setAtividade(true);
            }
            for(int i =0; i < listaPersonagens.getTamanho(); i++)
            {
                listaPersonagens[i]->setAtividade(true);
            }
        }

        else{
            for(int i =0; i < listaObstaculos.getTamanho(); i++)
            {
                listaObstaculos[i]->setAtividade(false);
            }
            for(int i =0; i < listaPersonagens.getTamanho(); i++)
            {
                listaPersonagens[i]->setAtividade(false);
            }
        }
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
