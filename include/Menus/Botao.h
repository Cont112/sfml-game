#pragma once

#include "../Ente.h"

#define BUTTON_SIZE_X 200
#define BUTTON_SIZE_Y 50

namespace Menus{
        class Botao: public Ente{
        private:
            sf::Vector2f pos;
            sf::Vector2f tam;

            void init();

        public:
            Botao(const sf::Vector2f pos);
            ~Botao();
            
            sf::Vector2f getPos();
            sf::Vector2f getTam();    

            void imprimir_se();
            void atualizar();
        };
}