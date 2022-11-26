#pragma once
#include "Menu.h"

#define PATH_MENU_FASES "assets/Fundos/menu_fases.jpg"
#define PATH_FASE1 "assets/Buttons/Menu_Fases/fase1.png"
#define PATH_FASE2 "assets/Buttons/Menu_Fases/fase2.png"

class Jogo;

namespace Menus{
    
    class Menu_Fases: public Menu{
    private:
        Botao fase1;
        Botao fase2;

    public:
        Menu_Fases(Jogo* jogo);
        ~Menu_Fases();

        void atualizar();
        void executar();
    };
}