#pragma once
#include "Lista.h"
#include "../Entidades/Entidade.h"

namespace Listas
{

    class ListaEntidades
    {
    private:
        Lista<Entidades::Entidade> lista;

    public:
        ListaEntidades();
        ~ListaEntidades();

        void adicionarEntidade(Entidades::Entidade* pEntidade);
        int getTamanho();
    };

}