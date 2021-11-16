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
#include "GlobalScore.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class PlayScene2: public BaseScene, public GlobalScore{
    private:
        sf::RenderWindow w; //sfml
        sf::Texture texBackground;//fondo
        sf::Sprite spBackground;
        sf::Music music;
<<<<<<< HEAD
        int vidas = 3;
=======
        /*Enemy *enemy;
        Enemy *enemy_2;
        Enemy *enemy_3;*/

        int _vidas = 3;
>>>>>>> d9849e24ce24f97f2c5aa6c548bb178c90619b18
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
        GlobalScore sc;


        int n=0;
        int contadorEnemigos;

<<<<<<< HEAD
        void init();
=======
        void init(int score, int vidas);
>>>>>>> d9849e24ce24f97f2c5aa6c548bb178c90619b18
        void colisiones_ball();
        void colisiones_enemy();
        void colisiones_limit();
        void aumentarScore();
<<<<<<< HEAD
        void disminuirScore();
=======
        void scoreCero();
>>>>>>> d9849e24ce24f97f2c5aa6c548bb178c90619b18

    public:


<<<<<<< HEAD
        PlayScene2(int score, int highScore);
=======
        PlayScene2(int score, int vidas);
>>>>>>> d9849e24ce24f97f2c5aa6c548bb178c90619b18
        bool pause = false;

        void update();
        void draw(sf::RenderWindow &w);

};

#endif // PLAYSCENE2_H
