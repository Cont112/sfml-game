#include "../../include/Personagens/Jogador.h"

Jogador::Jogador(): shape()
{
    init();
}

Jogador::~Jogador()
{
}

void Jogador::init()
{
    vel = sf::Vector2f(0.2f,0.2f);
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
        std::cout << -1 << "," << 0 << std::endl;

    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        shape.move(vel.x, 0.0f);
        std::cout << 1 << "," << 0 << std::endl;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        shape.move(0.0f, -vel.y);
        std::cout << 0 << "," << -1 << std::endl;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        shape.move(0.0f, vel.y);
        std::cout << 0 << "," << 1 << std::endl;
    }
}