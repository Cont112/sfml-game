#pragma once

#include "Inimigo.h"

#define PATH_CAVALEIRO "assets/Inimigos/cavaleiro.png"

#define DANO_CAVALEIRO 20.f
#define TAM_CAVALEIRO_X 56.0f
#define TAM_CAVALEIRO_Y 84.0f
#define VELOCIDADE_CAVALEIRO 150.0f

namespace Entidades{
    namespace Personagens {
        namespace Inimigos {
            class Cavaleiro: public Inimigo {
            private:
                
            public:
                Cavaleiro(const sf::Vector2f pos,Jogador *jogador, int dano);
                ~Cavaleiro();
            };
        }
    }
}