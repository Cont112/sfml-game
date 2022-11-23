#pragma once

#include "Obstaculo.h"
#include "../Personagens/Personagem.h"

#define PATH_LAVA "assets/lava.png"
#define TAMANHO_LAVA_X 20.f
#define TAMANHO_LAVA_Y 20.0f

namespace Entidades {
    namespace Obstaculos{
        class Lava: public Obstaculo{
        private:
            int dano;
        public:
            Lava(sf::Vector2f pos);
            ~Lava();

            void atualizar();
            void colisao(Entidade* other, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
        };
    }
}