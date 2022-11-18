#include "../../include/Entidades/Entidade.h"
#include "../../include/Entidades/Colisao.h"
#include <iostream>

namespace Entidades
{

    Entidade::Entidade() : Ente(), posicao(sf::Vector2f(0.f, 0.f)), ativo(0), vel(sf::Vector2f(0.f, 0.f)), col(new Colisao::Colisao())
    {
    }

    Entidade::Entidade(const sf::Vector2f pos, const sf::Vector2f tam) : Ente(), posicao(pos), ativo(0), vel(sf::Vector2f(0.f, 0.f)), col(new Colisao::Colisao())
    {
        shape.setSize(tam);
    }

    Entidade::~Entidade()
    {
        if (col)
            delete col;
    }

    sf::Vector2f Entidade::getPosicao()
    {
        return posicao;
    }
    
    void Entidade::setPosicao(sf::Vector2f p)
    {
        posicao = p;
        shape.setPosition(p);
    }
   
    sf::Vector2f Entidade::getVelocidade()
    {
        return vel;
    }
   
    void Entidade::setVelocidade(sf::Vector2f v)
    {
        vel = v;
    }
   
    

    void Entidade::Colisao(sf::Vector2f intersecao,Entidades::Entidade * c)
    {
        sf::Vector2f posColisor = c->getPosicao();
        
        if (intersecao.x > intersecao.y)
        {
            if(posicao.x < posColisor.x)
                shape.move(intersecao.x, 0) ;
            else 
                shape.move(-intersecao.x, 0);
        }
        else 
        {
            if (posicao.y < posColisor.y)
                shape.move(0, intersecao.y);
            else 
                shape.move(0, -intersecao.y);
        }
        
    }

    void Entidade::executar()
    {
    }

}