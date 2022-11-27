#include "../../../../include/Entidades/Personagens/Inimigos/Mago.h"

namespace Entidades {
    namespace Personagens {
        namespace Inimigos {
            
            
            Mago::Mago(sf::Vector2f pos, Jogador* jogador, Listas::Lista_Entidades *lista): Inimigo(pos, sf::Vector2f(TAM_MAGO_X,TAM_MAGO_Y), VELOCIDADE_MAGO,jogador, IDs::mago, 0), range(400.f),
                  listaObst(lista), projetilCriado(false)
            {
                
                pGrafico->createTexture(PATH_MAGO);
                setTextura(pGrafico->textureMap.at(PATH_MAGO));                
            }

            Mago::~Mago()
            {
            }
            
            void Mago::atacar()
            {          
                //projetil->setAtividade(true);
               
                sf::Vector2f ds(fabs(posicao.x - jogador1->getPosicao().x),fabs(posicao.y - jogador1->getPosicao().y) );
                
                if (ds.x<=RANGE_MAGO_X && ds.y <= RANGE_MAGO_Y)
                {
                    if (!projetilCriado)
                    {
                        criarProjetil();
                        if (posicao.x > jogador1->getPosicao().x)
                            projetil->setVel(sf::Vector2f(-projetil->getVel().x, projetil->getVel().y));
                    }

                    projetil->atualizar();
                }

                    
               
                    
                    
                
                
                 
            }
            void Mago::criarProjetil()
            {
                Entidades::Projetil *p = new Entidades::Projetil(posicao, sf::Vector2f(TAM_X_PROJETIL, TAM_Y_PROJETIL), PATH_PROJETIL, IDs::projetil,sf::Vector2f(VEL_X_PROJETIL, 0));
                listaObst->addEntidade(p);
                projetil = p;                                   
                projetilCriado = true;
                std::cout<<"criou projetil"<<std::endl;
            
            }
            
        }
    }
}
