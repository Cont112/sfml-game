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

    void Lista_Entidades::addEntidade(Entidades::Entidade* pEntidade)
    {
        if(pEntidade != NULL)
        {
            lista=(pEntidade);
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

    Entidades::Entidade* Lista_Entidades::operator[](int posicao)
    {
        return (lista.operator[](posicao));
    }

    void Lista_Entidades::atualizar()
    {
        for (int i = 0; i<lista.getTamanho(); i++)
        {
            lista.operator[](i)->atualizar();
        }
    }

    void Lista_Entidades::limparLista()
    {
        lista.limpar();
    }

    void Lista_Entidades::removerEntidade(Entidades::Entidade* pEntidade)
    {
        lista.removerElemento(pEntidade);
    }
}