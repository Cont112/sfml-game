#pragma once 
#include "../Entidade.h"
#include "../Personagens/Personagem.h"
#include "../Personagens/Jogador.h"

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
                virtual void colisao(Entidade* other, sf::Vector2f ds =  sf::Vector2f(0.0f,0.0f)) = 0;
                virtual void colisaoObstaculo(sf::Vector2f ds, Personagens::Personagem* pPersonagem);
        };



    }
}