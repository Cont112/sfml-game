#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../Gerenciadores/Gerenciador_Grafico.h"
#include "../../Ente.h"
#include "../Entidade.h"

namespace Entidades { 
namespace Personagens{ 

class Jogador:public Entidade
{
    private:
        void init();
    public:
        Jogador();
        ~Jogador();
        void movimentar();
        void executar();
        

};
}}