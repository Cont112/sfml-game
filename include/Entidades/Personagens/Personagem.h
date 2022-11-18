#include "../Entidade.h"

namespace Entidades{ 
namespace Personagens { 

class Personagem:public Entidade{
    protected:
        int vida;
        int dano;
    public:
        Personagem ();
        ~Personagem();
        int getVida() const;
        int getDano() const;
        void setDano(int d);
        void setVida(int v);
};

}
}