#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Gerenciadores/Gerenciador_Grafico.h"
#include "Ente.h"

class Jogador:public Ente 
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
        void imprimir_se();

};