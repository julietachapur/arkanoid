#ifndef PLAY_SCENE_H
#define PLAY_SCENE_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Collisionable.h"
#include "Object.h"
#include "Player.h"
#include "MenuNextLevel.h"
#include "Ball.h"
#include "BaseScene.h"
#include "PlayScene2.h"
#include "Enemy.h"
#include "LimiteGameOver.h"
#include "EndGame.h"
#include "GlobalScore.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class PlayScene: public BaseScene{
    private:
        sf::RenderWindow w; //sfml
        sf::Texture texBackground;//fondo
        sf::Sprite spBackground;
        sf::Music music;
        int vidas = 3;
        int score = 0;
        int highScore;
        sf::Text txt;
        sf::Text vida;
        sf::Font font;
        Player *player;
        Ball *ball;
        Enemy *enemy[1000];
        LimiteGameOver *limit;

        GlobalScore sc;

        int n=0;
        int contadorEnemigos=0;
<<<<<<< HEAD
        int _highScore;
=======



    public:
>>>>>>> d9849e24ce24f97f2c5aa6c548bb178c90619b18
        void init();
        void colisiones_ball();
        void colisiones_enemy();
        void colisiones_limit();
        void aumentarScore();
<<<<<<< HEAD
        void disminuirScore();

    public:
        PlayScene(int highScore);
=======
        void scoreCero();
        PlayScene();
>>>>>>> d9849e24ce24f97f2c5aa6c548bb178c90619b18
        bool pause = false;

        void update();
        void draw(sf::RenderWindow &w);

};
#endif // PLAY_SCENE_H
