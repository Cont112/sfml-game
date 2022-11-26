#pragma once

#include "../Ente.h"

#define FONT_PATH "assets/Fonts/font.ttf"
#define BUTTON_SIZE_X 400
#define BUTTON_SIZE_Y 100

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