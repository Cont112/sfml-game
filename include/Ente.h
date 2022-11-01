#pragma once

#include "Gerenciadores/Graficos.h"

class Ente {
protected:
    int id;
    Gerenciadores::Graficos* pGrafico;
    
public:
    Ente();
    ~Ente();

    
    virtual void executar() = 0;
    virtual void imprimir_se();
    
};