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
        Entidades::Entidade* operator[](int posicao);
        void executar();
    };

}