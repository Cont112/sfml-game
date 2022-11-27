#include "../../include/Menus/Menu_Jogadores.h"

#include "../../include/Jogo.h"

namespace Menus{

    Menu_Jogadores::Menu_Jogadores(Jogo* jogo): Menu(IDs::menu_jogadores, jogo),
    singleplayer(sf::Vector2f(640.f,360.f)),
    multiplayer(sf::Vector2f(640.f, 500.f))
    {
        setTextura(PATH_MENU_JOGADORES);
        singleplayer.setTextura(PATH_SINGLEPLAYER);
        multiplayer.setTextura(PATH_MULTIPLAYER);
    }

    Menu_Jogadores::~Menu_Jogadores()
    {
   
    }

    void Menu_Jogadores::atualizar()
    {
        if(!cooldown && botaoClicado(singleplayer))
        {
            cooldown = true;
            jogo->getFase(IDs::bosque)->doisJogadores(false);
            jogo->getFase(IDs::castelo)->doisJogadores(false);
            jogo->setGameState(2);
            
        }

        if(!cooldown && botaoClicado(multiplayer))
        {
            cooldown = true;
            jogo->getFase(IDs::bosque)->doisJogadores(true);
            jogo->getFase(IDs::castelo)->doisJogadores(true);
            jogo->getFase(IDs::bosque)->resetar();
            jogo->getFase(IDs::castelo)->resetar();
            jogo->setGameState(2);
        }

    }

    void Menu_Jogadores::executar()
    {
        imprimir_se();
        singleplayer.atualizar();
        multiplayer.atualizar();
        atualizar();
    }

}