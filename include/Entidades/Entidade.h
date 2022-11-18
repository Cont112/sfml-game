#pragma once
#include "../Ente.h"


namespace Entidades{
    namespace Colisao{
        class Colisao;
    }
}


namespace Entidades{ 
    class Entidade:public Ente{

        protected:
            float g = 1.0f;
            sf::Vector2f posicao;       
            bool ativo;
            sf::Vector2f vel; 
            bool inimigo;
            bool jogador;
            bool obstaculo;
        
        public:
            Entidade();
            Entidade(const sf::Vector2f pos,const sf::Vector2f tam);
            ~Entidade();
            sf::Vector2f getPosicao();
            void setPosicao(sf::Vector2f p);
            sf::Vector2f getVelocidade();
            void setVelocidade(sf::Vector2f v);
            void setTipo(int tipo);
            int getTipo();
            void Colisao(sf::Vector2f intersecao,Entidades::Entidade * c);
            void executar();
            


    };
}