#include "../../include/Entidades/Entidade.h"
#include "../../include/Entidades/Colisao.h"
#include <iostream>

namespace Entidades
{

    Entidade::Entidade() : Ente(), posicao(sf::Vector2f(0.f, 0.f)), tam(sf::Vector2f(32.f,32.f)), ativo(1), inimigo(false), jogador(false), obstaculo(false)
    {
    }

    Entidade::Entidade(const sf::Vector2f pos, const sf::Vector2f tam) : Ente(), posicao(pos), ativo(1), inimigo(false), jogador(false), obstaculo(false)
    {
        shape.setSize(tam);
        shape.setPosition(pos);
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
   
    void Entidade:: setTipo(int tipo)
    {
        if (tipo ==1)
            jogador = true;
        else if (tipo == 2)
            inimigo = true;
        else if (tipo ==3)
            obstaculo = true; 
    }

    int Entidade::getTipo()
    {
        if (inimigo)
            return 2;
        else if(jogador)
            return 1;
        else
            return 3;
    }

    void Entidade::setTam(sf::Vector2f t)
    {
        tam = t;
        shape.setSize(tam);
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


}