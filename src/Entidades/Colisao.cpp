#include "../../include/Entidades/Colisao.h"

namespace Entidades
{
    namespace Colisao
    {
        Colisao::Colisao():frontal(false), superior(false)
        {
            
        }
        Colisao::~Colisao()
        {

        }
        void Colisao::SetColisao(int tipo, bool estado)
        {
            if (tipo ==1)
                frontal = estado;
            if (tipo ==2)
                superior = estado;
        }
        bool Colisao::GetColisaoFrontal()
        {
            return frontal;
        }
        bool Colisao::GetColisaoSuperior()
        {
            return superior;
        }
        void Colisao::setColisor(Entidades::Entidade *e)
        {
            C = e;
        }
        Entidades::Entidade* Colisao::getColisor()
        {
            return C;
        }
    }
}