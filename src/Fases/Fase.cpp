#include "../../include/Fases/Fase.h"

using namespace Entidades::Personagens;
using namespace Entidades::Obstaculos;

namespace Fases{

    Fase::Fase(): Ente(ID), fundo(),listaPersonagens(new Listas::Lista_Entidades), listaObstaculos(new Listas::Lista_Entidades), 
                  pColisao(new Gerenciadores::Gerenciador_Colisoes(listaObstaculos, listaPersonagens)),
                  pGrafico(Gerenciadores::Gerenciador_Grafico::getInstance())
    {
        if (pColisao == NULL)
        {
            std::cout << "Fase: Nao foi possivel criar o gerenciador de colisoes" << std::endl;
            exit(1);
        }

        const char* fundo = "assets/nskybox.jpg";
        pGrafico->createTexture(fundo);

        
    }

    Fase::~Fase() 
    {
        if(pColisao){
            delete(pColisao);
            pColisao = nullptr;
        }

        listaObstaculos->limparLista();
        listaPersonagens->limparLista();
    }

    void Fase::gerenciar_colisoes() 
    {
        pColisao->executar();
    }
    
    void Fase::criarPlataforma(const sf::Vector2f pos)
    {        
        Entidades::Obstaculos::Plataforma *plataforma = new Entidades::Obstaculos::Plataforma (sf::Vector2f(pos.x*50.f, pos.y*50.f));
        
        if (plataforma==nullptr)
        {
            std::cout<<"Erro ao criar plataforma"<<std::endl;
            exit(1);
        }

        listaPersonagens->addEntidade(static_cast<Entidades::Entidade*>(plataforma));      
    }
    
    void Fase::criarInimigo(const sf::Vector2f pos)
    {
        Entidades::Personagens::Inimigo *inimigo = new Entidades::Personagens::Inimigo (sf::Vector2f(pos.x*50.f, pos.y*50.f), sf::Vector2f(100, 100), getJogador(),IDs::inimigo);
        
        if (inimigo==nullptr)
        {
            std::cout<<"Erro ao criar inimigo"<<std::endl;
            exit(1);
        }

        listaPersonagens->addEntidade(static_cast<Entidades::Entidade*>(inimigo));

    }
    
    void Fase::criarJogador(const sf::Vector2f pos)
    {
       Entidades::Personagens::Jogador *jogador1 = new Entidades::Personagens::Jogador(sf::Vector2f(pos.x*50.f, pos.y*50.f), sf::Vector2f(100, 100), IDs::jogador);
        
        if (jogador1==nullptr)
        {
            std::cout<<"Erro ao criar jogador"<<std::endl;
            exit(1);
        }

        listaPersonagens->addEntidade(static_cast<Entidades::Entidade*>(jogador1));

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
            criarJogador(pos);
        }
            break;
        case ('i'):
        {
            criarInimigo(pos);
        }
            break;
        case('p'):
        {
            criarPlataforma(pos);
        }
            break;
        
        case('c'):
        {
            criarCaixa(pos);
        }
            break;

        default:
            break;
        }
    }

    Entidades::Personagens::Jogador* Fase::getJogador()
    {
        for (int i = 0 ; i<listaPersonagens->getTamanho();i++)
            if(listaPersonagens->operator[](i)->getID()==IDs::jogador)
                return (static_cast<Entidades::Personagens::Jogador*>(listaPersonagens->operator[](i)));
    }
    
    void Fase::gerenciar_colisoes()
    {
        pColisao->setListas(listaPersonagens, listaObstaculos);
        pColisao->executar();
    }
    
    void Fase::executar()
    {
        desenhar();
        pColisao->executar();        
    }
    
    void Fase::desenhar()
    {
        listaPersonagens->atualizar();
        listaObstaculos->atualizar();
    }

}
