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

            void setProximo (Elemento<TL>* proximo) 
            {
                pProximo = proximo;
            }
            
            Elemento<TE>* getProximo () 
            {
                return pProximo;
            }

            void setData(TE *d) 
            {
                pData = d;
            }
            
            TE* getData() 
            {
                return pData;
            }
        };

        Elemento<TL>* pPrimeiro;
        Elemento<TL>* pUltimo;
        int tamanho;

    public:
        Lista();
        ~Lista(); 
        void limpar();
        bool empty();
        void addElemento(TL* pElemento);
        int getTamanho();
        TL* operator[](int pos);
        
    };


    template <class TL>
    Lista<TL>::Lista() : pPrimeiro(NULL), pUltimo(NULL), tamanho(0) 
    {
        
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
            if(paux)
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
    void Lista<TL>::addElemento(TL* pElemento)
    {
        Elemento<TL>* novo = new Elemento<TL>();
        novo->setData(pElemento);
        
        if(pElemento != NULL)
        {
            if(empty())
            {
                pPrimeiro=novo;
                pUltimo=novo;
            }
            else
            {
                pUltimo->setProximo(novo);
                pUltimo=novo;
            }
        }
        tamanho++;

        //else
            //std::cout << "Erro: Nao foi possivel setar o elemento na lista (Lista<TL>::setElemento)." << std::endl;
    }

    template<class TL>
    int Lista<TL>::getTamanho()
    {
        return tamanho;
    }

    template<class TL>
    TL* Lista<TL>::operator[](int pos)
    {
        Elemento<TL>* aux = pPrimeiro;
        for (int i =0 ; i<pos; i++)
        {
            aux= aux->getProximo();
        }
        return aux->getData();
    }
}