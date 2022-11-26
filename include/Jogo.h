#pragma once
#include "../stdafx.h"


class Jogo
{
private:
    static Gerenciadores::Gerenciador_Grafico* pGrafico;
    static Gerenciadores::Gerenciador_Eventos* pEventos;

    int gamestate;
    bool rodando;

    Menus::Menu_Principal menu_principal;
    Menus::Menu_Fases menu_fases;
    Fases::Bosque lv1;
    Fases::Castelo lv2;

    float dtAux;

    
public:
    Jogo();
    ~Jogo();

    void setGameState(int g);
    int getGameState();
    Fases::Fase* getFase(const IDs ID);

    void executar();
};