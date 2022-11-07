#pragma once
#include "../Personagem.h"
#include "../Jogador.h"

namespace Personagens{

    namespace Inimigos{

        class Inimigo: public Personagem
        {
        private:
            Jogador* j1;
            sf::Clock clock;
            int rand;
            void init();

        public:
            Inimigo(sf::Vector2f pos, sf::Vector2f tam, Jogador* j);
            ~Inimigo();

        };

    }
    
}