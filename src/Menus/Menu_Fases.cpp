#include "../../include/Menus/Menu_Fases.h"

#include "../../include/Jogo.h"

namespace Menus{

    Menu_Fases::Menu_Fases(Jogo* jogo): Menu(IDs::menu_fases, jogo),
    fase1(sf::Vector2f(640.f,360.f)),
    fase2(sf::Vector2f(640.f, 500.f))
    {
        setTextura(PATH_MENU_FASES);
        fase1.setTextura(PATH_FASE1);
        fase2.setTextura(PATH_FASE2);
    }

    Menu_Fases::~Menu_Fases()
    {
   
    }

    void Menu_Fases::atualizar()
    {
        if(!cooldown && botaoClicado(fase1))
        {
            cooldown = true;
            jogo->setGameState(4);
        }

        if(!cooldown && botaoClicado(fase2))
        {
            cooldown = true;
            jogo->setGameState(5);
        }

    }

    void Menu_Fases::executar()
    {
        imprimir_se();
        fase1.atualizar();
        fase2.atualizar();
        atualizar();
    }

}