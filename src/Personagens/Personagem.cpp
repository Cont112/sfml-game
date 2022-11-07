#include "../../include/Personagens/Personagem.h"

namespace Personagens
{

    Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam): shape()
    {
        shape.setPosition(pos);
        shape.setSize(tam);
    }

    Personagem::~Personagem()
    {
    }

    sf::RectangleShape Personagem::getShape() const
    {
        return shape;
    }

    void Personagem::setTextura(sf::Texture* texture)
    {
        shape.setTexture(texture);
    }

}