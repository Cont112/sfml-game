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
            imprimir_se();
            movimentar();
        }

        void Jogador::movimentar()
        {
            sprite->move(velocidade);
        }
    }


}