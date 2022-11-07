#include "../../../include/Entidades/Personagens/Inimigo.h"

Inimigo::Inimigo(): atira(0)
{
    init();
}
Inimigo::~Inimigo()
{

}
void Inimigo::init()
{
    vel = sf::Vector2f(0.1f,0.1f);
    shape.setOrigin(500.f,500.f);
    shape.setSize(sf::Vector2f(100.0f,100.0f));

}
void Inimigo::movimentar()
{


}