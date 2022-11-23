#pragma once

#include "Menu.h"
#include "Botao/Texto.h"

#define PATH_MENU_PRINCIPAL "assets/barreto.jpg"

namespace Menus{
    class Menu_Principal: public Menu{
    private:
        void criarFundo();
        void criarBotoes();
    public:
        Menu_Principal();
        ~Menu_Principal();    

        void atualizar();
    };
}