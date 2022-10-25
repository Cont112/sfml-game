#include "../include/Entidades/Entidade.h"

namespace Entidades {

    Entidade::Entidade(const sf::Vector2f size): sf::RectangleShape(size), Ente()
    {
    }

    Entidade::Entidade(): sf::RectangleShape(), Ente()
    {
    }

    Entidade::~Entidade()
    { 
    }

    void Entidade::setHitbox( const sf::FloatRect& h)
    {
        hitbox = h;
    }
    sf::FloatRect Entidade::getHitbox() const
    {
        return getTransform().transformRect(hitbox);
    }
}

