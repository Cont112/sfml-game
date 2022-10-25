#pragma once
#include "../Entidade.h"

namespace Entidades {
    namespace Personagens {

        class Personagem: public Entidade
        {
        protected:
            int vida;
            int dano;
            bool morto;

        public:
            Personagem();
            ~Personagem();

            virtual void executar() = 0;
            virtual void movimentar() = 0;
        };
    }
}