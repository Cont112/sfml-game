#include "../../include/Entidades/Entidade.h"
#include <iostream>

namespace Entidades
{

    Entidade::Entidade(const sf::Vector2f pos, const sf::Vector2f tam, const sf::Vector2f vel, const IDs ID) : 
    Ente(ID), posicao(pos), tam(tam), vel(vel),ativo(1)
    {
        shape.setOrigin(sf::Vector2f(tam.x/2.0f, 0.0f));
        shape.setPosition(posicao);
        shape.setSize(tam);
    } 

    Entidade::~Entidade()
    {
        
    }

    sf::Vector2f Entidade::getPosicao()
    {
        return posicao;
    }
    sf::Vector2f Entidade::getTam()
    {
        return tam;
    }
    sf::Vector2f Entidade::getVel()
    {
        return vel;
    }
    void Entidade::setVel(sf::Vector2f v)
    {
        vel = v;
    }
    
    void Entidade::setPosicao(sf::Vector2f p)
    {
        posicao = p;
        shape.setPosition(posicao);
    }
   

    void Entidade::setTam(sf::Vector2f t)
    {
        tam = t;
        shape.setSize(tam);
    }
    void Entidade::setAtividade(bool a)
    {
        ativo = a;
    }
    bool Entidade::getAtividade()
    {
        return ativo;
    }

}