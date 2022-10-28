#include "../../include/Listas/Lista.h"
#include <stdio.h>
using namespace Listas;

template <typename TE>
Elemento<TE>::Elemento()
{
    pProx == NULL;

}
template <typename TE>
Elemento<TE>::~Elemento()
{

}
template <typename TE>
void Elemento<TE>::setProximo(Elemento<TE>* p)
{
    pProx = p;
}
template <typename TL>
Lista<TL>::Lista()
{   
    pPrimeiro = NULL;
    pUltimo = NULL;

}
template <typename TL>
Lista<TL>::~Lista()
{

}
template <typename TL>
void Lista<TL>::inserir(Elemento<TL>* p)
{
    if (pPrimeiro==NULL)
    {
        pPrimeiro = p;
        pUltimo = p;
        pUltimo->pProx=NULL;
    }
    else
    {
        pUltimo->pProx = p;
        pUltimo = p;
        pUltimo->pProx =NULL;

    }
}

