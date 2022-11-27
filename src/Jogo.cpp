#include "../include/Jogo.h"
using namespace std;


Gerenciadores::Gerenciador_Grafico* Jogo::pGrafico = Gerenciadores::Gerenciador_Grafico::getInstance();
Gerenciadores::Gerenciador_Eventos* Jogo::pEventos = Gerenciadores::Gerenciador_Eventos::getInstance();

Jogo::Jogo(): gamestate(0), rodando(true),j1(false),j2(true) ,
menu_principal(this), menu_fases(this), menu_pause(this), menu_jogadores(this), menu_gameover(this),lv1(), lv2(),dtAux(0.0f)
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

    pEventos->setJogo(this);
    pEventos->setJogador2(&j2);
    pEventos->setJogador(&j1);
    while(rodando)
    {
        executar();
    }
    
}

Jogo::~Jogo()
{
    pGrafico->deletarInstance();
    pEventos->deletarInstance(); 
}

/* Gamestates:
0: Menu Principal
1: Menu Jogadores
2: Menu Fases
3: Menu Pausa
4: Fase 1
5: Fase 2
6: Gameover
7: Fechar */
void Jogo::executar()
{
    if(!pGrafico->isWindowOpen())
        rodando = false;
   

    pGrafico->executar();
    pEventos->executar();

    switch (gamestate)
        {
        case 0:
            menu_principal.executar();
            break;
        case 1:
            menu_jogadores.executar();
            break;
        case 2:
            menu_fases.executar();
            break;
        case 3:
            menu_pause.executar();
            break;
        case 4:
            checarGameover();
            lv1.executar();
            break;
        case 5:
            checarGameover();
            lv2.executar();
            break;
        case 6:
            menu_gameover.executar();
            break;
        case 7:
            rodando = false;
            break;
    }

    pGrafico->display(); 

    dtAux += pGrafico->getDt();
    if(dtAux >= 1.5f)
    {
        Menus::Menu::setCooldown(false);
        dtAux = 0.0f;
    }
}

void Jogo::checarGameover()
{
    if(!(j1.getAtividade()) && !(j2.getAtividade()))
    {
        setGameState(6);
    }
}

int Jogo::getGameState()
{
    return gamestate;
}

void Jogo::setGameState(int g)
{
    lastGamestate = gamestate;
    gamestate = g;
}

Fases::Fase* Jogo::getFase(IDs ID)
{
    if (ID == IDs::bosque)
    {
        return dynamic_cast<Fases::Fase*>(&lv1);
    } else if (ID == IDs::castelo)
    {
        return dynamic_cast<Fases::Fase*>(&lv2);
    }

    else
        return nullptr;
}

int Jogo::getLastGameState()
{
    return lastGamestate;
}