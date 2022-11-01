#include "Lista.h"
#include "../Entidades/Entidade.h"
namespace Listas
{

    class ListaEntidades
    {
    public:
        Lista<Entidades::Entidade> LE;
        ListaEntidades();
        ~ListaEntidades();
    };

}