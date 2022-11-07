#pragma once 
#include"Gerenciadores/Gerenciador_Grafico.h"

class Ente{

protected:
    int id;
    Gerenciadores::Gerenciador_Grafico *pGra;
    sf::RectangleShape shape;

public:
    Ente();
    ~Ente();
    void setId(int i);
    
    //virtual void executar()=0;
    virtual void imprimir_se()=0;



};