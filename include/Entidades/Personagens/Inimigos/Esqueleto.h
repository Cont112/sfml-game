#pragma once

#include "Inimigo.h"

#define PATH_ESQUELETO "assets/Esqueleto.png"
#define DANO_ESQUELETO 20.f
#define TAM_ESQUELETO_X 60.0f
#define TAM_ESQUELETO_Y 64.0f

namespace Entidades{
    namespace Personagens {
        namespace Inimigos {
            class Esqueleto: public Inimigo {
            private:
                
            public:
                Esqueleto(const sf::Vector2f pos,Jogador *jogador);
                ~Esqueleto();

                void atualizar();
            };
        }
    }
}