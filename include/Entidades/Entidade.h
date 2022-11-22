#pragma once
#include "../Ente.h"

namespace Entidades{ 
    class Entidade:public Ente{

        protected:
            sf::Vector2f posicao;       
            sf::Vector2f tam;
            sf::Vector2f vel;

            bool ativo;
            sf::Clock relogio;
            float dt;

        public:
            Entidade(const sf::Vector2f pos,const sf::Vector2f tam, const sf::Vector2f vel,IDs ID);
            ~Entidade();

            sf::Vector2f getTam();
            sf::Vector2f getPosicao();
            void setTam(sf::Vector2f t);
            void setPosicao(sf::Vector2f p);
            virtual void colisao(Entidade* other, sf::Vector2f ds =  sf::Vector2f(0.0f,0.0f)) = 0;
            virtual void atualizar() = 0;
            
    };
}