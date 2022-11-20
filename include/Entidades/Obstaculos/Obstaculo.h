#pragma once 
#include "../Entidade.h"

namespace Entidades{
    namespace Obstaculos{
        class Obstaculo: public Entidade {

            protected:
                bool danoso;              
            public:
                Obstaculo(const sf::Vector2f pos, const sf::Vector2f tam, const char* path, const IDs id);
                ~Obstaculo();
                void setDanoso(bool d);
                void atualizar();
        };



    }
}