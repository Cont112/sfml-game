#include "../../../include/Entidades/Personagens/Personagem.h"

namespace Entidades {
    namespace Personagens{

        Personagem::Personagem(int vi=100, int d=10, bool m=false ): Entidade()
        {
            //terminar de incializar 
            vida=vi;
            dano=d;
            morto =m;
            
        }

        Personagem::~Personagem()
        {
            vida = 0;
            morto = true;
        }
    
        void Personagem::setVelocidade (Fisica::CoordF v)
        {
            velocidade.x = v.x;
            velocidade.y= v.y;
        }
        Fisica::CoordF Personagem:: getVelocidade() const
        {
            return velocidade;
        }
    }
}