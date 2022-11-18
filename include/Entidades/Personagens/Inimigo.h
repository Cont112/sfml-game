#pragma once 
#include "Personagem.h"
#include "Jogador.h"

#define VELOCIDADE_INIMIGO 200.f

namespace Entidades { 
    namespace Personagens{ 
        class Inimigo : public Personagem{

            protected:
                bool atira;
                void init();
                Jogador *jogador1;

            public:
                Inimigo();
                ~Inimigo();
                void movimentar();
                void atualizar();
                void setJog1(Entidades::Personagens::Jogador *j);
        };
}
}