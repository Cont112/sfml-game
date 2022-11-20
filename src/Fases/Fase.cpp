#include "../../include/Fases/Fase.h"


using namespace Entidades::Personagens;
using namespace Entidades::Obstaculos;

namespace Fases{

    Fase::Fase(): Ente(),                  
                  pGrafico(Gerenciadores::Gerenciador_Grafico::getInstance()), 
                  listaObstaculos(), listaPersonagens(),
                  pColisao(new Gerenciadores::Gerenciador_Colisoes())
    {
        if(pColisao == nullptr){
            std::cout << "Fase::nao foi possivel criar um Gerenciador de Colisao" << std::endl;
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
        Obstaculo *obstaculo = new Obstaculo();
        const char* obs1 = "assets/index.jpeg";
        obstaculo->setTamanho(sf::Vector2f (100.f, 20.f));
        pGrafico->createTexture(obs1);
        obstaculo->setTextura(pGrafico->textureMap.at(obs1));
        obstaculo->setTipo(3);
        obstaculo->getShape().setPosition(pos);

        if (obstaculo==nullptr)
        {
            std::cout<<"Plataforma nula, problema. Fase::criarPlataforma"<<std::endl;
            exit(1);
        }
        
        
        listaObstaculos.addEntidade(static_cast<Entidades::Entidade*> (obstaculo));
        
    }
    
    void Fase::criarInimigo(const sf::Vector2f pos)
    {
        Inimigo *inimigo1 = new Inimigo();
        const char* ini1 = "assets/inimigo.png";
        pGrafico->createTexture(ini1);
        inimigo1->setTextura(pGrafico->textureMap.at(ini1));
        inimigo1->setTipo(2);
        inimigo1->getShape().setPosition(pos);
        inimigo1->setJog1(static_cast<Entidades::Personagens::Jogador*>(listaPersonagens.operator[](0)));

        if (inimigo1==nullptr)
        {
            std::cout<<"Inimigo nul, problema. Fase::criarInimigo"<<std::endl;
            exit(1);
        }
        
        
        listaPersonagens.addEntidade(static_cast<Entidades::Entidade*> (inimigo1));


    }
    
    void Fase::criarJogador(const sf::Vector2f pos)
    {
        Jogador *jogador1 = new Jogador();
        const char* jog = "assets/jogador.png";
        pGrafico->createTexture(jog);
        jogador1->setTextura(pGrafico->textureMap.at(jog));
        jogador1->setTipo(1);
        jogador1->getShape().setPosition(pos);

        if (jogador1==nullptr)
        {
            std::cout<<"Jogador nulo, problema. Fase::criarJogador"<<std::endl;
            exit(1);
        }
        
        
        listaPersonagens.addEntidade(static_cast<Entidades::Entidade*> (jogador1));

    }
    
    void Fase::criarCaixa(const sf::Vector2f pos)
    {
        Obstaculo *caixa = new Obstaculo();
        const char* cai = "assets/barreto.jpg";
        caixa->setTamanho(sf::Vector2f (20.f, 20.f));
        pGrafico->createTexture(cai);
        caixa->setTextura(pGrafico->textureMap.at(cai));
        caixa->getShape().setPosition(pos);
        
        if (caixa==nullptr)
        {
            std::cout<<"Caixa nula, problema. Fase::criarCaixa"<<std::endl;
            exit(1);
        }
        
        
        listaObstaculos.addEntidade(static_cast<Entidades::Entidade*> (caixa)); 
    }
    
    void Fase::criarEntidade(const sf::Vector2f pos)
    {
        //descobrir se precisa
    }
    
    void Fase::gerenciar_colisoes()
    {
        pColisao->setListas(&listaPersonagens, &listaObstaculos);
        std::cout<<"setei listas"<<std::endl;
        pColisao->executar();
        std::cout<<"executou pColisao!"<<std::endl;
    }
    
    void Fase::executar()
    {
        pGrafico->loadTextures();
        
        desenhar();
        
        gerenciar_colisoes(); 
    }
    
    void Fase::desenhar()
    {
        //pGrafico->render(fundoTela);
        //std::cout<<"renderizei fundo!"<<std::endl;

        listaPersonagens.executar();
        std::cout<<"executei listaPrsonagens!"<<std::endl;
        
        listaObstaculos.executar();
        std::cout<<"executei listaObstaculos!"<<std::endl;
    }
    
    void Fase::setPColisao(Gerenciadores::Gerenciador_Colisoes* g)
    {
        pColisao = g;
    }

    Listas::Lista_Entidades* Fase:: getListaPersonagens()
    {
        return &listaPersonagens;
    }
    
    Listas::Lista_Entidades* Fase:: getListaObstaculos()
    {
        return &listaObstaculos;
    }


}
