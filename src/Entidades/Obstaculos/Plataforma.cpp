#include "../../../include/Entidades/Obstaculos/Plataforma.h"

namespace Entidades{
    namespace Obstaculos{
        Plataforma::Plataforma(sf::Vector2f pos): Obstaculo(pos, sf::Vector2f(TAMANHO_PLATAFORMA_X, TAMANHO_PLATAFORMA_Y), PATH_PLATAFORMA, IDs::plataforma)
        {
        }

        Plataforma::~Plataforma()
        {
        }

        void Plataforma::colisao(Entidade* other, sf::Vector2f ds)
        {
            sf::Vector2f posOutro = other->getPosicao();
            sf::Vector2f tamOutro = other->getTam();

            if(other->getID() == IDs::jogador || other->getID() == IDs::esqueleto || other->getID() == IDs::zumbi)
            {
                colisaoObstaculo(ds, static_cast<Personagens::Personagem*>(other));
            }
        }

    }
}