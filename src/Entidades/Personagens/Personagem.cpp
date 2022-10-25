#include "../../../include/Entidades/Personagens/Personagem.h"

namespace Entidades {
    namespace Personagens{

        Personagem::Personagem(): Entidade(), vida(100), dano(10), morto(false)
        {
        }

        Personagem::~Personagem()
        {
            vida = 0;
            morto = true;
        }
    }
}