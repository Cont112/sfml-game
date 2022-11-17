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
            Entidades::Colisao::Colisao *col;
        
        public:
            Entidade();
            ~Entidade();
            sf::Vector2f getPosicao();
            void setPosicao(sf::Vector2f p);
            sf::Vector2f getVelocidade();
            void setVelocidade(sf::Vector2f v);
            Entidades::Colisao::Colisao getColisao();
            void executar();
            


    };
}