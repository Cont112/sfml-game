#include "../../include/Menus/Botao.h"

namespace Menus{
        Botao::Botao(const sf::Vector2f pos):
        Ente(IDs::botao),pos(pos), tam(BUTTON_SIZE_X,BUTTON_SIZE_Y)
        {
            init();   

        }

        Botao::~Botao()
        {
        }

        void Botao::init()
        {
            shape.setOrigin(sf::Vector2f(tam.x/2.0f, tam.y/2.0f));
            shape.setPosition(pos);
            shape.setSize(tam);
            shape.setFillColor(sf::Color::White);

        }

        sf::Vector2f Botao::getPos() 
        {
            return pos;
        }

        sf::Vector2f Botao::getTam()
        {
            return tam;
        }
        void Botao::imprimir_se()
        {
            pGrafico->render(shape);
        }

        void Botao::atualizar()
        {
            imprimir_se();
        }
}