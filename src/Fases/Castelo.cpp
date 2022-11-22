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

}

void Fases::Castelo::criarFundo()
{
    sf::Texture *texturaFundo = new sf::Texture();
    texturaFundo->loadFromFile("assets/skybox.jpg");
    fundo.setSize(sf::Vector2f(1366, 768));
    fundo.setTexture(texturaFundo);
    pGrafico->render(fundo);


}