#pragma once

#include "Obstaculo.h"
#include "../Personagens/Personagem.h"

#define PATH_PLATAFORMA "assets/ground.jpeg"
#define TAMANHO_PLATAFORMA_X 100.f
#define TAMANHO_PLATAFORMA_Y 20.0f

namespace Entidades {
    namespace Obstaculos{
        class Plataforma: public Obstaculo{
        private:
            bool flutuando;
        public:
            Plataforma(sf::Vector2f pos);
            ~Plataforma();

            void atualizar();
            void colisao(Entidade* other, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
        };
    }
}