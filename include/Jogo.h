#pragma once
#include "../stdafx.h"

#include "Menus/Botao/Botao.h"


class Jogo
{
private:
    int gamestate;

    static Gerenciadores::Gerenciador_Grafico* pGrafico;
    static Gerenciadores::Gerenciador_Eventos* pEventos;

    void criarFase(int tipoFase, bool player2);
    Fases::Fase *fase;

    
public:
    Jogo();
    ~Jogo();

    void setGameState(int g) {gamestate = g;}
    int getGameState() {return gamestate;}

    void executar();
};