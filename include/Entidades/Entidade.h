#pragma once
#include "../Ente.h"
#include "SFML/Graphics.hpp"

namespace Entidades {

    class Entidade : public sf::RectangleShape , public Ente {

        protected:
        sf::FloatRect hitbox;

        public:
            Entidade(const sf::Vector2f size);
            Entidade();
            ~Entidade();


            void setHitbox(const sf::FloatRect &h);
            sf::FloatRect getHitbox() const;

    };


}