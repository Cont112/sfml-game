#pragma once
#include "../Ente.h"

namespace Entidades{ 
    class Entidade:public Ente{

        protected:
            sf::Vector2f posicao;       
            sf::Vector2f tam;
            sf::Vector2f vel;
            int dano;
            
            bool ativo;

        public:
            Entidade(const sf::Vector2f pos,const sf::Vector2f tam, const sf::Vector2f vel,IDs ID, int d);
            ~Entidade();

            sf::Vector2f getVel();
            sf::Vector2f getTam();
            sf::Vector2f getPosicao();
            void setVel(sf::Vector2f v);
            void setTam(sf::Vector2f t);
            void setPosicao(sf::Vector2f p);
            virtual void colisao(Entidade* other, sf::Vector2f ds =  sf::Vector2f(0.0f,0.0f)) = 0;
            virtual void atualizar() = 0;
            void setAtividade(bool a);
            bool getAtividade();
            void setDano(int d);
            int getDano();
            
    };
}