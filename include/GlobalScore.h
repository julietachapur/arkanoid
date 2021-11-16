#ifndef GLOBALSCORE_H
#define GLOBALSCORE_H


class GlobalScore
{
    public:
       GlobalScore();
       void setHighScore(int n);
       void setLastScore(int n);

       void setCero();

       int getHighScore();
       int getLastScore();

       bool grabarEnDisco();
       bool leerDeDisco(int);

    private:
        int highScore=0;
        int lastScore=0;
};

#endif // GLOBALSCORE_H
