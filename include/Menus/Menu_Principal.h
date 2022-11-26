#pragma once
#include "Menu.h"

#define PATH_MENU_PRINCIPAL "assets/bosque.jpg"
#define PATH_JOGAR "assets/lava.png"
#define PATH_SAIR "assets/barreto.jpg"

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