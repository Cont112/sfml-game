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
            sf::Vector2f posicao;       
            sf::Vector2f tam; 
            Colisao::Colisao* col;
            bool ativo;

        

        public:
            Entidade();
            Entidade(const sf::Vector2f pos,const sf::Vector2f tam);
            ~Entidade();

            sf::Vector2f getTam();
            sf::Vector2f getPosicao();
            void setTam(sf::Vector2f t);
            void setPosicao(sf::Vector2f p);
            
            
            void Colisao(sf::Vector2f intersecao,Entidades::Entidade * c);
            virtual void atualizar() = 0;
            


    };
}