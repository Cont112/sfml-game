#pragma once
#include <fstream>
#include "Fase.h"

#define PATH_CASTELO "assets/bosque.jpg"

namespace Fases{

    class Castelo: public Fase{
        private:
    
        public:
            Castelo();
            ~Castelo();
            void criarMapa();
    };
}