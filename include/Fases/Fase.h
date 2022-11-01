#include "../Ente.h"
namespace Fases{

    class Fase : public Ente{
    protected:
        
    public:
        virtual void executar();
        void gerenciar_colisoes();
    };

}