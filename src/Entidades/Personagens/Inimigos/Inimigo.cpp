#include "../../../../include/Entidades/Personagens/Inimigos/Inimigo.h"
#define HEIGHT 720
namespace Entidades { 
    namespace Personagens{
        namespace Inimigos{  

        Inimigo::Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, const float vel,Jogador *jogador,const IDs ID) :
        Personagem(pos,tam,vel,ID),jogador1(jogador),atira(0)
        {
            moveAleatorio = rand()%3;
            if(moveAleatorio == 0){
                parar();
            } else if (moveAleatorio == 1){
                movimentar(true);
            } else {
                movimentar(false);
            }
        }
        Inimigo::~Inimigo()
        {
        }

        void Inimigo::atualizarMovimentoAleatorio()
        {
            if(dtAux > 1.0f){
                moveAleatorio = rand()%3;
                if(moveAleatorio == 0){
                    parar();
                } else if (moveAleatorio == 1){
                    movimentar(true);
                } else {
                    movimentar(false);
                }
                dtAux = 0.0f;          
            }
        }
        
        void Inimigo::moveInimigo()
        {
            sf::Vector2f posJogador = jogador1->getPosicao();
            sf::Vector2f posInimigo = getPosicao();
            if(fabs(posJogador.y - posInimigo.y) <= 20.f && fabs(posJogador.x - posInimigo.x) <= RAIO_X){
                if(posJogador.x - posInimigo.x > 0.0f){
                    movimentar(false);
                } else {
                    movimentar(true);
                }
            } else {
                atualizarMovimentoAleatorio();
            }
        }

        void Inimigo::atualizar()
        {
            if (vivo && ativo)
            {
                imprimir_se();
                atualizarPosicao();
                moveInimigo();
                dtAux += pGrafico->getDt();
            }
        }

        void Inimigo::colisao(Entidade* other, sf::Vector2f ds)
        {
            switch (other->getID())
            {
            case (IDs::jogador):
                parar();
                break;
            
            case (IDs::caixa):
                parar();
                atualizarMovimentoAleatorio();
                break;
            
            case (IDs::esqueleto):
            {
                if (other->getAtividade())
                {
                    colisaoPersonagem(ds, other);
                }
            }
            case(IDs::mago):
            {
                 if (other->getAtividade())
                {
                    colisaoPersonagem(ds, other);
                }
            }
                break;
            }

        }
    
        
    }
}
}