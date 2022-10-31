#include "../../../include/Entidades/Personagens/Jogador.h"

namespace Entidades{
    namespace Personagens{
        
        Jogador::Jogador(int vi, int d, bool m): Personagem(vi,d,m)
        {
        }

        Jogador::Jogador(): Personagem(100,20,false)
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
                move(-this->velocidade.x, 0.f);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                move(this->velocidade.x, 0.f);
        }

    }


}