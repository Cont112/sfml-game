#pragma once 
#include"Gerenciadores/Gerenciador_Grafico.h"
#include "iostream"

class Ente{

protected:
    int id;
    static int num_ente;
    static Gerenciadores::Gerenciador_Grafico* pGrafico;
    sf::RectangleShape shape;

public:
    Ente();
    ~Ente();
    void setId(int i);
    
    virtual void atualizar()=0;
    void imprimir_se();
    sf::RectangleShape getShape() const;
    void setTextura(sf::Texture* texture);



};