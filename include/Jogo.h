#pragma once
#include "../stdafx.h"
#include "Menus/Menu_Principal.h"



class Jogo
{
private:
    static Gerenciadores::Gerenciador_Grafico* pGrafico;
    static Gerenciadores::Gerenciador_Eventos* pEventos;

    int gamestate;
    bool rodando;

    Menus::Menu_Principal menuPrincipal;
    Fases::Bosque lv1;

    
public:
    Jogo();
    ~Jogo();

    void setGameState(int g) {gamestate = g;}
    int getGameState() {return gamestate;}

    void executar();
};