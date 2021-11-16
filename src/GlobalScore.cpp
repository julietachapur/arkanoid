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

bool GlobalScore::grabarEnDisco(){
    FILE *p;
    p=fopen("score.dat","ab");
    if(p==NULL){
        return -1;
    }

    bool x=fwrite(this, sizeof(GlobalScore),1,p);
    fclose(p);
    return x;
}

bool GlobalScore::leerDeDisco(int pos){
    FILE *p;
    p=fopen("score.dat","rb");
    if(p==NULL){
        return -1;
    }

    fseek(p,sizeof(GlobalScore)*pos,0);
    bool x=fread(this,sizeof(GlobalScore),1,p);
    fclose(p);
    return x;
}
