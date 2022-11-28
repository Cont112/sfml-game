#include "../../include/Menus/Menu_Leaderboard.h"

#include "../../include/Jogo.h"
#include "fstream"

namespace Menus{

    Menu_Leaderboard::Menu_Leaderboard(Jogo* jogo): Menu(IDs::menu_leaderboard, jogo),
    menu_principal(sf::Vector2f(80.f, 50.f)), listaTextos(), listaPontos(),body(), registrou(false)
    {
        loadPoints();
        
        sortPosicao();

        setTextura(PATH_MENU_PAUSE);
        menu_principal.setTextura(PATH_MENU);

        body.setPosition(sf::Vector2f(640.f, 360.f));
        body.setSize(sf::Vector2f(300.f,600.f));
        body.setOrigin(sf::Vector2f(150.f,300.f));
        body.setFillColor(sf::Color::White);

    }

    Menu_Leaderboard::~Menu_Leaderboard()
    {
        savePoints();
        std::vector<sf::Text*>::iterator it;
        for(it = listaTextos.begin(); it != listaTextos.end(); it++)
        {
            delete *it;
        }
        listaPontos.clear();
        listaTextos.clear();
    }

    void Menu_Leaderboard::atualizar()
    {
        pGrafico->render(body);
        for(int i = 0; i < listaTextos.size(); i++)
        {
            pGrafico->render(*listaTextos[i]);
        }

        if(!cooldown && botaoClicado(menu_principal))
        {
            cooldown = true;
            jogo->getFase(IDs::bosque)->resetar();
            jogo->getFase(IDs::castelo)->resetar();
            jogo->setGameState(0);
        }

    }

    void Menu_Leaderboard::executar()
    {
        imprimir_se();
        menu_principal.atualizar();
        atualizar();
    }

    void Menu_Leaderboard::criarTexto(int i,int n, sf::Vector2f pos)
    {
        sf::Text* text = new sf::Text();


        text->setFont(*pGrafico->loadFont());
        text->setString(std::to_string(i) + ".   " + std::to_string(n) + "s");
        text->setCharacterSize(18);
        text->setFillColor(sf::Color::Black);
        text->setOrigin(sf::Vector2f(text->getLocalBounds().width/2.0f,text->getLocalBounds().height/2.0f));
        text->setPosition(pos);

        

        listaTextos.push_back(text);
    }

    void Menu_Leaderboard::sortPosicao()
    {
        
        sf::Vector2f pos = sf::Vector2f(640.0f,70.0f);
        for(int i = 0; i < listaPontos.size() ; i++)
        {
            criarTexto(i+1, listaPontos[i], sf::Vector2f(pos.x, pos.y + i*40));
        }
    }

    void Menu_Leaderboard::registrarPontuacao(int n)
    {

        registrou = true;
        std::cout << "registrou" << std::endl;
        listaPontos.push_back(n);
        criarTexto(listaPontos.size(), n, sf::Vector2f(640.0f, 70.0f + 40*(listaPontos.size() - 1)));
    }
    
    void Menu_Leaderboard::savePoints()
    {
        std::ofstream arq;
        arq.open("ld", std::ofstream::out | std::ofstream::trunc );
        for(int i = 0; i < listaPontos.size(); i++)
        {
            arq << listaPontos[i] << " ";
        }
        arq.close();
    }

    void Menu_Leaderboard::loadPoints()
    {
        std::ifstream arq;
        int i;
        arq.open("ld", std::ifstream::in);
        while (!arq.eof())
        {
            arq >> i;
            listaPontos.push_back(i);
        }
        arq.close();
        
    }

}