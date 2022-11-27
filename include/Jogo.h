#pragma once
#include "../stdafx.h"


class Jogo
{
private:
    static Gerenciadores::Gerenciador_Grafico* pGrafico;
    static Gerenciadores::Gerenciador_Eventos* pEventos;

    int gamestate;
    int lastGamestate;
    bool rodando;

    Menus::Menu_Principal menu_principal;
    Menus::Menu_Fases menu_fases;
    Menus::Menu_Pause menu_pause;
    Menus::Menu_Jogadores menu_jogadores;
    Menus::Menu_Gameover menu_gameover;
    Fases::Bosque lv1;
    Fases::Castelo lv2;

    Entidades::Personagens::Jogador j1;
    Entidades::Personagens::Jogador j2;

    float dtAux;

    
public:
    Jogo();
    ~Jogo();

    void setGameState(int g);
    int getGameState();
    int getLastGameState();
    Fases::Fase* getFase(const IDs ID);
    void checarGameover();

    void executar();
};