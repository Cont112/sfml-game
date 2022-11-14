#include "../Entidades/Personagens/Jogador.h"
#include "../Entidades/Personagens/Inimigo.h"
#include "../Listas/Lista.h"
#include "../Listas/Lista_Entidades.h"
#include <math.h>

class Gerenciador_Colisoes{

    private:
        Listas::Lista_Entidades listaMoveis;
        Listas::Lista_Entidades listaFixos;
    public:
        Gerenciador_Colisoes();
        ~Gerenciador_Colisoes();
        sf::Vector2f calculaDistancia(Entidades::Entidade *ente1,Entidades::Entidade *ente2 );





};