#pragma once
#include "../Ente.h"


namespace Entidades {

    class Entidade : public Ente
    {
        protected:
            //pode usar vetor ?
            int x;
            int y;
            sf::Sprite* sprite;
            
            

        public:
            Entidade(int posx = 0 , int posy  = 0);
            ~Entidade();

            void imprimir_se();
            void setTextura(sf::Texture t);

    };


}