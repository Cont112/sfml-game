#include "../../include/Listas/Lista_Entidades.h"
#include "../../include/Listas/Lista.h"

namespace Listas
{
    Lista_Entidades::Lista_Entidades()
    {}

    Lista_Entidades::~Lista_Entidades()
    {
        lista.limpar();
    }

    void Lista_Entidades::adicionarEntidade(Entidades::Entidade* pEntidade)
    {
        if(pEntidade != NULL)
        {
            lista.push_back(pEntidade);
        }

        else
        {
            std::cout << "Ponteiro para Entidade eh NULO" << std::endl;
        }
    }

    int Lista_Entidades::getTamanho()
    {
        return lista.getTamanho();
    }

}