#pragma once

#include "../Listas/Lista_Entidades.h"

namespace Fases{
    class Fase{
    protected:
        Listas::Lista_Entidades lista;

    public:
        Fase();
        ~Fase();

        void gerenciar_colisoes();
        virtual void executar() = 0;
        virtual void inicializar_entidades() =0;

   };
}