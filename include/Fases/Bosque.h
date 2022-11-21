#pragma once
#include <fstream>
#include "Fase.h"



namespace Fases{

    class Bosque: public Fase{
        private:
    
        public:
            Bosque();
            ~Bosque();
            void criarMapa();
            void criarFundo();
    };
}