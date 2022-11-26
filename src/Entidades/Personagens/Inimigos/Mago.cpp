#include "../../../../include/Entidades/Personagens/Inimigos/Mago.h"

namespace Entidades {
    namespace Personagens {
        namespace Inimigos {

            Mago::Mago(sf::Vector2f pos, Jogador* jogador, Listas::Lista_Entidades *lista): Inimigo(pos, sf::Vector2f(TAM_MAGO_X,TAM_MAGO_Y), VELOCIDADE_MAGO,jogador, IDs::mago, 0), range(400.f),
                  listaObst(lista)
            {
                atira = false;
                pGrafico->createTexture(PATH_MAGO);
                setTextura(pGrafico->textureMap.at(PATH_MAGO));
                
                
            }

            Mago::~Mago()
            {
            }
            
            void Mago::atacar()
            {
                
                if (!atira)
                {
                    projetil = new Entidades::Projetil(posicao, sf::Vector2f(TAM_X_PROJETIL, TAM_Y_PROJETIL), PATH_PROJETIL, IDs::projetil,sf::Vector2f(VEL_X_PROJETIL, 0));
                    listaObst->addEntidade(projetil);
                    std::cout<<"criei projetil"<<std::endl;
                    atira = 1;
                }
                
                projetil->setAtividade(true);
                projetil->atualizar();
                    
                
                 
            }
            
        }
    }
}
