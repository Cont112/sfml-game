#include "../../../include/Entidades/Personagens/Inimigo.h"
#define HEIGHT 720
namespace Entidades { 
    namespace Personagens{ 

        Inimigo::Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Jogador *jogador,const IDs ID) :
        Personagem(pos,tam,VELOCIDADE_INIMIGO,ID),jogador1(jogador),atira(0), dtAux(0.0f)
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
            if(dtAux > .3f){
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
            if(fabs(posJogador.x - posInimigo.x) <= RAIO_X && fabs(posJogador.y - posInimigo.y) <= RAIO_Y){
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
            atualizarPosicao();
            moveInimigo();
            dtAux += relogio.getElapsedTime().asSeconds() * 100;
            relogio.restart();
        }

        void Inimigo::colisao(Entidade* other, sf::Vector2f ds)
        {
            switch (other->getID())
            {
            case (IDs::jogador):
                /* code */
                break;
            
            case (IDs::caixa):
                
                break;
            }
        }
    }
}