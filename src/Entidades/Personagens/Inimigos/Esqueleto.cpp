#include "../../../../include/Entidades/Personagens/Inimigos/Esqueleto.h"

namespace Entidades {
    namespace Personagens {
        namespace Inimigos {
            Esqueleto::Esqueleto(sf::Vector2f pos,Jogador *jogador): 
            Inimigo(pos, sf::Vector2f(TAM_ESQUELETO_X,TAM_ESQUELETO_Y),jogador, IDs::esqueleto)
            {
                atira = false;
                pGrafico->createTexture(PATH_ESQUELETO);
                setTextura(pGrafico->textureMap.at(PATH_ESQUELETO));
            }

            Esqueleto::~Esqueleto()
            {
            }

            void Esqueleto::atualizar()
            {
                imprimir_se();
                atualizarPosicao();
                moveInimigo();
                dtAux += relogio.getElapsedTime().asSeconds() * 100;
                relogio.restart();
            }
        }
    }
}