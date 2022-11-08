#pragma once 
#include "Personagem.h"

namespace Entidades { 
    namespace Personagens{ 
        class Inimigo : public Entidades::Personagens::Personagem{

            protected:
                bool atira;
                void init();

            public:
                Inimigo();
                ~Inimigo();
                void movimentar();
                void executar();

        };
}
}