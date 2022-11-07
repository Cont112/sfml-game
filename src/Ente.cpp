#include "../include/Ente.h"

Ente::Ente(): pGra(Gerenciadores::Gerenciador_Grafico::getInstance()),id(0){
        
}

Ente::~Ente(){
}
void Ente::setId(int i)
{
    id = i;
}