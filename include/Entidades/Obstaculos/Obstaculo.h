#pragma once 
#include "../Entidade.h"

namespace Entidades{
    namespace Obstaculos{
        class Obstaculo: public Entidade {

            protected:
            
                sf::Vector2f tamanho;
                bool danoso;              
            public:
                Obstaculo();
                Obstaculo(const sf::Vector2f pos, const sf::Vector2f tam, const char* path);
                void setTamanho(sf::Vector2f t);
                ~Obstaculo();
                void setDanoso(bool d);
                void atualizar();
        };



    }
}