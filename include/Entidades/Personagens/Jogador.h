#pragma once
#include "Personagem.h"


namespace Entidades {
    namespace Personagens {

        class Jogador: public Personagem
        {   
            public:
                Jogador();
                ~Jogador();
                void movimentar()override;
                void executar()override;            



        };
    }
}