#include "../include/Jogo.h"
using namespace std;


Gerenciadores::Gerenciador_Grafico* Jogo::pGrafico = Gerenciadores::Gerenciador_Grafico::getInstance();
Gerenciadores::Gerenciador_Eventos* Jogo::pEventos = Gerenciadores::Gerenciador_Eventos::getInstance();

Jogo::Jogo(): gamestate(0), rodando(true), menuPrincipal(this), lv1()
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

    while(rodando)
    {
        executar();
    }
    
}

Jogo::~Jogo()
{
    pGrafico->deletarInstance();
    pEventos->deletarInstance();
    
    std::cout << "Jogo fechou!" << std::endl;
}

void Jogo::executar()
{
    if(!pGrafico->isWindowOpen())
        rodando = false;

    pGrafico->executar();
    pEventos->executar();
        
    switch (gamestate)
        {
        case 0:
            menuPrincipal.executar();
            break;
        case 1:
            lv1.executar();
            break;
        case 3:
            rodando = false;
            break;
    }

    pGrafico->display(); 
        
    }






