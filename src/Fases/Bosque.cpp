#include "../../include/Fases/Bosque.h"

Fases::Bosque::Bosque()
{

}
Fases::Bosque::~Bosque()
{

}
void Fases::Bosque::criarMapa()
{
    criarJogador(sf::Vector2f(500.f, 0.f));
    criarInimigo(sf::Vector2f(700.f, 0.f));
    criarCaixa(sf::Vector2f(100.f, 200.f));
    criarPlataforma(sf::Vector2f(0.f, 1260.f));

}
void Fases::Bosque::criarFundo()
{
    const char* tela = "assets/nskybox.jpg";
    pGrafico->createTexture(tela);
    fundoTela.setTexture(pGrafico->textureMap.at(tela));
    fundoTela.setSize(sf::Vector2f(1280, 720));
    pGrafico->render(fundoTela);


}