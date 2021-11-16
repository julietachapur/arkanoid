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

PlayScene::PlayScene(int highScore)
{
    _highScore=highScore;
    init();
}

void PlayScene::init(){//inicializacion
    vidas=3;
    player = new Player(sf::Vector2f(210,390));
    BaseScene::add(player);
    ball = new Ball();
    BaseScene::add(ball);


    n=0;
    for(int i=1;i<=5;i++){
        for(int j=0;j<=5;j++){
            enemy[n]=new Enemy(i,j,1);
            BaseScene::add(enemy[n]);
            n++;
        }
    }

    limit= new LimiteGameOver();
    BaseScene::add(limit);

    texBackground.loadFromFile("assets/images/level_1.png");
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
    txt.setPosition(30,420);
    txt.setScale(0.5,0.5);

    ///Musica
    /*music.openFromFile("assets/music/level_1.ogg");
    music.setLoop(true);
    music.setVolume(5.f);
    music.play();*/


}
void PlayScene::aumentarScore()
{
    score +=1;
    txt.setString("Score "+ to_string(score));
}
void PlayScene::scoreCero()
{
    score=0;
    txt.setString("Score "+ to_string(score));
}


void PlayScene::disminuirScore()
{
    if(score>0){
        score --;
        txt.setString("Score "+ to_string(score));
    }
}

void PlayScene::update(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
        if(pause == true){
            pause = false;
            music.play();
        }
        else{pause = true; music.stop();}
        }
    if(!pause) BaseScene::update();
    colisiones_ball();
    colisiones_enemy();
    if(vidas==0){
        music.stop();
<<<<<<< HEAD
        //GlobalScore::setLastScore(score);
        Game::getInstance().switchScene(new EndGame(score,_highScore));
    }
    if(contadorEnemigos==30){
        music.stop();
        Game::getInstance().switchScene(new MenuNextLevel(score,_highScore));
=======
    sc.setLastScore(score);
    sc.grabarEnDisco();
       Game::getInstance().switchScene(new EndGame());
    }
    if(contadorEnemigos==30){
        music.stop();
        Game::getInstance().switchScene(new MenuNextLevel(score, vidas));
>>>>>>> d9849e24ce24f97f2c5aa6c548bb178c90619b18
    }
    vida.setString("vidas " + to_string(vidas));
}

void PlayScene::draw(sf::RenderWindow &w)
{
    w.draw(spBackground);
    BaseScene::draw(w);
    w.draw(vida);
    w.draw(txt);
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
<<<<<<< HEAD
            disminuirScore();
=======
            if(vidas>1){
            scoreCero();
            }
>>>>>>> d9849e24ce24f97f2c5aa6c548bb178c90619b18
            ball->reset();
        }
    }
}

void PlayScene::colisiones_limit(){
if(limit->isCollision(*ball)){
    w.close();
}
}

void PlayScene::colisiones_enemy(){

   for(int i=0;i<n;i++){
        if(enemy[i]->isCollision(*ball)){
        enemy[i]->disapear();
        contadorEnemigos++;
        ball->dirChangeE();
        aumentarScore();
    }
   }


}
