#pragma once 
#include "../Entidade.h"

namespace Entidades{
    namespace Obstaculos{
        class Obstaculo:public Entidade {

            protected:
                sf::Vector2f tamanho;
                bool danoso;              
            public:
                Obstaculo();
                ~Obstaculo();
                void setTamanho(sf::Vector2f t);
                void setDanoso(bool d);
                void executar();
        };



    }
}