#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include "./Ball.h"
#include "./BaseScene.h"


using namespace std;

class Menu: public BaseScene{
    private:
        sf::Texture texBackground;//fondo
        sf::Sprite spBackground;
        sf::Texture texAstronaut;
        sf::Sprite spAstronaut;
        sf::Texture texSpace;
        sf::Sprite spSpace;
        sf::Font textFont;
        sf::Text titleText;
        sf::Text playText;
        sf::Text highScoreText;
        sf::Text highScoreValue;
        sf::Text exitText;
        sf::Music music;
        int _highScore;

    public:
        Menu(int highScore);
        void update();
        void draw(sf::RenderWindow &w);
};

#endif // MENU_H
