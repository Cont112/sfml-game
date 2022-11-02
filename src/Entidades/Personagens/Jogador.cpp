#include "../../../include/Entidades/Personagens/Jogador.h"

namespace Entidades{
    namespace Personagens{
        
        Jogador::Jogador(int vi =100, int d=10, bool m=false): Personagem(vi,d,m,0,0)
        {

        }

        Jogador::~Jogador()
        {

        }
        void Jogador::executar()
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                std::cout << "-1" << std::endl;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                std::cout << "1" << std::endl;
            
        }

    }


}