#include "../../../include/Entidades/Personagens/Jogador.h"

namespace Entidades{
    namespace Personagens{
        
        Jogador::Jogador(int vi=100, int d=10, bool m=false): Personagem(vi,d,m)
        { 
            Entidade(sf::Vector2f(100.f, 100.f));

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