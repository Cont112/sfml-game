#include "../../include/Fases/Castelo.h"

Fases::Castelo::Castelo():Fase()
{

}

Fases::Castelo::~Castelo()
{

}

void Fases::Castelo::criarMapa()
{
    std::ifstream arquivo;
    std::string linha;

    int nCaixas = (rand()%9)+3;
    int nMagos = (rand()%4)+3;
    int nCaveiras = (rand()%4)+3;

    for (int i=0; i<nCaixas;i++)//criando caixas aleatorias 
    {
        criarEntidade('c', sf::Vector2f( (rand()%25)+2 ,0));
    }


    arquivo.open("src/Fases/Mapa_Castelo.txt");
    if(!arquivo.is_open()){
        std::cout << "Não foi possivel abrir o arquivo da fase Castelo" << std::endl;
        exit(1);
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

    for (int i=0; i<nMagos;i++)//criando magos aleatorios
    {
        criarEntidade('m', sf::Vector2f( (rand()%25)+5 ,0));
    }    

    for (int i=0; i<nMagos;i++)//criando esqueleto aleatorios
    {
        criarEntidade('e', sf::Vector2f( (rand()%25)+5 ,0));
    }   

}

void Fases::Castelo::criarFundo()
{
    sf::Texture *texturaFundo = new sf::Texture();
    texturaFundo->loadFromFile("assets/skybox.jpg");
    fundo.setSize(sf::Vector2f(1366, 768));
    fundo.setTexture(texturaFundo);
    pGrafico->render(fundo);


}