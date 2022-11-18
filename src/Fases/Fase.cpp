#include "../../include/Fases/Fase.h"

using namespace Entidades::Personagens;
using namespace Entidades::Obstaculos;

namespace Fases{

    Fase::Fase(): Ente(), fundo(),listaPersonagens(new Listas::Lista_Entidades), listaObstaculos(new Listas::Lista_Entidades), 
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
        Obstaculo *obstaculo = new Obstaculo;
        const char* obs1 = "assets/index.jpeg";
        obstaculo->setTamanho(sf::Vector2f (100.f, 20.f));
        pGrafico->createTexture(obs1);
        obstaculo->setTextura(pGrafico->textureMap.at(obs1));
        obstaculo->setTipo(3);
        
        Entidades::Entidade *entidade = static_cast<Entidades::Entidade*> (obstaculo);
        listaObstaculos->addEntidade(entidade);
        
    }
    
    void Fase::criarInimigo(const sf::Vector2f pos)
    {
        Inimigo* inimigo1 = new Inimigo;
        const char* ini1 = "assets/inimigo.png";
        pGrafico->createTexture(ini1);
        inimigo1->setTextura(pGrafico->textureMap.at(ini1));
        inimigo1->setTipo(2);
        
        Entidades::Entidade *entidade = static_cast<Entidades::Entidade*> (inimigo1);
        listaPersonagens->addEntidade(entidade);


    }
    
    void Fase::criarJogador(const sf::Vector2f pos)
    {
        Jogador *jogador1 = new Jogador;
        const char* jog = "assets/jogador.png";
        pGrafico->createTexture(jog);
        jogador1->setTextura(pGrafico->textureMap.at(jog));
        jogador1->setTipo(1);
        
        Entidades::Entidade *entidade = static_cast<Entidades::Entidade*> (jogador1);
        listaPersonagens->addEntidade(entidade);

    }
    
    void Fase::criarCaixa(const sf::Vector2f pos)
    {
        Obstaculo *caixa = new Obstaculo;
        const char* cai = "assets/index.jpeg";
        caixa->setTamanho(sf::Vector2f (20.f, 20.f));
        pGrafico->createTexture(cai);
        caixa->setTextura(pGrafico->textureMap.at(cai));
        
        Entidades::Entidade *entidade = static_cast<Entidades::Entidade*> (caixa);
        listaObstaculos->addEntidade(entidade);
    }
    
    void Fase::criarEntidade(const sf::Vector2f pos)
    {
        //descobrir se precisa
    }
    
    void Fase::gerenciar_colisoes()
    {
        pColisao->setListas(listaPersonagens, listaObstaculos);
        pColisao->executar();
    }
    
    void Fase::executar()
    {
        pGrafico->loadTextures();
        desenhar();
        pColisao->executar();        
    }
    
    void Fase::desenhar()
    {
        pGrafico->render(fundo);
        listaPersonagens->executar();
        listaObstaculos->executar();
    }


}
