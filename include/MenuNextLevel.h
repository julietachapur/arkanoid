#ifndef MENUNEXTLEVEL_H
#define MENUNEXTLEVEL_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include "./Ball.h"
#include "./BaseScene.h"


using namespace std;

class MenuNextLevel: public BaseScene{
    private:
        int _score;
<<<<<<< HEAD
        int _highScore;
=======
        int _vidas;
>>>>>>> d9849e24ce24f97f2c5aa6c548bb178c90619b18
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
        sf::Text txt;
        sf::Text exitText;
        sf::Music music;

    public:
<<<<<<< HEAD
        MenuNextLevel(int score,int highScore);
=======
        MenuNextLevel(int score,int vidas);
>>>>>>> d9849e24ce24f97f2c5aa6c548bb178c90619b18
        void update();
        void draw(sf::RenderWindow &w);
};

#endif // MENUNEXTLEVEL_H
