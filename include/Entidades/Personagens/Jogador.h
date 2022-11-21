#pragma once

#include <iostream>
#include "Personagem.h"

#define PATH_JOGADOR "assets/Jogador.png"
#define VELOCIDADE_JOGADOR 200.f
#define TAMANHO_PULO 0.1f

class Gerenciador_Colisoes;

namespace Entidades { 
    namespace Personagens{ 

        class Jogador:public Personagem
        {
            private:
                void init();
                bool isJumping;
 
            public:
                Jogador(const sf::Vector2f pos, const sf::Vector2f tam, const IDs ID);
                ~Jogador();

                void pular();
                void podePular();
                void atualizar();

                void colisao(Entidade* other, sf::Vector2f ds =  sf::Vector2f(0.0f,0.0f));
                

        };
    }
}