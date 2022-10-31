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
            Elemento<TE>* pAnterior;
            TE* pData;
        public:
            Elemento()
            {
                pProximo = NULL;
                pAnterior = NULL;
                pData = NULL;
            }
            ~Elemento()
            {
                pProximo = NULL;
                pAnterior = NULL;
                pData = NULL;
            }

            void setProximo (Elemento<TE>* proximo) {pProximo = proximo;}
            Elemento<TE>* getProximo () {return pProximo;}

            void setAnterior(Elemento<TE>* anterior) {pAnterior = anterior;}
            Elemento<TE>* getAnterior() {return pAnterior;}

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
        TL* pop_back();

    private:
        bool empty();
        void setElemento(Elemento<TL>* pElemento);
        
    };
}