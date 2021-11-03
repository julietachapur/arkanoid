#include "../include/PlayScene.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <iostream>
#include "../include/Ball.h"
#include "../include/Player.h"
#include"../include/Enemy.h"
#include"../include/LimiteGameOver.h"
using namespace std;

PlayScene::PlayScene()
{
    init();
}

void PlayScene::init(){//inicializacion
    vidas=3;
    player = new Player(sf::Vector2f(210,390));
    BaseScene::add(player);
    ball = new Ball();
    BaseScene::add(ball);
    enemy = new Enemy();
    BaseScene::add(enemy);
    limit= new LimiteGameOver();
    BaseScene::add(limit);

    texBackground.loadFromFile("assets/images/bckground.png");
    spBackground.setTexture(texBackground);

    font.loadFromFile("assets/fonts/font.ttf");

    ///Texto para vidas

    vida.setFont(font);
    vida.setString("Vidas "+ to_string(vidas));
    vida.setFillColor(sf::Color::White);
    vida.setPosition(330,420);
    vida.setScale(0.5,0.5);

    ///Texto para score

    txt.setFont(font);
    txt.setString("Score "+ to_string(score));
    txt.setFillColor(sf::Color::White);
    txt.setPosition(330,420);
    txt.setScale(0.5,0.5);
}
void PlayScene::aumentarScore()
{
    score +=1;
    txt.setString("Score "+ to_string(score));
}

void PlayScene::update(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
        if(pause == true){
            pause = false;
        }
        else{pause = true;}
        }



    if(!pause) BaseScene::update();
    colisiones_ball();
    colisiones_enemy();
    if(vidas==0){
       Game::getInstance().switchScene(new EndGame());
    }
    aumentarScore();
    vida.setString("vidas " + to_string(vidas));
}

void PlayScene::draw(sf::RenderWindow &w)
{
    w.draw(spBackground);
    BaseScene::draw(w);
    w.draw(vida);
}

void PlayScene::colisiones_ball(){
   sf::Vector2f pos=ball->getVelocity();

    if(ball->isCollision(*player)){
        ball->moveBall(*player);
        ball->dirChange();
    }

    if(ball->isCollision(*limit)){
        if(ball->velBall.y>0){
            vidas--;
        }
    }
}

void PlayScene::colisiones_limit(){
if(limit->isCollision(*ball)){
    w.close();
}
}

void PlayScene::colisiones_enemy(){
    if(enemy->isCollision(*ball)){
        enemy->disapear();
        aumentarScore();
    }

}
