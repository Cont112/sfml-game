#include "../../../../include/Entidades/Personagens/Inimigos/Esqueleto.h"

namespace Entidades {
    namespace Personagens {
        namespace Inimigos {
            Esqueleto::Esqueleto(sf::Vector2f pos,Jogador *jogador, int dano): 
            Inimigo(pos, sf::Vector2f(TAM_ESQUELETO_X,TAM_ESQUELETO_Y),VELOCIDADE_ESQUELETO,jogador, IDs::esqueleto, dano)
            {
                atira = false;
                setTextura(PATH_ESQUELETO);
            }

            Esqueleto::~Esqueleto()
            {
            }

        }
    }
}