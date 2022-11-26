#include "../../../../include/Entidades/Personagens/Inimigos/Mago.h"

namespace Entidades {
    namespace Personagens {
        namespace Inimigos {

            Mago::Mago(sf::Vector2f pos, Jogador* jogador, Listas::Lista_Entidades *lista): Inimigo(pos, sf::Vector2f(TAM_MAGO_X,TAM_MAGO_Y), VELOCIDADE_MAGO,jogador, IDs::mago, 0), range(400.f),
                  listaObst(lista)
            {
                atira = true;
                pGrafico->createTexture(PATH_MAGO);
                setTextura(pGrafico->textureMap.at(PATH_MAGO));
                Entidades::Projetil *p = new Entidades::Projetil(posicao, sf::Vector2f(TAM_X_PROJETIL, TAM_Y_PROJETIL), PATH_PROJETIL, IDs::projetil,sf::Vector2f(VEL_X_PROJETIL, 0));
                projetil = p;

                listaObst->addEntidade(p);
                
            }

            Mago::~Mago()
            {
            }
            
            void Mago::atacar()
            {
                
                projetil->setAtividade(true);
                projetil->atualizar();
                    
                
                 
            }
            
        }
    }
}
