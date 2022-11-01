#pragma once
#include "Personagem.h"


namespace Entidades {
    namespace Personagens {

        class Jogador: public Personagem
        {   
            public:
                Jogador(int vi, int d, bool m);
                ~Jogador();
                 
                void executar()override;
                void movimentar();

        };
    }
}