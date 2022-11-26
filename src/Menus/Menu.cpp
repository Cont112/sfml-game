#include "../../include/Menus/Menu.h"

namespace Menus{

    Gerenciadores::Gerenciador_Eventos* Menu::pEventos = Gerenciadores::Gerenciador_Eventos::getInstance();

    Menu::Menu(const IDs ID, Jogo* jogo): Ente(ID), jogo(jogo)
    {
        shape.setPosition(sf::Vector2f(0.0f,0.0f));
        shape.setSize((sf::Vector2f)pGrafico->getWindow()->getSize());
    }

    Menu::~Menu()
    {
    }

    bool Menu::botaoClicado(Botao &b)
    {
        int bX = b.getPos().x;
        int bY = b.getPos().y;
        int bW = b.getTam().x;
        int bH = b.getTam().y;

        int mouseX = pEventos->getMousePosition().x;
        int mouseY = pEventos->getMousePosition().y;

        if (pEventos->getMouseClick() && mouseX < bX + bW/2.0f && mouseX > bX - bW/2.0f && mouseY > bY - bH/2.0f && mouseY < bY + bH/2.0f)
        {
            return true;
        }

        return false;
    }
}