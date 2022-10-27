#pragma once
#include "Personagem.h"


namespace Entidades {
    namespace Personagens {

        class Jogador: public Personagem
        {   
            public:
                Jogador(int vi, int d, bool m);
                ~Jogador();
                void movimentar()override;
                void executar()override;            



        };
    }
}