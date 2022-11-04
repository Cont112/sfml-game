#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>

namespace Gerenciadores {

    class Gerenciador_Grafico{
    private:
        sf::RenderWindow* window;
        sf::Event event;
        sf::View view;
        sf::Clock clock;
        static float dt;
        
        //Singleton
        static Gerenciadores::Gerenciador_Grafico* instance; 

        Gerenciador_Grafico();
    public:
        ~Gerenciador_Grafico();
        
        static Gerenciador_Grafico* getInstance();

        std::map<const char*, sf::Texture*> textureMap;

        void render(sf::RectangleShape shape);

        void display();

        void clear();

        bool isWindowOpen() const;

        void closeWindow();

        sf::RenderWindow* getWindow() const;

        void handleEvent();

        void updateDeltaTime();

        void loadTextures();

        void createTexture(const char* path);

    };
}