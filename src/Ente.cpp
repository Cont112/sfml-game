#include "../include/Ente.h"

Gerenciadores::Gerenciador_Grafico* Ente::pGrafico = Gerenciadores::Gerenciador_Grafico::getInstance();
Ente::Ente(): shape(){
        
}

Ente::~Ente(){
}
void Ente::setId(int i)
{
    id = i;
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