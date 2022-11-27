#include "../../include/Menus/Menu_Pause.h"

#include "../../include/Jogo.h"

namespace Menus{

    Menu_Pause::Menu_Pause(Jogo* jogo): Menu(IDs::menu_principal, jogo),
    voltar(sf::Vector2f(640.f,360.f)),
    menu_principal(sf::Vector2f(640.f, 500.f))
    {
        setTextura(PATH_MENU_PAUSE);
        voltar.setTextura(PATH_VOLTAR);
        menu_principal.setTextura(PATH_MENU);
    }

    Menu_Pause::~Menu_Pause()
    {
   
    }

    void Menu_Pause::atualizar()
    {
        if(!cooldown && botaoClicado(voltar))
        {
            cooldown = true;
            jogo->setGameState(jogo->getLastGameState());
        }

        if(!cooldown && botaoClicado(menu_principal))
        {
            cooldown = true;
            jogo->setGameState(0);
        }

    }

    void Menu_Pause::executar()
    {
        imprimir_se();
        voltar.atualizar();
        menu_principal.atualizar();
        atualizar();
    }

}