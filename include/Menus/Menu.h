#pragma once

#include "../Ente.h"
#include "../Gerenciadores/Gerenciador_Eventos.h"
#include "Botao.h"


class Jogo;
namespace Menus{
    class Menu: public Ente{
    protected:
        static bool cooldown;
        static Gerenciadores::Gerenciador_Eventos* pEventos;
        Jogo* jogo;

    public:
        Menu(const IDs ID,Jogo* jogo);
        ~Menu();

        bool botaoClicado(Botao &b);

        static void setCooldown(bool c) {cooldown = c;}
        bool getCooldown() {return cooldown;}
        virtual void executar() = 0;
        virtual void atualizar() =0;
    };
}