#include "../../include/Menus/Menu_Gameover.h"

#include "../../include/Jogo.h"

namespace Menus{

    Menu_Gameover::Menu_Gameover(Jogo* jogo): Menu(IDs::menu_gameover, jogo),
    salvar(sf::Vector2f(640.f, 360.f))
    {
        setTextura(PATH_MENU_GAMEOVER);
        salvar.setTextura(PATH_SALVAR);
    }

    Menu_Gameover::~Menu_Gameover()
    {
   
    }

    void Menu_Gameover::atualizar()
    {
        if(!cooldown && botaoClicado(salvar))
        {
            cooldown = true;
            jogo->setGameState(0);
            //salvar
        }

    }

    void Menu_Gameover::executar()
    {
        imprimir_se();
        salvar.atualizar();
        atualizar();
    }

}