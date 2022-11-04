#include "../include/Jogo.h"


Jogo::Jogo(): pGrafico(Gerenciadores::Gerenciador_Grafico::getInstance()) , j1()
{
    executar();
}

Jogo::~Jogo()
{
}

void Jogo::executar()
{

    const char* path = "assets/images.jpeg";

    sf::RectangleShape* shape = new sf::RectangleShape(sf::Vector2f(100.0f,100.0f));

    sf::Texture texture;

    if(!texture.loadFromFile(path))
        std::cout << "Nao foi possivel carregar a textura" << std::endl;
    else
        std::cout << "Textura carregada com sucesso!" << std::endl;
    
    j1.setTextura(&texture);

    
    while(pGrafico->isWindowOpen())
    {

        pGrafico->handleEvent();
        pGrafico->updateDeltaTime();
        pGrafico->clear();

        pGrafico->render(j1.getShape());
        j1.movimentar();
       
        pGrafico->display();        
    }

}

