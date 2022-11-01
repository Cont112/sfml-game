#pragma once

#include "Ente.h"
#include "iostream"

class Menu: public Ente 
{
private:
    const char* title;

public:
    Menu();
    ~Menu();

    void executar()override;
    void imprimir_se()override;
};