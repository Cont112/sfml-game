#pragma once
#include "../stdafx.h"


class Jogo
{
private:

    Listas::Lista_Entidades lista;
    Listas::Lista_Entidades listaFixos;
    Listas::Lista_Entidades listaMoveis;    
    Gerenciadores::Gerenciador_Grafico* pGrafico;
    


public:
    Jogo();
    ~Jogo();
    void criarEntidades();
    void executar();
};