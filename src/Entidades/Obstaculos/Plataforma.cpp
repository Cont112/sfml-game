#include "../../../include/Entidades/Obstaculos/Plataforma.h"

namespace Entidades{
    namespace Obstaculos{
        Plataforma::Plataforma(sf::Vector2f pos): 
        Obstaculo(pos, sf::Vector2f(TAMANHO_PLATAFORMA_X, TAMANHO_PLATAFORMA_Y), PATH_PLATAFORMA, IDs::plataforma, 0), 
        flutuando(false)
        {
        }

        Plataforma::~Plataforma()
        {
        }
        void Plataforma::atualizar()
        {
            imprimir_se();
        }

        void Plataforma::colisao(Entidade* other, sf::Vector2f ds)
        {

            if(other->getID() == IDs::jogador || other->getID() == IDs::esqueleto || other->getID() == IDs::mago)
            {
                colisaoObstaculo(ds, static_cast<Personagens::Personagem*>(other));
            }
        }

    }
}