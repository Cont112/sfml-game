#include "../../../include/Entidades/Personagens/Jogador.h"

namespace Entidades{
    namespace Personagens{
        
        Jogador::Jogador(int vida, int dano, bool morto, sf::Vector2f v): Ṕersonagem(vida,dano,morto,v){ 

        }
        void Jogador::movimentar(){
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                move(-this->velocidade.x, 0.f);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                move(this->velocidade.x, 0.f);
        

        }




    }


}