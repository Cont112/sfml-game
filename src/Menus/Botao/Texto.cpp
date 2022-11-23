#include "../../../include/Menus/Botao/Texto.h"

namespace Menus{
    namespace Botao{

        Texto::Texto(sf::Font fonte, const std::string texto): fonte(fonte), texto()
        {
            this->texto.setString(texto);
            this->texto.setFont(fonte);

        }

        Texto::~Texto() 
        {
        }

        void Texto::setString(const std::string texto)
        {
            this->texto.setString(texto);
        }

        const std::string Texto::getString()
        {  
            return texto.getString();
        }

        sf::Text Texto::getTexto()
        {
            return texto;
        }
    }
}