#pragma once
#include "../Ente.h"

namespace Entidades {

    class Entidade : public Ente {
        protected:
            int x,y;

        public:
            Entidade();
            ~Entidade();

    };


}