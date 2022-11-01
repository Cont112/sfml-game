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

    private:
        bool empty();
        void setElemento(Elemento<TL>* pElemento);
        
    };
}