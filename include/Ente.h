#pragma once

#include "Gerenciadores/Graficos.h"

class Ente {
protected:
    int id;
    Gerenciadores::Graficos* pGrafico;
    
public:
    Ente();
    ~Ente();

    
    virtual void executar() = 0 ;
    void imprimir_se();
    virtual void render() = 0;
};