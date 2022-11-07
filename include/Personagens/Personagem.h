#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

namespace Personagens
{
    class Personagem
    {
        protected:
            sf::RectangleShape shape;
            sf::Vector2f vel;
        public:
            Personagem(sf::Vector2f pos, sf::Vector2f tam);
            ~Personagem();
            sf::RectangleShape getShape() const;
            void setTextura(sf::Texture* texture);
            virtual void movimentar() = 0;
    };

}