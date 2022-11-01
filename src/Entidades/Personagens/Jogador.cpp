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

        }
        void Jogador::movimentar(){
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                sprite->move(-this->velocidade.x, 0.f);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                sprite->move(this->velocidade.x, 0.f);
        }

    }


}