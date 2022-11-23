#include "../../../include/Entidades/Obstaculos/Lava.h"

namespace Entidades{
    namespace Obstaculos{
        Lava::Lava(sf::Vector2f pos): 
        Obstaculo(pos, sf::Vector2f(TAMANHO_LAVA_X, TAMANHO_LAVA_Y), PATH_LAVA, IDs::lava), 
        dano(50)
        {
        }

        Lava::~Lava()
        {
        }
        void Lava::atualizar()
        {
            imprimir_se();
        }

        void Lava::colisao(Entidade* other, sf::Vector2f ds)
        {

            if(other->getID() == IDs::jogador || other->getID() == IDs::esqueleto || other->getID() == IDs::mago)
            {
                colisaoObstaculo(ds, static_cast<Personagens::Personagem*>(other));
            }
        }

    }
}