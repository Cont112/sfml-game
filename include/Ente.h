#pragma once 
#include"Gerenciadores/Gerenciador_Grafico.h"
#include "IDs.h"
#include "iostream"

class Ente{

protected:
    static Gerenciadores::Gerenciador_Grafico* pGrafico;
    sf::RectangleShape shape;
    const IDs ID;

public:
    Ente(const IDs ID);
    ~Ente();

    virtual void atualizar()=0;
    virtual void imprimir_se();

    const IDs getID() const;
    sf::RectangleShape getShape() const;
    void setTextura(sf::Texture* texture);



};