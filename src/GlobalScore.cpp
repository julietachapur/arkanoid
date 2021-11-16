#include <iostream>
using namespace std;


#include "GlobalScore.h"

GlobalScore::GlobalScore()
{
}

void GlobalScore::setCero(){
    highScore = 0;
    lastScore = 0;
    cout<<highScore;
    cout<<lastScore;
}

int GlobalScore::getHighScore(){
return highScore;
}

int GlobalScore::getLastScore(){
return lastScore;
}

void GlobalScore::setHighScore(int n){
highScore=n;
}

void GlobalScore::setLastScore(int n){
lastScore=n;
}
