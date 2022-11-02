#include "../../include/Entidades/Entidade.h"

namespace Entidades {


    Entidade::Entidade(int posx, int posy) : Ente()
    {
        x = posx;
        y = posy;
    }

    Entidade::~Entidade()
    { 
    }

    void Entidade::imprimir_se()
    {
        pGrafico->render(sprite);   
    }

    sf::Sprite Entidade::getSprite() const
    {
        return sprite;
    }

}

