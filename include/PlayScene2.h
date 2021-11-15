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
        /*Enemy *enemy;
        Enemy *enemy_2;
        Enemy *enemy_3;*/

        int _vidas = 3;
        int _score=0;
        int s=0;
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

        void init(int score, int vidas);
        void colisiones_ball();
        void colisiones_enemy();
        void colisiones_limit();
        void aumentarScore();
        void scoreCero();

    public:


        PlayScene2(int score, int vidas);
        bool pause = false;

        void update();
        void draw(sf::RenderWindow &w);

};

#endif // PLAYSCENE2_H
