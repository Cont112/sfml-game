#include "../include/Ente.h"

Ente::Ente(): pGra(Gerenciadores::Gerenciador_Grafico::getInstance()), shape(){
        
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
    pGra->render(shape);
}