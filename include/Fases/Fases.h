#include "../Ente.h"
namespace Fases{

    class Fase : public Ente{
    public:
        virtual void executar();
        void gerenciar_colisoes();
    };

}