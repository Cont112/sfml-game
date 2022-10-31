#pragma once
#include "../Ente.h"


namespace Entidades {

    class Entidade : public Ente
    {
        protected:
            int x;
            int y;
            //pode usar vetor ?
            sf::Sprite* sprite;
            

        public:
            Entidade();
            ~Entidade();

            void render()override;

    };


}