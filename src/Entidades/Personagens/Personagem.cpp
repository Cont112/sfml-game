#include "../../../include/Entidades/Personagens/Personagem.h"

namespace Entidades{
    namespace Personagens{

        Personagem::Personagem()
        {
        }

        Personagem::~Personagem()
        {
        }

        int Personagem::getDano() const{
            return dano;
        }

        int Personagem::getVida() const {
            return vida;
        }

        void Personagem::setDano(int d){
            dano = d;
        }

        void Personagem::setVida(int v){
            vida = v;
        }
    }
}


