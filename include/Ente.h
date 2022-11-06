#pragma once 
#include"Gerenciadores/Gerenciador_Grafico.h"

class Ente{

protected:
    int id;
    Gerenciadores::Gerenciador_Grafico *pGra;

public:
    Ente(Gerenciadores::Gerenciador_Grafico *p = nullptr);
    ~Ente();
    void setId(int i);
    
    //virtual void executar()=0;
    //virtual void imprimir_se()=0;



};