#pragma once
#include "Personagem.h"
#include "iostream"


namespace Entidades {
    namespace Personagens {

        class Jogador: public Personagem
        {   
            public:
                Jogador(int vi, int d, bool m);
                ~Jogador();
                 
                void executar();

        };
    }
}