#pragma once

#include <SFML/Graphics.hpp>

namespace Menus{
    namespace Botao{
        class Texto{
        private:
            sf::Text texto;
            sf::Font fonte;

        public:
            Texto(sf::Font fonte, const std::string texto = "");
            ~Texto();

            sf::Text getTexto();
            void setString(const std::string texto);
            const std::string getString();
        };
    }
}