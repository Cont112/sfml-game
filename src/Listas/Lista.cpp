#include "../../include/Listas/Lista.h"

namespace Listas
{
    template <class TL>
    Lista<TL>::Lista() : pPrimeiro(NULL), pUltimo(NULL), tamanho(0) {}
    
    template <class TL>
    Lista<TL>::~Lista()
    {
        Elemento<TL>* paux;
        paux = pPrimeiro;

        while(pPrimeiro != NULL)
        {
            pPrimeiro = pPrimeiro->getProximo();
            delete paux;
            paux = pPrimeiro;
            tamanho--;
        }

        pPrimeiro = NULL;
        pUltimo = NULL;
    }
    
    template<class TL>
    bool Lista<TL>::empty()
    {
        return (pPrimeiro == NULL && tamanho == 0);
    }

    template <class TL>
    void Lista<TL>::setElemento(Elemento<TL>* pElemento)

    {
        if(pElemento != NULL)
        {
            if(empty())
            {
                pPrimeiro = pElemento;
                pUltimo = pPrimeiro;
            }
            else
            {
                pUltimo->setProximo(pElemento);
                pUltimo = pElemento;
            }
        }

        else
        {
            std::cout << "Erro: Nao foi possivel setar o elemento na lista (Lista<TL>::setElemento)." << std::endl;
        }
    }

    template <class TL>
    void Lista<TL>::push_back(TL* info)
    {

        if(info != NULL)
        {
            Elemento<TL>* elemento = new Elemento<TL>;
            elemento->setData(info);
            setElemento(elemento);
        }
        else
        {
            std::cout << "Erro: Nao foi possivel pushar para a lista. Ponteiro eh nulo! (Lista<TL>::push)" << std::endl;
        }

    }


}

