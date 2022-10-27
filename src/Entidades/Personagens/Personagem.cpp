#include "../../../include/Entidades/Personagens/Personagem.h"

namespace Entidades {
    namespace Personagens{

        Personagem::Personagem(int vida, int dano, bool morto, sf::Vector2f v ): Entidade(), vida(vida), dano(dano), morto(morto), velocidade(v)
        {
            //terminar de incializar 
        
        }

        Personagem::~Personagem()
        {
            vida = 0;
            morto = true;
        }
    
        void Personagem::setVelocidade (sf::Vector2f v)
        {
            velocidade.x = v.x;
            velocidade.y= v.y;
        }
        sf::Vector2f Personagem:: getVelocidade() const
        {
            return velocidade;
        }
    }
}