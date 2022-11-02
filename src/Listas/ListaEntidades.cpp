#include "../../include/Listas/ListaEntidades.h"

namespace Listas
{
    ListaEntidades::ListaEntidades()
    {}

    ListaEntidades::~ListaEntidades()
    {
        lista.limpar();
    }

    void ListaEntidades::adicionarEntidade(Entidades::Entidade* pEntidade)
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

    int ListaEntidades::getTamanho()
    {
        return lista.getTamanho();
    }

}