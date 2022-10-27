#pragma once
#include "../Entidade.h"
#include "../../Gerenciadores/Graficos.h"

namespace Entidades {
    namespace Personagens {

        class Personagem: public Entidade
        {
        protected:
            int vida;
            int dano;
            bool morto;
            Fisica::CoordF velocidade;        
           

        public:
            Personagem(int vi, int d, bool m);
            ~Personagem();
            void setVelocidade (Fisica::CoordF v);
            Fisica::CoordF getVelocidade() const;
            

            virtual void executar() = 0;
            virtual void movimentar() = 0;
        };
    }
}