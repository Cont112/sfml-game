#pragma once

#include "../Ente.h"
#include "Botao/Botao.h"
#include <list>

namespace Menus{
    class Menu: public Ente{
    private:
        sf::Texture textura;
        std::list<Botao::Botao*> listaBotao;
        std::list<Botao::Botao*>::iterator it;
    public:
        Menu(const IDs ID);
        ~Menu();

        void addBotao(std::string text);
        void imprimir_se();
        virtual void executar() = 0;
    };
}