#pragma once

#include "Entidades/Personagens/Jogador.h"
#include "Gerenciadores/Graficos.h"


class Jogo {
private:

    Gerenciadores::Graficos* pGerenciadorGrafico;
    Entidades::Personagens::Jogador j1;

public:
    Jogo();
    ~Jogo();

    void executar();
};