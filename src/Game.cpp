#include "Game.h"
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;

// PATRON SINGLETON
// oculta el constructor para que no se pueda crear mas de un obj de este tipo

Game *Game::instance = nullptr;
Game::Game(){}

Game &Game::create(const sf::VideoMode &videoMode, BaseScene *scene, const string &name){
    if(instance){
        cerr << "ERROR: cant call create(), game already running" << endl;
    } else {
        Game & g = getInstance();
        g.w.create(videoMode, name, sf::Style::Close);
        g.nextScene = nullptr;
        g.currentScene = scene;
        g.w.setFramerateLimit(60); //60 cuadros por segundos, a eso corre el programa
    }
    return getInstance();
}

Game &Game::getInstance(){
    if(!instance){
        instance = new Game();
    }
    return *instance;
}

void Game::run(){
    while(w.isOpen() && currentScene != nullptr){
        sf::Event e;
        while(w.pollEvent(e)){
            if(e.type == sf::Event::Closed)
                w.close();//trabaja con una cola de eventos

        }
        update();
        draw();
        if(nextScene != nullptr){
            delete currentScene;
            currentScene = nextScene;
            nextScene = nullptr;
        }
    }
}

void Game::update(){
    currentScene->update();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace)){//si se aprieta esc se cierra
        w.close();
    }

}

void Game::draw(){
    w.clear(sf::Color::Black);
    currentScene->draw(w);
    w.display();
}

void Game::switchScene(BaseScene *scene){
    nextScene = scene;
}
