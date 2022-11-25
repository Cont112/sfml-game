#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>

//FEITO COM BASE NOS VIDEOS DO MONITOR BURDA 2022/2 - TECPROG UTFPR
//https://www.youtube.com/watch?v=RFSOXXsm4Ug&list=PLSPev71NbUEBIQlT2QCd-gN6l_mNVw1cJ&index=5

namespace Gerenciadores {

    class Gerenciador_Grafico{
    private:
        sf::RenderWindow* window;
        sf::Clock clock;
        sf::Font* font;
        static float dt;
        
        //Singleton
        static Gerenciadores::Gerenciador_Grafico* instance; 

        Gerenciador_Grafico();
    public:
        ~Gerenciador_Grafico();
        
        static Gerenciador_Grafico* getInstance();

        std::map<const char*, sf::Texture*> textureMap;

        void render(sf::RectangleShape shape);

        void render(sf::Text text);

        void display();

        void clear();

        bool isWindowOpen() const;

        void closeWindow();

        sf::RenderWindow* getWindow() const;

        float getDt() const;

        void updateDeltaTime();

        void createTexture(const char* path);

        void deletarInstance();

        void executar();
    };
}