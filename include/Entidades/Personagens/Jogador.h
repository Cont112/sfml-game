#pragma once

#include <iostream>
#include <cstring>
#include "Personagem.h"

#define PATH_JOGADOR_1 "assets/Jogadores/jogador1.png"
#define PATH_JOGADOR_2 "assets/Jogadores/jogador2.png"
#define VELOCIDADE_JOGADOR 250.f
#define TAMANHO_PULO .2f

class Gerenciador_Colisoes;

namespace Entidades { 
    namespace Personagens{ 

        class Jogador:public Personagem
        {
            private:
                sf::Text textoVida;
                void init(const bool multiplayer);
                bool isJumping;
                bool invulneravel;
 
            public:
                Jogador(const bool multiplayey);
                ~Jogador();

                void pular();
                void podePular();
                void receberDano(int dano);

                void atualizar();
                void resetar();
                void colisao(Entidade* other, sf::Vector2f ds =  sf::Vector2f(0.0f,0.0f));

        };
    }
}