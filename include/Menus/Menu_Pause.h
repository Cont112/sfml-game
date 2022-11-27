#pragma once
#include "Menu.h"

#define PATH_MENU_PAUSE "assets/Fundos/menu_pause.jpg"
#define PATH_VOLTAR "assets/Buttons/Menu_Pause/voltar.png"
#define PATH_MENU "assets/Buttons/Menu_Pause/menu_principal.png"

class Jogo;

namespace Menus{
    
    class Menu_Pause: public Menu{
    private:
        Botao voltar;
        Botao menu_principal;

    public:
        Menu_Pause(Jogo* jogo);
        ~Menu_Pause();

        void atualizar();
        void executar();
    };
}