#include "../../include/Fases/Fase.h"

using namespace Entidades::Personagens;
using namespace Entidades::Obstaculos;

namespace Fases{

    Fase::Fase(): Ente(ID), fundo(),listaPersonagens(), listaObstaculos(), 
                  pColisao(new Gerenciadores::Gerenciador_Colisoes(&listaObstaculos, &listaPersonagens)),
                  pGrafico(Gerenciadores::Gerenciador_Grafico::getInstance())
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

        listaPersonagens.addEntidade(static_cast<Entidades::Entidade*>(plataforma));      
    }
    
    void Fase::criarInimigo(const sf::Vector2f pos)
    {
        Gerenciadores::Gerenciador_Eventos *pEvento = pEvento->getInstance();
        Entidades::Personagens::Jogador* jogador = pEvento->getJogador();
        
        Entidades::Personagens::Inimigo *inimigo = new Entidades::Personagens::Inimigo (pos, sf::Vector2f(100, 100), jogador,IDs::inimigo);

        if (inimigo==nullptr)
        {
            std::cout<<"Erro ao criar inimigo"<<std::endl;
            exit(1);
        }

        listaPersonagens.addEntidade(static_cast<Entidades::Entidade*>(inimigo));

    }
    
    void Fase::criarJogador(const sf::Vector2f pos)
    {
       Entidades::Personagens::Jogador *jogador1 = new Entidades::Personagens::Jogador(pos, sf::Vector2f(100, 100), IDs::jogador);
        
        if (jogador1==nullptr)
        {
            std::cout<<"Erro ao criar jogador"<<std::endl;
            exit(1);
        }

        listaPersonagens.addEntidade(static_cast<Entidades::Entidade*>(jogador1));
        Gerenciadores::Gerenciador_Eventos *pEvento = pEvento->getInstance();
        pEvento->setJogador(jogador1);
    }
    
    void Fase::criarCaixa(const sf::Vector2f pos)
    {
       
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
        case ('i'):
        {
            criarInimigo(sf::Vector2f(pos.x *50.f, pos.y *50.f));
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
        desenhar();
        pColisao->executar();        
    }
    
    void Fase::desenhar()
    {
        listaPersonagens.atualizar();
        listaObstaculos.atualizar();
    }

    void Fase::atualizar()
    {

    }

}
