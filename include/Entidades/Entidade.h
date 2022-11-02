#pragma once
#include "../Ente.h"
#include <SFML/Graphics.hpp>


namespace Entidades {

    class Entidade : public Ente
    {
        protected:
            //pode usar vetor ?
            int x;
            int y;

            sf::Sprite sprite;
            

        public:
            Entidade(int posx = 0 , int posy = 0);
            ~Entidade();

            virtual void executar() = 0;
            void imprimir_se();
            sf::Sprite getSprite() const;


    };


}