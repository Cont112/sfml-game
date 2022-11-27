#pragma once
#include "Menu.h"

#define PATH_MENU_JOGADORES "assets/Fundos/menu_jogadores.jpg"
#define PATH_SINGLEPLAYER "assets/Buttons/Menu_Jogadores/singleplayer.png"
#define PATH_MULTIPLAYER "assets/Buttons/Menu_Jogadores/multiplayer.png"

class Jogo;

namespace Menus{
    
    class Menu_Jogadores: public Menu{
    private:
        Botao singleplayer;
        Botao multiplayer;

    public:
        Menu_Jogadores(Jogo* jogo);
        ~Menu_Jogadores();

        void atualizar();
        void executar();
    };
}