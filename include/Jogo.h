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
    static Gerenciadores::Gerenciador_Eventos* pEventos;
    
    Entidades::Personagens::Jogador* j1;

public:
    Jogo();
    ~Jogo();
    void criarEntidades();
    void executar();
};