#include "EndGame.h"
#include <iostream>
#include "Game.h"
#include "Menu.h"
#include "Global.h"
#include "PlayScene.h"

EndGame::EndGame(){
    int high_score = Global::getHighScore();
    int last_score = Global::getLastScore();
    cout<<last_score;
    cout<<high_score;
    // LOAD BACKGROUND IMAGE
    texBackground.loadFromFile("assets/images/menu-background.jpg");
    spBackground.setTexture(texBackground);
    spBackground.setScale(0.5, 0.5);

    // LOAD FONT
    if(!textFont.loadFromFile("assets/fonts/menu-font.ttf")){
        cout << "Error loading font" << endl;
    };

    // GAME OVER TITLE
    titleText.setFont(textFont);
    titleText.setColor(sf::Color::White);
    titleText.setString("Game Over");
    titleText.setCharacterSize(48);
    titleText.setPosition(sf::Vector2f((400-titleText.getGlobalBounds().width)/2.0, 50));

    // SCORE
    scoreText.setFont(textFont);
    scoreText.setColor(sf::Color::White);
    scoreText.setString("Your score");
    scoreText.setCharacterSize(24);
    scoreText.setPosition(sf::Vector2f((400-scoreText.getGlobalBounds().width)/2.0, 200));

    // SCORE VALUE
    scoreValue.setFont(textFont);
    scoreValue.setColor(sf::Color::White);
    scoreValue.setString(to_string(last_score));
    scoreValue.setCharacterSize(32);
    scoreValue.setPosition(sf::Vector2f((400-scoreValue.getGlobalBounds().width)/2.0, 250));

    // NEW TEXT
    newText.setFont(textFont);
    newText.setColor(sf::Color::White);
    newText.setString("New");
    newText.setCharacterSize(32);
    newText.setPosition(sf::Vector2f((400-newText.getGlobalBounds().width)/2.0, 200));

    // HIGHSCORE TEXT
    newHighScore.setFont(textFont);
    newHighScore.setColor(sf::Color::White);
    newHighScore.setString("highscore!!");
    newHighScore.setCharacterSize(32);
    newHighScore.setPosition(sf::Vector2f((400-newHighScore.getGlobalBounds().width)/2.0, 230));

    // NEW HIGHSCORE VALUE
    newHighScoreValue.setFont(textFont);
    newHighScoreValue.setColor(sf::Color::White);
    newHighScoreValue.setString(to_string(high_score));
    newHighScoreValue.setCharacterSize(32);
    newHighScoreValue.setPosition(sf::Vector2f((400-newHighScoreValue.getGlobalBounds().width)/2.0, 280));

    // HIGHSCORE
    highScore.setFont(textFont);
    highScore.setColor(sf::Color::White);
    highScore.setString("Highscore");
    highScore.setCharacterSize(24);
    highScore.setPosition(sf::Vector2f((400-highScore.getGlobalBounds().width)/2.0, 330));

    // HIGHSCORE VALUE
    highScoreValue.setFont(textFont);
    highScoreValue.setColor(sf::Color::White);
    highScoreValue.setString(to_string(last_score));
    highScoreValue.setCharacterSize(24);
    highScoreValue.setPosition(sf::Vector2f((400-highScoreValue.getGlobalBounds().width)/2.0, 370));

    // BACK TO MENU
    backMenu.setFont(textFont);
    backMenu.setColor(sf::Color::Yellow);
    backMenu.setString("[m] - Menu");
    backMenu.setCharacterSize(10);
    backMenu.setPosition(10, 460);

    // PLAY AGAIN
    replay.setFont(textFont);
    replay.setColor(sf::Color::Yellow);
    replay.setString("[TAB] - Play again");
    replay.setCharacterSize(10);
    replay.setPosition(10, 480);

    // BACK TO MENU
    exit.setFont(textFont);
    exit.setColor(sf::Color::Yellow);
    exit.setString("[backspace] - Exit");
    exit.setCharacterSize(10);
    exit.setPosition(250, 480);

    //musica
//    music.openFromFile("assets/music/music.ogg");
//	music.setLoop(true);
//	music.play();
}

void EndGame::update(){
    // Back to menu
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)){
        Game::getInstance().switchScene(new Menu());
    }

    // Replay button
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)){
        Game::getInstance().switchScene(new PlayScene());
    }
}

void EndGame::draw(sf::RenderWindow &w){
    w.draw(spBackground);
    w.draw(titleText);
    if (Global::getLastScore() > Global::getHighScore()) {
        w.draw(newText);
        w.draw(newHighScore);
        w.draw(newHighScoreValue);
    } else {
        w.draw(scoreText);
        w.draw(scoreValue);
        w.draw(highScore);
        w.draw(highScoreValue);
    }
    w.draw(replay);
    w.draw(backMenu);
    w.draw(exit);
}
