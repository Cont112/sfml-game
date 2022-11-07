#pragma once

#include "Gerenciadores/Gerenciador_Grafico.h"

class Ente
{
protected:
    int id;
    Gerenciadores::Gerenciador_Grafico* pGrafico;
    static int idCount;

public:
    Ente();
    ~Ente();
    virtual void executar() = 0;
    virtual void imprimir_se() = 0;

};