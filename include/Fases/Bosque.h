#pragma once
#include "Fase.h"

namespace Fases{

    class Bosque: public Fase{
        private:
    
        public:
            Bosque();
            ~Bosque();
            void executar();
            void inicializar_entidades();
    }
}