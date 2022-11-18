#pragma once
#include "../stdafx.h"


class Jogo
{
private:
    int gamestate;

    Listas::Lista_Entidades *lista;
    Listas::Lista_Entidades *listaFixos;
    Listas::Lista_Entidades *listaMoveis;

    static Gerenciadores::Gerenciador_Grafico* pGrafico;
    Gerenciadores::Gerenciador_Colisoes* pColisao;
    


public:
    Jogo();
    ~Jogo();
    void criarEntidades();
    void executar();
};