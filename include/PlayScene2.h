#ifndef PLAYSCENE2_H
#define PLAYSCENE2_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Collisionable.h"
#include "Object.h"
#include "Player.h"
#include "Ball.h"
#include "BaseScene.h"
#include "Enemy.h"
#include "LimiteGameOver.h"
#include "EndGame.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class PlayScene2: public BaseScene{
    private:
        sf::RenderWindow w; //sfml
        sf::Texture texBackground;//fondo
        sf::Sprite spBackground;
        sf::Music music;

        int _vidas;
        int _score=0;
        int _highScore;
        int score;
        sf::Text txt;
        sf::Text vida;
        sf::Font font;
        Player *player;
        Ball *ball;
        Enemy *enemy[1000];
        LimiteGameOver *limit;


        int n=0;
        int contadorEnemigos;

        void init();
        void colisiones_ball();
        void colisiones_enemy();
        void colisiones_limit();
        void aumentarScore();

        void disminuirScore();

    public:
        PlayScene2(int score, int highScore, int vidas);
        bool pause = false;

        void update();
        void draw(sf::RenderWindow &w);

};

#endif // PLAYSCENE2_H
