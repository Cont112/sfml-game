#pragma once
#include "../stdafx.h"


class Jogo
{
private:
    int gamestate;

    static Gerenciadores::Gerenciador_Grafico* pGrafico;
    static Gerenciadores::Gerenciador_Eventos* pEventos;

    void criarFase();
    Fases::Fase *fase;
    

    

public:
    Jogo();
    ~Jogo();
    void executar();
};