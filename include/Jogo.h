#pragma once

#include "Jogador.h"
#include "Gerenciadores/Gerenciador_Grafico.h"
#include "Ente.h"
#include <vector>


class Jogo
{
private:

    Jogador j1;
    Gerenciadores::Gerenciador_Grafico* pGrafico;


public:
    Jogo();
    ~Jogo();

    void executar();
};