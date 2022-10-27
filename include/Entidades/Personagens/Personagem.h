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
            Personagem(int vida, int dano, bool morto, sf::Vector2f v);
            ~Personagem();
            void setVelocidade (sf::Vector2f v);
            sf::Vector2f getVelocidade() const;
            

            virtual void executar() = 0;
            virtual void movimentar() = 0;
        };
    }
}