#pragma once

#include "Ente.h"

class Menu: public Ente 
{
private:
    const char* title;

public:
    Menu();
    ~Menu();

    void executar()override;
};