#pragma once
#include "Menu.h"

#define PATH_MENU_PRINCIPAL "assets/Fundos/menu_principal.jpg"
#define PATH_JOGAR "assets/Buttons/Menu_Principal/jogar.png"
#define PATH_SAIR "assets/Buttons/Menu_Principal/sair.png"

class Jogo;

namespace Menus{
    
    class Menu_Principal: public Menu{
    private:
        Botao jogar;
        Botao sair;

    public:
        Menu_Principal(Jogo* jogo);
        ~Menu_Principal();

        void atualizar();
        void executar();
    };
}