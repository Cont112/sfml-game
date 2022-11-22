#pragma once
#include <fstream>
#include "Fase.h"



namespace Fases{

    class Castelo: public Fase{
        private:
    
        public:
            Castelo();
            ~Castelo();
            void criarMapa();
            void criarFundo();
    };
}