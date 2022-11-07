#include "Personagem.h"

class Inimigo : public Entidades::Personagens::Personagem{

    protected:
        bool atira;
        void init();

    public:
        Inimigo();
        ~Inimigo();
        void movimentar();

};
