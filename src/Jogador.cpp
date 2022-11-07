#include "../include/Jogador.h"

Jogador::Jogador():shape()
{
    init();

}

Jogador::~Jogador()
{
}

void Jogador::init()
{
    vel = sf::Vector2f(0.1f,0.1f);
    shape.setSize(sf::Vector2f(100.f, 100.f));
    shape.setOrigin(0.0f,0.0f);
    shape.setSize(sf::Vector2f(100.0f,100.0f));
}

sf::RectangleShape Jogador::getShape() const
{
    return shape;
}

void Jogador::setTextura(sf::Texture* texture)
{
    shape.setTexture(texture);
}

void Jogador::movimentar()
{

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        shape.move(-vel.x, 0.0f);

    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        shape.move(vel.x, 0.0f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        shape.move(0.0f, -vel.y);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        shape.move(0.0f, vel.y);
    }
}

void Jogador::imprimir_se()
{
    pGra->render(shape);
}
