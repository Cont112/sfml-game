#pragma once

#include "Entidades/Personagens/Jogador.h"
#include "Gerenciadores/Graficos.h"


class Jogo {
private:

    Gerenciadores::Graficos* pGrafico;

public:
    Jogo();
    ~Jogo();

    void executar();
};