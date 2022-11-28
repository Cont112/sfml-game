#pragma once
#include "Menu.h"
#include <vector>

#define PATH_MENU_LEADERBOARD "assets/Fundos/menu_leaderboard.jpg"
#define PATH_MENU "assets/Buttons/Menu_Pause/menu_principal.png"

class Jogo;

namespace Menus{
    
    class Menu_Leaderboard: public Menu{
    private:
        std::vector<sf::Text*> listaTextos;
        std::vector<int> listaPontos;
        sf::RectangleShape body;
        Botao menu_principal;
        bool registrou;

    public:
        Menu_Leaderboard(Jogo* jogo);
        ~Menu_Leaderboard();

        void criarTexto(int i, int n, sf::Vector2f pos);

        void registrarPontuacao(int n);
        void sortPosicao();
        void savePoints();
        void loadPoints();

        bool getRegistrou() {return registrou;}
        void atualizar();
        void executar();
    };
}