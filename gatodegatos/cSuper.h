#include "cGato.h"

class Super
{
  private:
    vector<Gato*> vgato;
    char p1, p2;
    int pos;
    bool end;
  public:
    Super();
    string display();
    void start();
};