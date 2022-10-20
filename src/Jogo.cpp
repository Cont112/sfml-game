#include "../include/Jogo.h"

using namespace Gerenciadores;

Jogo::Jogo() : pGerenciadorGrafico(Graficos::getInstance())
{
    executar();
}

Jogo::~Jogo()
{ 
}

void Jogo::executar()
{
    while(pGerenciadorGrafico->isWindowOpen())
    {
        //pGerenciadorGrafico->updateDeltaTime();
        pGerenciadorGrafico->clear();
        //
        //
        pGerenciadorGrafico->display();
    }

}

