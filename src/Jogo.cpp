#include "../include/Jogo.h"
using namespace std;
#define WIDTH 1280
#define HEIGHT 720

Jogo::Jogo(): pGrafico(Gerenciadores::Gerenciador_Grafico::getInstance())
{
    executar();
}

Jogo::~Jogo()
{
    pGrafico->~Gerenciador_Grafico();
    std::cout << "Jogo fechou!" << std::endl;
}

void Jogo::executar()
{
    criarEntidades();      
    //loop principal 
    while(pGrafico->isWindowOpen())
    {
        pGrafico->executar();
        lista.executar();
        pGrafico->display(); 
        
    }


}
void Jogo:: criarEntidades()
{
    //criando entidades
    Entidades::Personagens::Jogador* j1 = new  Entidades::Personagens::Jogador ();
    Entidades::Personagens::Inimigo* i1 = new  Entidades::Personagens::Inimigo ();
    Entidades::Obstaculos::Obstaculo* chao = new Entidades::Obstaculos::Obstaculo();
    Entidades::Obstaculos::Obstaculo* sky = new Entidades::Obstaculos::Obstaculo();
    

    //criando texturas
    const char* jog1 = "assets/jogador.png";
    const char* ini1 = "assets/inimigo.png";
    const char* ch = "assets/ground.jpeg";
    const char* sky1 = "assets/nskybox.jpg";

    pGrafico->createTexture(sky1);
    pGrafico->createTexture(jog1);
    pGrafico->createTexture(ini1);
    pGrafico->createTexture(ch);
    pGrafico->loadTextures();

    sky->setTextura(pGrafico->textureMap.at(sky1));
    j1->setTextura(pGrafico->textureMap.at(jog1));
    i1->setTextura(pGrafico->textureMap.at(ini1));
    chao->setTextura(pGrafico->textureMap.at(ch));

    //criando obstaculos 
    sky->setTamanho(sf::Vector2f(WIDTH, HEIGHT));
    sky->setPosicao(sf::Vector2f(0,0));
    chao->setTamanho(sf::Vector2f(WIDTH, 20));//altura do chao = 20
    chao->setPosicao(sf::Vector2f(0, 700));//posicao chao*/   

    //setando inimigo
    i1->setJog1(j1);
    
    //listando entidades
    Entidades::Entidade *e0 = static_cast<Entidades::Entidade*>(sky);
    Entidades::Entidade *e1 = static_cast<Entidades::Entidade*>(j1);
    Entidades::Entidade *e2 = static_cast<Entidades::Entidade*>(i1);
    Entidades::Entidade *e3 = static_cast<Entidades::Entidade*>(chao);

    lista.addEntidade(e0);
    lista.addEntidade(e1);
    lista.addEntidade(e2);
    lista.addEntidade(e3);

    listaMoveis.addEntidade(e1);
    listaMoveis.addEntidade(e2);
    listaFixos.addEntidade(e3);

}

