#pragma once

#include <iostream>
#include "../../Entidades/Colisao.h"
#include "Personagem.h"
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
                Jogador(const sf::Vector2f pos, const sf::Vector2f tam);
                Jogador();
                ~Jogador();

                void pular();
                void atualizar();
                

        };
    }
}