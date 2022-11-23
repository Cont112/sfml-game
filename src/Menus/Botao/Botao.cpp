#include "../../../include/Menus/Botao/Botao.h"

namespace Menus{
    namespace Botao{
        Botao::Botao(const std::string text):Ente(IDs::botao), selecionado(0), texto(pGrafico->loadFont(FONT_PATH),text)
        {
        }

        Botao::~Botao()
        {
        }

        void Botao::imprimir_se()
        {
            pGrafico->render(shape);
            pGrafico->render(texto.getTexto());
        }
    }
}