#pragma once

#include "Entidades/Personagens/Jogador.h"
#include "Gerenciadores/Gerenciador_Grafico.h"
#include "Ente.h"
#include <vector>


class Jogo
{
private:

    Entidades::Personagens::Jogador j1;
    Gerenciadores::Gerenciador_Grafico* pGrafico;


public:
    Jogo();
    ~Jogo();

    void executar();
};