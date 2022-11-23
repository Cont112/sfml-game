#pragma once

#include "Texto.h"
#include "../../Ente.h"

#define FONT_PATH "assets/Fonts/font.ttf"

namespace Menus{
    namespace Botao{
        class Botao: public Ente{
        private:
            bool selecionado;
            Texto texto;

        public:
            Botao(const std::string text);
            ~Botao();
            
            void imprimir_se();
            void atualizar() {}
        };
    }
}