#pragma once
#include "../stdafx.h"


class Jogo
{
private:
    int gamestate;
    Fases::Fase *fase1;
    static Gerenciadores::Gerenciador_Grafico* pGrafico;
    void criarFase();
    


public:
    Jogo();
    ~Jogo();
    void executar();
};