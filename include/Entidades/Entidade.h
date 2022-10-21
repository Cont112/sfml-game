#pragma once
#include "../Ente.h"
#include "SFML/Graphics.hpp"
#include "../Fisica/CoordTL.h"

namespace Entidades {

    class Entidade : public Ente {
        protected:
        Fisica::CoordF pos;
        sf::Texture* texture;
        sf::RectangleShape* hitbox;
        //TEXTURA

        public:
            Entidade();
            ~Entidade();

    };


}