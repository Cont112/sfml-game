#pragma once
#include "Menu.h"

#define PATH_MENU_GAMEOVER "assets/Fundos/menu_gameover.jpg"
#define PATH_LEADERBOARD "assets/Buttons/Menu_Gameover/leaderboard.png"

class Jogo;

namespace Menus{
    
    class Menu_Gameover: public Menu{
    private:
        Botao leaderboard;
        Botao menu_principal;

    public:
        Menu_Gameover(Jogo* jogo);
        ~Menu_Gameover();

        void atualizar();
        void executar();
    };
}