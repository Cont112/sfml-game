#pragma once 
#include "../Entidade.h"
#include "../Personagens/Personagem.h"
#include "../Personagens/Jogador.h"

namespace Entidades{
    namespace Obstaculos{
        class Obstaculo: public Entidade {

            protected:
                bool danoso;
                int dano;              
            public:
                Obstaculo(const sf::Vector2f pos, const sf::Vector2f tam, const char* path, const IDs id);
                ~Obstaculo();
                
                void setDanoso(bool d);
                virtual void atualizar() =0;
                virtual void colisao(Entidade* other, sf::Vector2f ds =  sf::Vector2f(0.0f,0.0f)) = 0;
                virtual void colisaoObstaculo(sf::Vector2f ds, Personagens::Personagem* pPersonagem);
                int getDano();
                void setDano(int d);

        };



    }
}