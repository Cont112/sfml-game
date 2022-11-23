#include "../../../../include/Entidades/Personagens/Inimigos/Mago.h"

namespace Entidades {
    namespace Personagens {
        namespace Inimigos {

            Mago::Mago(sf::Vector2f pos, Jogador* jogador): Inimigo(pos, sf::Vector2f(TAM_MAGO_X,TAM_MAGO_Y), VELOCIDADE_MAGO,jogador, IDs::mago), range(400.f)
            {
                atira = true;
                pGrafico->createTexture(PATH_MAGO);
                setTextura(pGrafico->textureMap.at(PATH_MAGO));
            }

            Mago::~Mago()
            {
            }

        }
    }
}
