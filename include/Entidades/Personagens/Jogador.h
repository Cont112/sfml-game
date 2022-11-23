#pragma once

#include <iostream>
#include "Personagem.h"

#define PATH_JOGADOR_1 "assets/Jogador.png"
#define PATH_JOGADOR_2 "assets/barreto.jpg"
#define VELOCIDADE_JOGADOR 250.f
#define TAMANHO_PULO 0.2f

class Gerenciador_Colisoes;

namespace Entidades { 
    namespace Personagens{ 

        class Jogador:public Personagem
        {
            private:
                void init(const bool multiplayer);
                bool isJumping;
                bool invulneravel;
 
            public:
                Jogador(const sf::Vector2f pos, const sf::Vector2f tam, const bool multiplayer,const IDs ID);
                ~Jogador();

                void pular();
                void podePular();
                void receberDano(int dano);

                void atualizar();

                void colisao(Entidade* other, sf::Vector2f ds =  sf::Vector2f(0.0f,0.0f));
                

        };
    }
}