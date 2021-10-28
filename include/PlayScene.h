#ifndef PLAY_SCENE_H
#define PLAY_SCENE_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Collisionable.h"
#include "Object.h"
#include "Player.h"
#include "Ball.h"
#include "BaseScene.h"
#include "Enemy.h"
#include "LimiteGameOver.h"
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
        //sf::Music music;
        /*Enemy *enemy;
        Enemy *enemy_2;
        Enemy *enemy_3;*/
        int vidas;

        sf::Text vida;
        sf::Font font;
        Player *player;
        Ball *ball;
        Enemy *enemy;
        LimiteGameOver *limit;

        void init();
        void colisiones_ball();
        void colisiones_enemy();
        void colisiones_limit();

    public:


        PlayScene();
        bool pause = false;

        void update();
        void draw(sf::RenderWindow &w);

};
#endif // PLAY_SCENE_H
