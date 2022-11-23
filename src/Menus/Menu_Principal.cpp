#include "../../include/Menus/Menu_Principal.h"

namespace Menus{
    
    Menu_Principal::Menu_Principal(): Menu(IDs::menu_principal)
    {
        criarFundo();
    }

    Menu_Principal::~Menu_Principal()
    {
    }
    
    void Menu_Principal::criarBotoes()
    {

    }

    void Menu_Principal::criarFundo()
    {
        pGrafico->createTexture(PATH_MENU_PRINCIPAL);
        shape.setTexture(pGrafico->textureMap.at(PATH_MENU_PRINCIPAL));
    }

    void Menu_Principal::atualizar()
    {
        imprimir_se();
    }
}