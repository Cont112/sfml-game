#pragma once
#include "Lista.h"
#include "../Entidades/Entidade.h"

namespace Listas
{

    class Lista_Entidades
    {
    private:
        Lista<Entidades::Entidade> lista;

    public:
        Lista_Entidades();
        ~Lista_Entidades();
        void addEntidade(Entidades::Entidade* pEntidade);
        int getTamanho();
        void limparLista();
        Entidades::Entidade* operator[](int posicao);
        void atualizar();
    };

}