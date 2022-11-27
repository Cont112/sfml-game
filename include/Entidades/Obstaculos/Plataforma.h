#pragma once

#include "Obstaculo.h"
#include "../Personagens/Personagem.h"

#define PATH_PLATAFORMA_1 "assets/Objetos/ground1.png"
#define PATH_PLATAFORMA_2 "assets/Objetos/ground2.png"
#define TAMANHO_PLATAFORMA_X 100.f
#define TAMANHO_PLATAFORMA_Y 20.0f

namespace Entidades {
    namespace Obstaculos{
        class Plataforma: public Obstaculo{
        private:
            bool flutuando;
        public:
            Plataforma(sf::Vector2f pos, bool f,bool v);
            ~Plataforma();

            void atualizar();
            void colisao(Entidade* other, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
        };
    }
}