#include "../include/Jogo.h"

using namespace Gerenciadores;

Jogo::Jogo() : pGrafico(Graficos::getInstance())
{
    executar();
}

Jogo::~Jogo()
{
}

void Jogo::executar()
{

    while(pGrafico->isWindowOpen())
    {
        pGrafico->updateDeltaTime();
        pGrafico->clear();
        //
        //
        pGrafico->display();
    }
}

