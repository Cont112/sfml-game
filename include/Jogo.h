#pragma once

#include "Ente.h"
#include "Entidades/Entidade.h"
#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Personagens/Personagem.h"
#include "Listas/Lista.h"
#include "Gerenciadores/Graficos.h"
#include <vector>


class Jogo
{
private:
    Gerenciadores::Graficos* pGrafico;

public:
    Jogo();
    ~Jogo();

    void executar();
};