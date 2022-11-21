#pragma once

#include "Inimigo.h"

#define PATH_MAGO "assets/Wizard.png"
#define TAM_MAGO_X 64.f
#define TAM_MAGO_Y 64.f

namespace Entidades {
    namespace Personagens{
        namespace Inimigos{
            class Mago: public Inimigo{
            private:
                float range;
            public:
                Mago(sf::Vector2f pos, Jogador* jogador);
                ~Mago();
            };
        }
    }
}