#pragma once

#include "Menu.h"
#include "Fases/Fase1.h"
//#include "Fases/Fase2.h"
#include "Gerenciadores/Graficos.h"
#include <vector>


class Jogo
{
private:
    Menu menu;
    Gerenciadores::Graficos* pGrafico;
    bool isRunning;


public:
    Jogo();
    ~Jogo();

    void executar();
};