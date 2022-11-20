#include "../include/Ente.h"

Gerenciadores::Gerenciador_Grafico* Ente::pGrafico = Gerenciadores::Gerenciador_Grafico::getInstance();

Ente::Ente(const IDs ID): ID(ID), shape()
{
    std::cout << "Ente criado!" << std::endl;
}

Ente::~Ente(){
}

const IDs Ente::getID() const 
{
    return ID;
}

sf::RectangleShape Ente::getShape() const
{
    return shape;
}

void Ente::setTextura(sf::Texture* texture)
{
    shape.setTexture(texture);
}
void Ente::imprimir_se()
{
    pGrafico->render(shape);
}