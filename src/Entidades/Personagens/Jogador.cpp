#include "../../../include/Entidades/Personagens/Jogador.h"
#include "../../../include/Gerenciadores/Gerenciador_Colisoes.h"
#define WIDTH 1280
#define HEIGHT 720

//MUDAR MOVIMENTO PARA SETAR VELOCIDADES 

namespace Entidades{ 
    namespace Personagens{ 
        Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f tam): Personagem(pos,tam, VELOCIDADE_JOGADOR), isJumping(false)
        {
            init();
        }

        Jogador::Jogador(): Personagem(VELOCIDADE_JOGADOR), isJumping(false)
        {
            init();
        }

        Jogador::~Jogador()
        {
        }

        void Jogador::init()
        {
            shape.setOrigin(sf::Vector2f(0.0f,0.0f));
            shape.setSize(sf::Vector2f(100.0f,100.0f));
        }

        void Jogador::pular()
        {
            if(!isJumping){
                vel.y = -2;
                isJumping = true;
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
