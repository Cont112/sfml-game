#include "../include/Entidade.h"

Entidade::Entidade():posicao(sf::Vector2f(0.f, 0.f)), ativo(0), vel(sf::Vector2f(0.f, 0.f))
{


}
Entidade::~Entidade()
{

}

sf::Vector2f Entidade:: getPosicao()
{
    return posicao;
}
void Entidade::setPosicao(sf::Vector2f p)
{
    posicao = p;
}
sf::Vector2f Entidade:: getVelocidade()
{
    return vel;
}
void Entidade::setVelocidade(sf::Vector2f v)
{
    vel = v;
}