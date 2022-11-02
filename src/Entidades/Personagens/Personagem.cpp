#include "../../../include/Entidades/Personagens/Personagem.h"

namespace Entidades {
    namespace Personagens{

        Personagem::Personagem(int vi=100, int d=10, bool m=false, float vx =0, float vy =0 ): Entidade()
        {
            
            vida=vi;
            dano=d;
            morto =m;
            velocidade.x = vx;
            velocidade.y = vy;
            
        }

        Personagem::~Personagem()
        {
           
        }
        sf::Vector2f Personagem::getVelocidade() const
        {
            return velocidade;
        }
    
        void Personagem::setVelocidade (sf::Vector2f v)
        {
            velocidade.x = v.x;
            velocidade.y = v.y;
        }
        void Personagem::setMorto(bool m)
        {
            morto = m;
        }
        void Personagem::setVida (int v)
        {
            vida = v;
        }
        void Personagem::setDano(int d)
        {
            dano = d;
        }

        int Personagem::getVida()const
        {
            return vida;
        }
    }
}