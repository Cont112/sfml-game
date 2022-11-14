#pragma once 
#include "Personagem.h"
#include "Jogador.h"

namespace Entidades { 
    namespace Personagens{ 
        class Inimigo : public Entidades::Personagens::Personagem{

            protected:
                bool atira;
                void init();
                Entidades::Personagens::Jogador *jogador1;

            public:
                Inimigo();
                ~Inimigo();
                void movimentar();
                void executar();
                void setJog1(Entidades::Personagens::Jogador *j);
        };
}
}