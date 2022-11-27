#include "../../../../include/Entidades/Personagens/Inimigos/Cavaleiro.h"

namespace Entidades {
    namespace Personagens {
        namespace Inimigos {
            Cavaleiro::Cavaleiro(sf::Vector2f pos,Jogador *jogador, int dano): 
            Inimigo(pos, sf::Vector2f(TAM_CAVALEIRO_X,TAM_CAVALEIRO_Y),VELOCIDADE_CAVALEIRO,jogador, IDs::cavaleiro, dano)
            {
                atira = false;
                setTextura(PATH_CAVALEIRO);
            }

            Cavaleiro::~Cavaleiro()
            {
            }

        }
    }
}