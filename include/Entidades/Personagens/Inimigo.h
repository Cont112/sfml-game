#pragma once 
#include "Personagem.h"
#include "Jogador.h"

#include <cmath>

#define RAIO_X 200.0f
#define RAIO_Y 200.0f

#define VELOCIDADE_INIMIGO 200.f

namespace Entidades { 
    namespace Personagens{ 
        class Inimigo : public Personagem{

            protected:
                bool atira;
                Jogador *jogador1;
                int moveAleatorio;
                float dtAux;

                void moveInimigo();
                void atualizarMovimentoAleatorio();
            public:
                Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Jogador* jogador,const IDs ID);
                ~Inimigo();

                virtual void atualizar();
        };
}
}