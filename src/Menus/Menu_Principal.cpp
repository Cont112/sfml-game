#include "../../include/Menus/Menu_Principal.h"

#include "../../include/Jogo.h"

namespace Menus{

    Menu_Principal::Menu_Principal(Jogo* jogo): Menu(IDs::menu_principal, jogo),
    jogar(sf::Vector2f(640.f,360.f)),
    sair(sf::Vector2f(640.f, 500.f))
    {
        setTextura(PATH_MENU_PRINCIPAL);
        jogar.setTextura(PATH_JOGAR);
        sair.setTextura(PATH_SAIR);
    }

    Menu_Principal::~Menu_Principal()
    {
   
    }

    void Menu_Principal::atualizar()
    {
        if(!cooldown && botaoClicado(jogar))
        {
            cooldown = true;
            jogo->setGameState(1);
        }

        if(!cooldown && botaoClicado(sair))
        {
            cooldown = true;
            jogo->setGameState(7);
        }

    }

    void Menu_Principal::executar()
    {
        imprimir_se();
        jogar.atualizar();
        sair.atualizar();
        atualizar();
    }

}