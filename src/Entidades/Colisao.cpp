#include "../../include/Entidades/Colisao.h"
#include <iostream>
using namespace std;

namespace Entidades
{
    namespace Colisao
    {
        Colisao::Colisao():colidiu(0)
        {
            
        }
        Colisao::~Colisao()
        {

        }
        void Colisao::SetColisao(bool estado,Entidades::Entidade * c)
        {
            colidiu = estado;
            colisor = c;
        }
        bool Colisao:: bateu()
        {
            return colidiu;
        }
        Entidades::Entidade* Colisao::getColisor()
        {
            return colisor;
        }
    }
}