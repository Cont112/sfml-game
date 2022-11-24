#pragma once

#include "../../Ente.h"

#define FONT_PATH "assets/Fonts/font.ttf"

namespace Menus{
    namespace Botao{
        class Botao: public Ente{
        private:
            sf::Text texto;
            sf::Font font;
            std::string info;
            sf::Vector2f pos;
            sf::Vector2f tam;

            void init();

        public:
            Botao(const std::string text, const sf::Vector2f pos);
            ~Botao();
            
            sf::Vector2f getPos();
            sf::Vector2f getTam();    

            void imprimir_se();
            void atualizar();
        };
    }
}