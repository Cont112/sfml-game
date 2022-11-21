#include "../../../include/Entidades/Personagens/Jogador.h"
#include "../../../include/Gerenciadores/Gerenciador_Colisoes.h"
#define WIDTH 1280
#define HEIGHT 720

//MUDAR MOVIMENTO PARA SETAR VELOCIDADES 

namespace Entidades{ 
    namespace Personagens{ 
        Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f tam, const IDs ID): Personagem(pos,tam, VELOCIDADE_JOGADOR, ID), isJumping(false)
        {
            init();
        }

        Jogador::~Jogador()
        {
        }

        void Jogador::init()
        {
            pGrafico->createTexture(PATH_JOGADOR);
            setTextura(pGrafico->textureMap.at(PATH_JOGADOR));
            shape.setOrigin(sf::Vector2f(0.f,0.f));
        }

        void Jogador::pular()
        {
            if(!isJumping){
                vel.y = -sqrt(2.0f * GRAVIDADE * TAMANHO_PULO);
                isJumping = true;
            }
        }

        void Jogador::podePular()
        {
            isJumping = false;
        }

        void Jogador::atualizar()
        {
            if(ativo)
            {
                imprimir_se();
                atualizarPosicao();
            }

        }

        void Jogador::colisao(Entidade* other, sf::Vector2f ds)
        {
            switch (other->getID())
            {
            case (IDs::inimigo):
                /* code */
                break;
            
            case (IDs::caixa):

                break;
            }
        }

    }
}
