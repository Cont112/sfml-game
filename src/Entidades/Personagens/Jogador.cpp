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
            shape.setOrigin(sf::Vector2f(tam.x/2.5f,tam.y/2.0f));
        }

        void Jogador::pular()
        {
            if(!isJumping){
                vel.y = -sqrt(2.0f * GRAVIDADE * TAMANHO_PULO);
                //isJumping = true;
            }
        }

        void Jogador::atualizar()
        {
            if(ativo)
            {
                imprimir_se();
                atualizarPosicao();
            }

        }

    }
}
