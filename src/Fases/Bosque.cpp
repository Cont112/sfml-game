#include "../../include/Fases/Bosque.h"

Fases::Bosque::Bosque():Fase()
{

}

Fases::Bosque::~Bosque()
{

}

void Fases::Bosque::criarMapa()
{
    std::ifstream arquivo;
    std::string linha;

    int nLavas = (rand()%3)+3;
    int nCaixas = (rand()%9)+3;
    int nMagos = (rand()%4)+3;
    int nCaveiras = (rand()%4)+3;

    for (int i=0; i<nCaixas;i++)//criando caixas aleatorias 
    {
        criarEntidade('c', sf::Vector2f( (rand()%25)+2 ,0));
    }

    for (int i=0; i<nLavas;i++)//criando caixas aleatorias 
    {
        criarEntidade('l', sf::Vector2f( (rand()%25)+2 ,0));
    }


    //criando mapa 
    
    arquivo.open("src/Fases/Mapa_Fase.txt");
    try
    {
        if (!arquivo.is_open())
        {
            std::cout<<"erro ao abrir o arquivo da fase bosque"<<std::endl;
            throw 1;
        }

    }
    catch(const int erro)
    {
        std::cout<<"erro:"<<erro<<std::endl;
    }
    int j = 0;
    while(std::getline(arquivo, linha)){
        for(int i = 0; i < linha.size(); i++){
            if(linha[i] != ' '){
                criarEntidade(linha[i], sf::Vector2f(i, j));
            }
        }
        j++;
    }
    arquivo.close();

    /*for (int i=0; i<nMagos;i++)//criando magos aleatorios
    {
        criarEntidade('m', sf::Vector2f( (rand()%25)+5 ,0));
    } */   

    for (int i=0; i<nCaveiras;i++)//criando esqueleto aleatorios
    {
        criarEntidade('e', sf::Vector2f( (rand()%25)+5 ,0));
    }    

    

}

void Fases::Bosque::criarFundo()
{
    sf::Texture *texturaFundo = new sf::Texture();
    texturaFundo->loadFromFile("assets/skybox.jpg");
    fundo.setSize(sf::Vector2f(1366, 768));
    fundo.setTexture(texturaFundo);
    pGrafico->render(fundo);


}