#pragma once

#include "Entidades/Entidade.h"
#include "Gerenciadores/Graficos.h"
#include <vector>


class Jogo {
private:

    Gerenciadores::Graficos* pGrafico;

public:
    Jogo();
    ~Jogo();

    void executar();
};