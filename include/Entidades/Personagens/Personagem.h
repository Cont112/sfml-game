#pragma once
#include "../Entidade.h"
#include "../../Gerenciadores/Graficos.h"

namespace Entidades {
    namespace Personagens {

        class Personagem: public Entidade
        {
        protected:
            int vida;
            int dano;
            bool morto;
            sf::Vector2f velocidade;        
           

        public:
            Personagem(int vi, int d, bool m, float vx, float vy);
            ~Personagem();
            sf::Vector2f getVelocidade() const;
            int getVida() const;
            void setVelocidade (sf::Vector2f v);
            void setMorto(bool m);
            void setVida (int v);
            void setDano(int d);
        };
    }
}