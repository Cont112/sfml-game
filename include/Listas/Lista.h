namespace Listas{

    template <typename TE>
    class Elemento{
    private:
        Elemento<TE>* pProx;
        <TE>* data;

    public:
        Elemento();
        ~Elemento();
        void setData(<TE>* d);

    };

    template <typename TL>
    class Lista{
    private:
        Elemento<TL>* pPrimeiro;
        Elemento<TL>* pUltimo;
    public:
        
        Lista();
        ~Lista();
        void inserir(Elemento<TL>* El);
        
    };






}