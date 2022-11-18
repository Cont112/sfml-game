#include "../Entidades/Personagens/Jogador.h"
#include "../Entidades/Personagens/Inimigo.h"
#include "../Entidades/Colisao.h"
#include "../Listas/Lista_Entidades.h"
#include <math.h>


namespace Gerenciadores{
    class Gerenciador_Colisoes{

        private:
            Listas::Lista_Entidades *listaMoveis;
            Listas::Lista_Entidades *listaFixos;
        public:
            Gerenciador_Colisoes();
            Gerenciador_Colisoes(Listas::Lista_Entidades* l1, Listas::Lista_Entidades* l2);
            ~Gerenciador_Colisoes();
            sf::Vector2f calculaDistancia(Entidades::Entidade *ente1,Entidades::Entidade *ente2 );
            void setListas(Listas::Lista_Entidades *lm,Listas::Lista_Entidades *lf );
            void executar();    
    };
}