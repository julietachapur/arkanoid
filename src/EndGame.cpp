#include "EndGame.h"
#include <iostream>
#include "Game.h"
#include "PlayScene.h"

<<<<<<< HEAD
EndGame::EndGame(int score, int highScore){
    _highScore = highScore;
    _score = score;
=======
int EndGame::mayor(){
int aux=0;
int pos=0;
while(sc.leerDeDisco(pos)){
    if(sc.getLastScore()>aux){
        aux=sc.getLastScore();
    }
    pos++;
}
return aux;
}
EndGame::EndGame(){

    _highScore=mayor();
>>>>>>> d9849e24ce24f97f2c5aa6c548bb178c90619b18
    // LOAD BACKGROUND IMAGE
    texBackground.loadFromFile("assets/images/gameover.png");
    spBackground.setTexture(texBackground);
    spBackground.setScale(0.5, 0.5);

    // LOAD ASTRONAUT
    texAstronaut.loadFromFile("assets/images/astro.png");
    spAstronaut.setTexture(texAstronaut);
    spAstronaut.setPosition(20,50);
    spAstronaut.setScale(0.2, 0.2);
    // LOAD FONT
    if(!textFont.loadFromFile("assets/fonts/menu-font.ttf")){
        cout << "Error loading font" << endl;
    };

    // GAME OVER TITLE
    titleText.setFont(textFont);
    titleText.setColor(sf::Color::Blue);
    titleText.setString("Game Over");
    titleText.setCharacterSize(48);
    titleText.setPosition(sf::Vector2f((400-titleText.getGlobalBounds().width)/2.0, 50));

    //SCORE
    txt.setFont(textFont);
    txt.setString("Score: "+ to_string(score));
    txt.setFillColor(sf::Color::Blue);
    txt.setCharacterSize(35);
    txt.setPosition(sf::Vector2f((400-txt.getGlobalBounds().width)/2.0, 425));

    if(_score > _highScore){
        _highScore = _score;
        texHighScore.loadFromFile("assets/images/highscore.png");
        spHighScore.setTexture(texHighScore);
        spHighScore.setPosition(115,300);
        spHighScore.setScale(0.35, 0.35);
    }

    // BACK TO MENU
    exit.setFont(textFont);
    exit.setColor(sf::Color::Yellow);
    exit.setString("[ESC] - Exit");
    exit.setCharacterSize(10);
    exit.setPosition(250, 480);


    //HighScore
    high.setFont(textFont);
    high.setColor(sf::Color::Magenta);
    high.setString("Highscore");
    high.setCharacterSize(29);
    high.setPosition(sf::Vector2f((400-high.getGlobalBounds().width)/2.0, 230));

    //highScore Value

    highValue.setFont(textFont);
    highValue.setColor(sf::Color::Magenta);
    highValue.setString(to_string(_highScore));
    highValue.setCharacterSize(29);
    highValue.setPosition(sf::Vector2f((400-high.getGlobalBounds().width)/2.0, 280));

    //MUSIC
    music.openFromFile("assets/music/menu.ogg");
    music.setLoop(true);
    music.play();
}

void EndGame::update(){

    // Replay button
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)){
<<<<<<< HEAD
        Game::getInstance().switchScene(new PlayScene(_highScore));
=======
        music.stop();
        Game::getInstance().switchScene(new PlayScene());
>>>>>>> d9849e24ce24f97f2c5aa6c548bb178c90619b18
    }
}

void EndGame::draw(sf::RenderWindow &w){
    w.draw(spBackground);
    w.draw(spAstronaut);
    w.draw(high);
    w.draw(highValue);
    w.draw(titleText);
    w.draw(spHighScore);
    w.draw(txt);
    w.draw(exit);
}
