#pragma once
#include "Obstaculo.h"

#define PATH_CAIXA "assets/Objetos/caixa.png"
#define TAMANHO_CAIXA_X 32.f
#define TAMANHO_CAIXA_Y 32.f

namespace Entidades{
    namespace Obstaculos{
        class Caixa: public Obstaculo
        {
        private:
            float vely =0.0f;

        public:
            Caixa(sf::Vector2f pos);
            ~Caixa();

            void atualizar();
            void colisao(Entidade* other, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
        };
    }
}