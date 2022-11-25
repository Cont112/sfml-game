#include "../include/Jogo.h"
using namespace std;


Gerenciadores::Gerenciador_Grafico* Jogo::pGrafico = Gerenciadores::Gerenciador_Grafico::getInstance();
Gerenciadores::Gerenciador_Eventos* Jogo::pEventos = Gerenciadores::Gerenciador_Eventos::getInstance();

Jogo::Jogo(): gamestate(0), fase(nullptr)
{
    if (pGrafico ==  nullptr)
    {
        cout<<"ponteiro grafico vazio, Jogo.cpp"<<endl;
        exit(1);
    }
    if (pEventos == nullptr)
    {
        cout<<"ponteiro grafico nulo"<<endl;
        exit(1);
    }
    
    
    criarFase(1, 1);//ESCOLHE AQUI A FASE E NUMERO DE PLAYERS
    executar();
}

Jogo::~Jogo()
{
    pGrafico->deletarInstance();
    pEventos->deletarInstance();
    
    std::cout << "Jogo fechou!" << std::endl;
}

void Jogo::executar()
{

    //loop principal 
    while(pGrafico->isWindowOpen())
    {
        pEventos->executar();
        pGrafico->executar();
        fase->executar();
        pGrafico->display(); 
        
    }


}

void Jogo::criarFase(int tipoFase, bool player2)
{
    
    if (tipoFase == 1)
    {
        Fases::Bosque *aux = new Fases::Bosque;
        fase = static_cast<Fases::Fase*>(aux);
        if (aux == nullptr)
        {
            std::cout<<"erro ao criar fase"<<std::endl;
            exit (1);
        } 
    }
    else 
    {
        Fases::Castelo *aux = new Fases::Castelo;
        fase = static_cast<Fases::Fase*>(aux);
        if (aux == nullptr)
        {
            std::cout<<"erro ao criar fase"<<std::endl;
            exit (1);
        }
    }
    
    if (player2)
        fase->doisJogadores();
    
    fase->criarFundo();
    fase->criarMapa();
}


