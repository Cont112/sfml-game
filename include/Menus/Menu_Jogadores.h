#pragma once
#include "Menu.h"

#define PATH_MENU_JOGADORES "assets/Fundos/menu_jogadores.jpg"
#define PATH_1JOGADOR "assets/Buttons/Menu_Jogadores/1_jogador.png"
#define PATH_2JOGADOR "assets/Buttons/Menu_Jogadores/2_jogador.png

class Jogo;

namespace Menus{
    
    class Menu_Jogadores: public Menu{
    private:
        Botao jogador1;
        Botao jogador2;

    public:
        Menu_Jogadores(Jogo* jogo);
        ~Menu_Jogadores();

        void atualizar();
        void executar();
    };
}