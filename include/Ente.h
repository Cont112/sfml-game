#pragma once

#include "Gerenciadores/Graficos.h"
#include <SFML/Graphics.hpp>

class Ente: public sf::Sprite {
protected:

    int id;
    Gerenciadores::Graficos* pGrafico;
    
public:
    Ente();
    ~Ente();

    
    virtual void executar() = 0;
    virtual void imprimir_se() = 0;

    
};