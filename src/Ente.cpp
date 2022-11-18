#include "../include/Ente.h"

Gerenciadores::Gerenciador_Grafico* Ente::pGrafico = Gerenciadores::Gerenciador_Grafico::getInstance();
int Ente::num_ente = 0;
Ente::Ente(): shape()
{
    num_ente++;
    id = num_ente;
    std::cout << "Ente criado!" << std::endl;
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