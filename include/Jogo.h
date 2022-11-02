#pragma once

#include "Menu.h"
#include "Fases/Fase1.h"
//#include "Fases/Fase2.h"
#include "Entidades/Personagens/Jogador.h"
#include "Gerenciadores/Graficos.h"
#include <vector>


class Jogo
{
private:
    Menu menu;
    Gerenciadores::Graficos* pGrafico;
    Entidades::Personagens::Jogador* j1;


public:
    Jogo();
    ~Jogo();

    void executar();
};