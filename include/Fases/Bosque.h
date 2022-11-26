#pragma once
#include <fstream>
#include "Fase.h"

#define PATH_BOSQUE "assets/bosque.jpg"


namespace Fases{

    class Bosque: public Fase{
        private:
    
        public:
            Bosque();
            ~Bosque();
            void criarMapa();
    };
}