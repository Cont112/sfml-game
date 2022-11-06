#include "../include/Ente.h"

Ente::Ente(Gerenciadores::Gerenciador_Grafico *p):id(0){
        pGra = p;
}

Ente::~Ente(){
}
void Ente::setId(int i)
{
    id = i;
}