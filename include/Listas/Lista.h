#pragma once
#include "iostream"

namespace Listas{

    template <class TL>
    class Lista{
    private:
        template <class TE>
        class Elemento {
        private:
            Elemento<TE>* pProximo;
            TE* pData;
        public:
            Elemento()
            {
                pProximo = NULL;
                pData = NULL;
            }
            ~Elemento()
            {
                pProximo = NULL;
                pData = NULL;
            }

            void setProximo (Elemento<TE>* proximo) {pProximo = proximo;}
            Elemento<TE>* getProximo () {return pProximo;}

            void setData(TE *d) {pData = d;}
            TE* getData() {return pData;}
        };

        Elemento<TL>* pPrimeiro;
        Elemento<TL>* pUltimo;
        int tamanho;

    public:
        Lista();
        ~Lista();
        
        void push_back(TL* info);
        void limpar();
        int getTamanho();

    private:
        bool empty();
        void setElemento(Elemento<TL>* pElemento);
        
    };


    template <class TL>
    Lista<TL>::Lista() : pPrimeiro(NULL), pUltimo(NULL), tamanho(0) 
    {
        limpar();
    }
    
    template <class TL>
    Lista<TL>::~Lista()
    {
        limpar();
    }
    
    template<class TL>
    void Lista<TL>::limpar()
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

    template<class TL>
    int Lista<TL>::getTamanho()
    {
        return tamanho;
    }

}