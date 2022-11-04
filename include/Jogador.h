#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Jogador
{
    private:
        sf::RectangleShape shape;
        sf::Vector2f vel;

        void init();
    public:
        Jogador();
        ~Jogador();
        sf::RectangleShape getShape() const;
        void setTextura(sf::Texture* texture);
        void movimentar();

};