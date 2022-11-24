#include "../../../include/Menus/Botao/Botao.h"

namespace Menus{
    namespace Botao{
        Botao::Botao(const std::string text, const sf::Vector2f pos):
        Ente(IDs::botao),pos(pos), tam(tam), font(), texto(), info(text)
        {
            init();   

        }


        Botao::~Botao()
        {
        }

        void Botao::init()
        {
            if(!font.loadFromFile(FONT_PATH))
                std::cout << "Nao foi possivel crirar a fonte" << std::endl;
            texto.setString(info);
            texto.setFont(font);
            texto.setFillColor(sf::Color::White);
            texto.setCharacterSize(30);
            texto.setOrigin(sf::Vector2f(texto.getGlobalBounds().width/2.0f,texto.getGlobalBounds().height/2.0f));
            texto.setPosition(sf::Vector2f(pos.x +2, pos.y -4));
            
            shape.setOrigin(sf::Vector2f(texto.getGlobalBounds().width/2.0f,texto.getGlobalBounds().height/2.0f));
            shape.setPosition(pos);
            tam = sf::Vector2f(texto.getGlobalBounds().width + 8, texto.getGlobalBounds().height+ 8);
            shape.setSize(tam);
            shape.setFillColor(sf::Color::Black);

            



        }

        sf::Vector2f Botao::getPos() 
        {
            return pos;
        }

        sf::Vector2f Botao::getTam()
        {
            return tam;
        }
        void Botao::imprimir_se()
        {
            pGrafico->render(shape);
            pGrafico->render(texto);
        }

        void Botao::atualizar()
        {
            imprimir_se();
        }
    }
}