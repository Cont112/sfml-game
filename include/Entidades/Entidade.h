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
            bool ativo;
        

        public:
            Entidade(const sf::Vector2f pos,const sf::Vector2f tam, IDs ID);
            ~Entidade();

            sf::Vector2f getTam();
            sf::Vector2f getPosicao();
            void setTam(sf::Vector2f t);
            void setPosicao(sf::Vector2f p);
            void setTipo(int tipo);
            int getTipo();
            void Colisao(sf::Vector2f intersecao,Entidades::Entidade * c);
            virtual void atualizar() = 0;
            


    };
}