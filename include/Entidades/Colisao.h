#pragma once
#include "../../include/Entidades/Entidade.h"

namespace Entidades
{    
    namespace Colisao
    {
       class Colisao{

            private:
                bool colidiu;
                Entidades::Entidade* colisor;
            public:
                Colisao();
                ~Colisao();
                void SetColisao(bool estado,Entidades::Entidade * c);
                bool bateu();
                Entidades::Entidade * getColisor();
        };        
    }
}
