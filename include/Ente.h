#pragma once 
#include"Gerenciadores/Gerenciador_Grafico.h"

class Ente{

protected:
    int id;
    static Gerenciadores::Gerenciador_Grafico* pGrafico;
    sf::RectangleShape shape;

public:
    Ente();
    ~Ente();
    void setId(int i);
    
    virtual void executar()=0;
    void imprimir_se();
    sf::RectangleShape getShape() const;
    void setTextura(sf::Texture* texture);



};