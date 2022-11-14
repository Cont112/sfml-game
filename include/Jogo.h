#pragma once

#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Personagens/Inimigo.h"
#include "Entidades/Obstaculos/Obstaculo.h"
#include "Gerenciadores/Gerenciador_Grafico.h"
#include "Ente.h"
#include "Listas/Lista.h"
#include "Listas/Lista_Entidades.h"
#include <vector>


class Jogo
{
private:

    Entidades::Personagens::Jogador* j1;
    Entidades::Personagens::Inimigo* i1;
    Entidades::Obstaculos::Obstaculo* chao;

    Listas::Lista_Entidades lista;    
    Gerenciadores::Gerenciador_Grafico* pGrafico;
    


public:
    Jogo();
    ~Jogo();
    void criarEntidades();
    void executar();
};