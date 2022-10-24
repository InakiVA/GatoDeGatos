#include "cTile.h"

class Gato
{
  private:
    vector<Tile*> gato;
    char p1, p2;
    string winner;
    int pos;
  public:
    Gato();
    void setP1(char _c);
    void setP2(char _c);
    int getPos();
    string getWinner();
    vector<Tile*> getTiles();
    string display();
    void turn(int turn); //checa winner    
};