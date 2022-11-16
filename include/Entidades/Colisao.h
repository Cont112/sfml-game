#pragma once
#include "../../include/Entidades/Entidade.h"

namespace Entidades
{    
    namespace Colisao
    {
       class Colisao{

            private:
                bool frontal;//tipo 1
                bool superior;//tipo 2
                Entidades::Entidade* C;
            public:
                Colisao();
                ~Colisao();
                void SetColisao(int tipo, bool estado);
                bool GetColisaoFrontal();
                bool GetColisaoSuperior();
                void setColisor(Entidades::Entidade *e);
                Entidades::Entidade * getColisor();
        };        
    }
}
