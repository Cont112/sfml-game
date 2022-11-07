#include "../../../include/Entidades/Personagens/Jogador.h"

namespace Entidades{ 
namespace Personagens{ 
Jogador::Jogador()
{
    init();

}

Jogador::~Jogador()
{
}

void Jogador::init()
{
    vel = sf::Vector2f(0.1f,0.1f);
    shape.setOrigin(0.0f,0.0f);
    shape.setSize(sf::Vector2f(100.0f,100.0f));
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

}
}