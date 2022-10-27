#pragma once
#include "../Fisica/CoordTL.h"
#include <SFML/Graphics.hpp>
#include <map>

namespace Gerenciadores {

    class Graficos{
    private:
        sf::RenderWindow* window;
        sf::Event event;
        sf::View view;
        sf::Clock clock;
        static float dt;
        

        //Singleton
        static Gerenciadores::Graficos* instance; 

        Graficos();
    public:
        ~Graficos();
        
        static Graficos* getInstance();

        std::map<const char*, sf::Texture*> textureMap;

        void render(sf::RectangleShape* shape);

        void render(sf::Sprite* sprite);

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