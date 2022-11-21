#include "../../include/Entidades/Entidade.h"
#include <iostream>

namespace Entidades
{

    Entidade::Entidade(const sf::Vector2f pos, const sf::Vector2f tam, const IDs ID) : Ente(ID), posicao(pos), tam(tam), ativo(1)
    {
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

}