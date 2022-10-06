#pragma once
#include "../Fisica/CoordTL.h"


namespace Entidades {

    class Entidade {
        protected:
            Fisica::CoordF pos;
            Fisica::CoordF size;

        public:
            Entidade();
            ~Entidade();

    };


}