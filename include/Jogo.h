#pragma once

#include "Menu.h"
#include <vector>


class Jogo
{
private:
    Menu menu;


public:
    Jogo();
    ~Jogo();

    void executar();
};