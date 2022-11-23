#include "../../include/Menus/Menu.h"

namespace Menus{

    Menu::Menu(const IDs ID): Ente(ID), listaBotao(), it(), textura()
    {
        shape.setSize((sf::Vector2f)pGrafico->getWindow()->getSize());
        shape.setPosition(sf::Vector2f(0.0f,0.0f));
    }

    Menu::~Menu()
    {
        if(!listaBotao.empty())
        {
            for(it = listaBotao.begin(); it != listaBotao.end(); it++)
            {
                delete(*it);
            }
            listaBotao.clear();
        }
    }

    void Menu::addBotao(const std::string text)
    {
        Botao::Botao* botao = new Botao::Botao(text);
        if(botao == nullptr)
        {
            std::cout << "Menu.cpp: Nao foi possivel criar botao" << std::endl;
        }

        listaBotao.push_back(botao);
    }

    void Menu::imprimir_se()
    {
        pGrafico->render(shape);
        for(it = listaBotao.begin(); it != listaBotao.end(); it++)
        {
            Botao::Botao* botao = *it;
            botao->imprimir_se();
            botao = nullptr;
        }
    }
}