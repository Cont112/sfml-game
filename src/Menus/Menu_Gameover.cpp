#include "../../include/Menus/Menu_Gameover.h"

#include "../../include/Jogo.h"

namespace Menus{

    Menu_Gameover::Menu_Gameover(Jogo* jogo): Menu(IDs::menu_gameover, jogo),
    leaderboard(sf::Vector2f(640.f, 360.f)),
    menu_principal(sf::Vector2f(640.f, 500.f))
    {
        setTextura(PATH_MENU_GAMEOVER);
        leaderboard.setTextura(PATH_LEADERBOARD);
        menu_principal.setTextura(PATH_MENU);
    }

    Menu_Gameover::~Menu_Gameover()
    {
   
    }
    void Menu_Gameover::atualizar()
    {
        if(!cooldown && botaoClicado(leaderboard))
        {
            cooldown = true;
            jogo->setGameState(7);
        }

        if(!cooldown && botaoClicado(menu_principal))
        {
            cooldown = true;
            jogo->setGameState(0);
        }

    }

    void Menu_Gameover::executar()
    {
        imprimir_se();
        leaderboard.atualizar();
        menu_principal.atualizar();
        atualizar();
    }

}