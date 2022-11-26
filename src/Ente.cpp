#include "../include/Ente.h"

Gerenciadores::Gerenciador_Grafico* Ente::pGrafico = Gerenciadores::Gerenciador_Grafico::getInstance();

Ente::Ente(const IDs ID): ID(ID), shape()
{
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

void Ente::setTextura(const char* path)
{
    pGrafico->createTexture(path);
    shape.setTexture(pGrafico->textureMap.at(path));
}
void Ente::imprimir_se()
{
    pGrafico->render(shape);
}